#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <set>
#include <chrono>
#include <ctime>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

#ifdef _WIN32
    #define CLEAR "cls"
    #define EXE_EXT ".exe"
#else
    #define CLEAR "clear"
    #define EXE_EXT ""
#endif

// Color codes – all defined
const string RESET   = "\033[0m";
const string RED     = "\033[31m";
const string GREEN   = "\033[32m";
const string YELLOW  = "\033[33m";
const string BLUE    = "\033[34m";
const string CYAN    = "\033[36m";
const string WHITE   = "\033[37m";
const string BOLD    = "\033[1m";
const string BG_RED  = "\033[41m";
const string BG_GREEN = "\033[42m";

void clearScreen() { system(CLEAR); }
string trim(const string& s) {
    size_t l = s.find_first_not_of(" \t\n\r");
    if (l == string::npos) return "";
    size_t r = s.find_last_not_of(" \t\n\r");
    return s.substr(l, r-l+1);
}
string currentTimestamp() {
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", localtime(&t));
    return string(buf);
}

//   AVL TREE
struct AVLNode {
    int id;
    string title, description, difficulty, inputFormat, outputFormat, constraints;
    vector<pair<string,string>> testCases;
    int solveCount;
    AVLNode *left, *right;
    int height;
    AVLNode(int i, string t, string d, string df, string inF, string outF, string cons,
            vector<pair<string,string>> tc)
        : id(i), title(t), description(d), difficulty(df), inputFormat(inF),
          outputFormat(outF), constraints(cons), testCases(tc), solveCount(0),
          left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
    AVLNode* root;
    int height(AVLNode* n) { return n ? n->height : 0; }
    int balance(AVLNode* n) { return n ? height(n->left) - height(n->right) : 0; }
    void updateHeight(AVLNode* n) { if(n) n->height = 1 + max(height(n->left), height(n->right)); }
    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;
        x->right = y;
        y->left = T2;
        updateHeight(y);
        updateHeight(x);
        return x;
    }
    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;
        y->left = x;
        x->right = T2;
        updateHeight(x);
        updateHeight(y);
        return y;
    }
    AVLNode* insertNode(AVLNode* n, int id, const string& t, const string& d, const string& df,
                        const string& inF, const string& outF, const string& cons,
                        const vector<pair<string,string>>& tc) {
        if(!n) return new AVLNode(id, t, d, df, inF, outF, cons, tc);
        if(id < n->id) n->left = insertNode(n->left, id, t, d, df, inF, outF, cons, tc);
        else if(id > n->id) n->right = insertNode(n->right, id, t, d, df, inF, outF, cons, tc);
        else return n;
        updateHeight(n);
        int b = balance(n);
        if(b > 1 && id < n->left->id) return rotateRight(n);
        if(b < -1 && id > n->right->id) return rotateLeft(n);
        if(b > 1 && id > n->left->id) { n->left = rotateLeft(n->left); return rotateRight(n); }
        if(b < -1 && id < n->right->id) { n->right = rotateRight(n->right); return rotateLeft(n); }
        return n;
    }
    AVLNode* searchNode(AVLNode* n, int id) {
        if(!n || n->id == id) return n;
        return id < n->id ? searchNode(n->left, id) : searchNode(n->right, id);
    }
    void inorderCollect(AVLNode* n, vector<AVLNode*>& out) {
        if(!n) return;
        inorderCollect(n->left, out);
        out.push_back(n);
        inorderCollect(n->right, out);
    }
    void resetCounts(AVLNode* n) {
        if(!n) return;
        n->solveCount = 0;
        resetCounts(n->left);
        resetCounts(n->right);
    }
public:
    AVLTree() : root(nullptr) {}
    void insert(int id, const string& t, const string& d, const string& df,
                const string& inF, const string& outF, const string& cons,
                const vector<pair<string,string>>& tc) {
        root = insertNode(root, id, t, d, df, inF, outF, cons, tc);
    }
    AVLNode* search(int id) { return searchNode(root, id); }
    vector<AVLNode*> getAll() { vector<AVLNode*> r; inorderCollect(root, r); return r; }
    void resetSolveCounts() { resetCounts(root); }
};

//  TRIE 
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<int> ids;
};
class Trie {
    TrieNode* root;
    void collect(TrieNode* n, vector<int>& res, set<int>& seen) {
        if(!n) return;
        for(int id : n->ids) if(!seen.count(id)) { res.push_back(id); seen.insert(id); }
        for(auto& p : n->children) collect(p.second, res, seen);
    }
public:
    Trie() { root = new TrieNode(); }
    ~Trie() { }
    void insert(const string& word, int id) {
        TrieNode* cur = root;
        for(char c : word) {
            if(!cur->children[c]) cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->ids.push_back(id);
    }
    vector<int> searchPrefix(const string& prefix) {
        TrieNode* cur = root;
        for(char c : prefix) {
            if(!cur->children[c]) return {};
            cur = cur->children[c];
        }
        vector<int> res; set<int> seen;
        collect(cur, res, seen);
        return res;
    }
};

//USER MODULE (persistent)
struct User {
    string username, password;
    int score;
    vector<int> solvedProblems;
    User() : score(0) {}
    User(string u, string p) : username(u), password(p), score(0) {}
};

class UserModule {
    unordered_map<string, User> users;
    const string filename = "users.txt";

    void save() {
        ofstream fout(filename);
        if(!fout) return;
        for(auto& [name, u] : users) {
            fout << u.username << "|" << u.password << "|" << u.score;
            for(int pid : u.solvedProblems) fout << "|" << pid;
            fout << "\n";
        }
        fout.close();
    }

    void load() {
        ifstream fin(filename);
        if(!fin) return;
        users.clear();
        string line;
        while(getline(fin, line)) {
            if(line.empty()) continue;
            stringstream ss(line);
            string token;
            vector<string> parts;
            while(getline(ss, token, '|')) parts.push_back(token);
            if(parts.size() < 3) continue;
            User u;
            u.username = parts[0];
            u.password = parts[1];
            u.score = stoi(parts[2]);
            for(size_t i=3; i<parts.size(); i++)
                u.solvedProblems.push_back(stoi(parts[i]));
            users[u.username] = u;
        }
        fin.close();
    }

public:
    UserModule() { load(); }
    ~UserModule() { save(); }

    bool registerUser(const string& u, const string& p) {
        if(users.count(u)) return false;
        users[u] = User(u,p);
        save();
        return true;
    }
    bool login(const string& u, const string& p) {
        return users.count(u) && users[u].password == p;
    }
    User* getUser(const string& u) {
        auto it = users.find(u);
        return (it != users.end()) ? &it->second : nullptr;
    }
    void addScore(const string& u, int pts) {
        if(users.count(u)) { users[u].score += pts; save(); }
    }
    void addSolved(const string& u, int pid) {
        if(users.count(u)) {
            auto& v = users[u].solvedProblems;
            if(find(v.begin(), v.end(), pid) == v.end()) {
                v.push_back(pid);
                save();
            }
        }
    }
    unordered_map<string, User>& all() { return users; }
    void recomputeProblemCounts(AVLTree& problems) {
        problems.resetSolveCounts();
        for(auto& [name, u] : users) {
            for(int pid : u.solvedProblems) {
                AVLNode* p = problems.search(pid);
                if(p) p->solveCount++;
            }
        }
    }
};

// ========================== SUBMISSION (Linked List + persistence) ==========================
struct Submission {
    string username, code, verdict;
    int problemId;
    double execTime;
    string timestamp;   // stored as string for persistence
    Submission* next;
    Submission(string u, int pid, string c, string v, double et=0, string ts="")
        : username(u), problemId(pid), code(c), verdict(v), execTime(et), next(nullptr) {
        timestamp = ts.empty() ? currentTimestamp() : ts;
    }
};

class SubmissionHistory {
    Submission* head;
    queue<Submission*> pending;
    const string historyFile = "submissions.txt";

    void appendToFile(Submission* s) {
        ofstream fout(historyFile, ios::app);
        if(!fout) return;
        // Format: username|problemId|verdict|execTime|timestamp
        fout << s->username << "|" << s->problemId << "|" << s->verdict
             << "|" << s->execTime << "|" << s->timestamp << "\n";
        fout.close();
    }

    void loadFromFile() {
        ifstream fin(historyFile);
        if(!fin) return;
        vector<Submission*> loaded;
        string line;
        while(getline(fin, line)) {
            if(line.empty()) continue;
            stringstream ss(line);
            string token;
            vector<string> parts;
            while(getline(ss, token, '|')) parts.push_back(token);
            if(parts.size() < 5) continue;
            string username = parts[0];
            int pid = stoi(parts[1]);
            string verdict = parts[2];
            double execTime = stod(parts[3]);
            string timestamp = parts[4];
            Submission* s = new Submission(username, pid, "", verdict, execTime, timestamp);
            loaded.push_back(s);
        }
        fin.close();
        // Add to linked list in reverse order so that most recent becomes head
        for(auto it = loaded.rbegin(); it != loaded.rend(); ++it) {
            Submission* s = *it;
            s->next = head;
            head = s;
        }
    }

public:
    SubmissionHistory() : head(nullptr) {
        loadFromFile();
    }
    ~SubmissionHistory() {
        while(head) {
            Submission* t = head;
            head = head->next;
            delete t;
        }
    }
    void add(Submission* s) {
        // Add to linked list (head = most recent)
        s->next = head;
        head = s;
        // Add to processing queue (for scoring)
        pending.push(s);
        // Persist to file
        appendToFile(s);
    }
    Submission* popPending() {
        if(pending.empty()) return nullptr;
        Submission* s = pending.front(); pending.pop();
        return s;
    }
    bool hasPending() { return !pending.empty(); }
    vector<Submission*> getUser(const string& u) {
        vector<Submission*> res;
        Submission* cur = head;
        while(cur) {
            if(cur->username == u) res.push_back(cur);
            cur = cur->next;
        }
        return res;
    }
};

// ========================== JUDGE MODULE ==========================
class JudgeModule {
    bool checkBrackets(const string& code) {
        stack<char> st;
        for(char c : code) {
            if(c=='(' || c=='{' || c=='[') st.push(c);
            else if(c==')' || c=='}' || c==']') {
                if(st.empty()) return false;
                char t = st.top(); st.pop();
                if((c==')' && t!='(') || (c=='}' && t!='{') || (c==']' && t!='[')) return false;
            }
        }
        return st.empty();
    }
    bool compile(const string& code, string& err) {
        ofstream f("temp_sol.cpp");
        if(!f) return false;
        f << code;
        f.close();
        string compileCmd = "g++ -std=c++17 -O2 temp_sol.cpp -o temp_sol" EXE_EXT " 2> compile_err.txt";
        int ret = system(compileCmd.c_str());
        if(ret != 0) {
            ifstream e("compile_err.txt");
            string line;
            while(getline(e, line)) err += line + "\n";
            return false;
        }
        return true;
    }
    string run(const string& input, double& execTime) {
        ofstream fin("temp_in.txt");
        fin << input; fin.close();
        auto start = chrono::high_resolution_clock::now();
#ifdef _WIN32
        system("temp_sol.exe < temp_in.txt > temp_out.txt 2> run_err.txt");
#else
        system("./temp_sol < temp_in.txt > temp_out.txt 2> run_err.txt");
#endif
        auto end = chrono::high_resolution_clock::now();
        execTime = chrono::duration<double>(end-start).count() * 1000.0;
        ifstream fout("temp_out.txt");
        string out, line;
        while(getline(fout, line)) out += line + "\n";
        return trim(out);
    }
public:
    Submission* judge(const string& user, int pid, const string& code,
                      const vector<pair<string,string>>& tests) {
        if(!checkBrackets(code))
            return new Submission(user, pid, code, "CE: Unmatched brackets");
        string compileErr;
        if(!compile(code, compileErr))
            return new Submission(user, pid, code, "CE: " + compileErr);
        int testNum=0;
        for(auto& tc : tests) {
            testNum++;
            double t=0;
            string out = run(tc.first, t);
            if(t > 2000.0)
                return new Submission(user, pid, code, "TLE on test " + to_string(testNum), t);
            if(out != trim(tc.second))
                return new Submission(user, pid, code, "WA on test " + to_string(testNum) +
                                      "\n  Expected: " + tc.second + "\n  Got: " + out, t);
        }
        return new Submission(user, pid, code, "AC", 0);
    }
};

// ========================== LEADERBOARD ==========================
class Leaderboard {
    priority_queue<pair<int,string>> heap;
public:
    void rebuild(const unordered_map<string,User>& users) {
        heap = priority_queue<pair<int,string>>();
        for(auto& p : users) heap.push({p.second.score, p.first});
    }
    vector<pair<string,int>> top(int n=10) {
        auto tmp = heap;
        vector<pair<string,int>> res;
        for(int i=0; i<n && !tmp.empty(); i++) {
            res.push_back({tmp.top().second, tmp.top().first});
            tmp.pop();
        }
        return res;
    }
};

// ========================== GRAPH ==========================
class ProblemGraph {
    unordered_map<int, vector<int>> adj;
public:
    void addEdge(int u, int v) { adj[u].push_back(v); }
    vector<int> bfsPath(int start, int target) {
        queue<int> q;
        unordered_map<int,int> parent;
        set<int> vis;
        q.push(start);
        vis.insert(start);
        parent[start] = -1;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            if(u == target) {
                vector<int> path;
                for(int x=target; x!=-1; x=parent[x]) path.push_back(x);
                reverse(path.begin(), path.end());
                return path;
            }
            for(int v : adj[u]) {
                if(!vis.count(v)) {
                    vis.insert(v);
                    parent[v] = u;
                    q.push(v);
                }
            }
        }
        return {};
    }
    vector<int> deps(int id) { return adj.count(id) ? adj[id] : vector<int>(); }
};

// ========================== RECOMMENDATION ENGINE ==========================
class RecommendationEngine {
    ProblemGraph* graph;
public:
    RecommendationEngine(ProblemGraph* g) : graph(g) {}
    vector<int> recommend(int pid, const vector<int>& solved) {
        set<int> solvedSet(solved.begin(), solved.end());
        vector<int> recs;
        for(int d : graph->deps(pid))
            if(!solvedSet.count(d)) recs.push_back(d);
        if(recs.empty()) {
            for(int d : graph->deps(pid))
                for(int nd : graph->deps(d))
                    if(!solvedSet.count(nd)) recs.push_back(nd);
        }
        return recs;
    }
    vector<int> path(int start, int target) { return graph->bfsPath(start, target); }
};

// ========================== MAIN SYSTEM ==========================
class OnlineJudgeSystem {
    UserModule users;
    AVLTree problems;
    JudgeModule judge;
    SubmissionHistory history;
    Leaderboard leaderboard;
    ProblemGraph graph;
    RecommendationEngine* recommender;
    Trie searchIndex;
    unordered_map<int,string> titles;
    string currentUser;
    bool loggedIn;

    string diffColor(const string& d) {
        if(d=="Easy") return GREEN;
        if(d=="Medium") return YELLOW;
        return RED;
    }

    void loadProblems() {
        // Problem 1: Two Sum
        problems.insert(1, "Two Sum",
            "Given an array of integers nums and an integer target, return indices of the two numbers that add up to target.\n\nYou may assume each input has exactly one solution, and you may not use the same element twice.\n\nExample:\nInput: 2 7 11 15 9\nOutput: 0 1",
            "Easy", "Space-separated integers, last number is target", "Two indices separated by space",
            "2 <= array length <= 10^4, -10^9 <= nums[i] <= 10^9, -10^9 <= target <= 10^9",
            {{"2 7 11 15 9", "0 1"}, {"3 2 4 6", "1 2"}});
        // Problem 2: Add Two Numbers
        problems.insert(2, "Add Two Numbers",
            "Given two integers a and b, output their sum.",
            "Easy", "Two integers separated by space", "Sum", "-1000 <= a,b <= 1000",
            {{"2 3", "5"}, {"10 20", "30"}});
        // Problem 3: Maximum Element
        problems.insert(3, "Maximum Element",
            "Given an array, find the maximum element.",
            "Easy", "Space-separated integers", "Maximum value", "1 <= n <= 100",
            {{"1 3 2 5 4", "5"}, {"10 20 30", "30"}});
        // Problem 4: Sum of Array
        problems.insert(4, "Sum of Array",
            "Calculate the sum of all elements.",
            "Easy", "Space-separated integers", "Sum", "1 <= n <= 100",
            {{"1 2 3 4 5", "15"}, {"10 20 30", "60"}});
        // Problem 5: Palindrome String
        problems.insert(5, "Palindrome String",
            "Check if a string reads the same forwards and backwards (case-sensitive).",
            "Easy", "Single string", "Yes or No", "1 <= |s| <= 100",
            {{"radar", "Yes"}, {"hello", "No"}});
        // Problem 6: Prime Check
        problems.insert(6, "Prime Check",
            "Check if an integer is prime.",
            "Easy", "Single integer", "Prime or Not Prime", "1 <= n <= 10^6",
            {{"7", "Prime"}, {"10", "Not Prime"}});
        // Problem 7: Count Vowels
        problems.insert(7, "Count Vowels",
            "Count vowels (a,e,i,o,u) case-insensitive.",
            "Easy", "Single string", "Number of vowels", "1 <= |s| <= 100",
            {{"hello", "2"}, {"programming", "3"}});
        // Problem 8: Sort Array
        problems.insert(8, "Sort Array",
            "Sort array in non-decreasing order.",
            "Medium", "Space-separated integers", "Sorted integers", "1 <= n <= 100",
            {{"3 1 2", "1 2 3"}, {"5 4 3 2 1", "1 2 3 4 5"}});
        // Problem 9: Factorial
        problems.insert(9, "Factorial",
            "Compute n!",
            "Medium", "Single integer n", "n!", "0 <= n <= 12",
            {{"5", "120"}, {"7", "5040"}});
        // Problem 10: Fibonacci
        problems.insert(10, "Fibonacci",
            "Return the nth Fibonacci number (0-indexed).",
            "Medium", "Single integer n", "F(n)", "0 <= n <= 30",
            {{"5", "5"}, {"10", "55"}});
        // Problem 11: Reverse Words
        problems.insert(11, "Reverse Words",
            "Reverse the order of words in a string.",
            "Medium", "String with spaces", "Words reversed", "1 <= words <= 10",
            {{"hello world", "world hello"}, {"code judge", "judge code"}});
        // Problem 12: Rotate Array Right
        problems.insert(12, "Rotate Array Right",
            "Rotate array to the right by k steps.",
            "Medium", "Space-separated integers, last is k", "Rotated array", "1 <= n <= 100, 0 <= k <= 100",
            {{"1 2 3 4 5 2", "4 5 1 2 3"}, {"1 2 3 1", "3 1 2"}});
        // Problem 13: GCD
        problems.insert(13, "GCD",
            "Compute greatest common divisor using Euclidean algorithm.",
            "Medium", "Two integers a b", "GCD", "1 <= a,b <= 10^6",
            {{"12 8", "4"}, {"17 5", "1"}});
        // Problem 14: Power Function
        problems.insert(14, "Power Function",
            "Compute x^n without pow().",
            "Medium", "Two integers x n", "x^n", "0 <= x,n <= 10",
            {{"2 5", "32"}, {"3 4", "81"}});
        // Problem 15: Binary Search
        problems.insert(15, "Binary Search",
            "Return index of target in sorted array (0-based), else -1.",
            "Hard", "Sorted array followed by target", "Index or -1", "1 <= n <= 100",
            {{"1 2 3 4 5 3", "2"}, {"10 20 30 40 20", "1"}});
        // Problem 16: Merge Sorted Arrays
        problems.insert(16, "Merge Sorted Arrays",
            "Merge two sorted arrays into one sorted array.",
            "Hard", "First line: n1, second line: n1 ints, third line: n2, fourth line: n2 ints",
            "Merged sorted array", "1 <= n1,n2 <= 50",
            {{"3\n1 3 5\n3\n2 4 6", "1 2 3 4 5 6"}, {"2\n1 2\n2\n3 4", "1 2 3 4"}});
        // Problem 17: Longest Substring Without Repeating Characters
        problems.insert(17, "Longest Substring Without Repeating",
            "Length of longest substring without repeating characters.",
            "Hard", "Single string", "Length", "1 <= |s| <= 100",
            {{"abcabcbb", "3"}, {"bbbbb", "1"}});
        // Problem 18: Coin Change (minimum coins)
        problems.insert(18, "Coin Change",
            "Minimum number of coins to make amount (unlimited supply).",
            "Hard", "First line: n, second line: coins, third line: amount", "Minimum coins or -1",
            "1 <= n <= 10, 1 <= coin <= 100, 1 <= amount <= 1000",
            {{"3\n1 2 5\n11", "3"}, {"2\n2 3\n4", "2"}});
        // Problem 19: BFS Traversal
        problems.insert(19, "BFS Traversal",
            "BFS traversal of undirected graph from node 1 (visit in increasing order).",
            "Hard", "First line: V E, next E lines: u v", "BFS order", "1 <= V <= 10",
            {{"4 4\n1 2\n1 3\n2 4\n3 4", "1 2 3 4"}, {"3 2\n1 2\n2 3", "1 2 3"}});
        // Problem 20: 0/1 Knapsack
        problems.insert(20, "0/1 Knapsack",
            "Maximum value with capacity W (0/1 property).",
            "Hard", "First line: n W, next n lines: weight value", "Max value", "1 <= n <= 10, 1 <= W <= 100",
            {{"3 10\n1 2\n3 4\n5 10", "15"}, {"2 5\n2 3\n4 5", "10"}});

        for(int i=1; i<=20; i++) {
            AVLNode* p = problems.search(i);
            if(p) {
                titles[i] = p->title;
                searchIndex.insert(p->title, i);
            }
        }
        vector<pair<int,int>> edges = {{1,2},{2,3},{3,4},{4,8},{5,7},{6,9},{7,11},
                                       {8,12},{9,10},{10,14},{11,17},{12,15},{13,14},
                                       {14,18},{15,16},{16,19},{17,18},{18,20},{19,20}};
        for(auto& e : edges) graph.addEdge(e.first, e.second);
        users.recomputeProblemCounts(problems);
    }

    void processPending() {
        while(history.hasPending()) {
            Submission* s = history.popPending();
            if(!s) continue;
            if(s->verdict == "AC") {
                User* u = users.getUser(s->username);
                if(u) {
                    bool already = find(u->solvedProblems.begin(), u->solvedProblems.end(), s->problemId) != u->solvedProblems.end();
                    if(!already) {
                        int points = (s->problemId <= 7) ? 100 : (s->problemId <= 14) ? 200 : 300;
                        users.addScore(s->username, points);
                        users.addSolved(s->username, s->problemId);
                        AVLNode* p = problems.search(s->problemId);
                        if(p) p->solveCount++;
                    }
                }
            }
        }
        leaderboard.rebuild(users.all());
    }

    void submitSolution(int pid) {
        AVLNode* p = problems.search(pid);
        if(!p) return;
        clearScreen();
        cout << CYAN << BOLD << "\n  ==========================================================\n";
        cout << "  Submit Solution - Problem " << pid << ": " << p->title << "\n";
        cout << "  ==========================================================\n" << RESET;
        cout << GREEN << "  " << p->description << RESET << "\n\n";
        cout << BLUE << "  Input Format: " << RESET << p->inputFormat << "\n";
        cout << BLUE << "  Output Format: " << RESET << p->outputFormat << "\n";
        cout << BLUE << "  Constraints: " << RESET << p->constraints << "\n\n";
        cout << YELLOW << "  Paste your full C++ code below (end with a line containing only 'END'):\n" << RESET;
        cout << CYAN << "  ----------------------------------------------------------\n" << RESET;
        string code, line;
        while(getline(cin, line)) {
            if(line == "END") break;
            code += line + "\n";
        }
        if(code.empty()) {
            cout << RED << "\n  Error: Empty code!\n" << RESET;
            cout << "\n  Press Enter..."; cin.get();
            return;
        }
        cout << "\n" << YELLOW << "  Compiling and running...\n" << RESET;
        Submission* sub = judge.judge(currentUser, pid, code, p->testCases);
        history.add(sub);
        processPending();

        cout << CYAN << "\n  ==========================================================\n" << RESET;
        if(sub->verdict == "AC") cout << BG_GREEN << "  VERDICT: ACCEPTED (AC) - All test cases passed!" << RESET << "\n";
        else cout << BG_RED << "  VERDICT: " << sub->verdict << RESET << "\n";
        cout << CYAN << "  ==========================================================\n" << RESET;
        cout << "\n  Press Enter..."; cin.get();
    }

    void showProblemDetail(int pid) {
        AVLNode* p = problems.search(pid);
        if(!p) return;
        clearScreen();
        cout << CYAN << BOLD << "\n  ==========================================================\n";
        cout << "  Problem #" << pid << ": " << p->title << "\n";
        cout << "  ==========================================================\n" << RESET;
        int pts = (p->difficulty=="Easy")?100:(p->difficulty=="Medium")?200:300;
        cout << "  Difficulty: " << diffColor(p->difficulty) << BOLD << p->difficulty << RESET;
        cout << "  |  Points: " << YELLOW << pts << RESET << "\n\n";
        cout << WHITE << "  Description:\n  " << RESET << p->description << "\n\n";
        cout << BLUE << "  Input Format: " << RESET << p->inputFormat << "\n";
        cout << BLUE << "  Output Format: " << RESET << p->outputFormat << "\n";
        cout << BLUE << "  Constraints: " << RESET << p->constraints << "\n";
        cout << BLUE << "  Sample Test Cases: " << RESET << p->testCases.size() << "\n\n";
        cout << CYAN << "  ----------------------------------------------------------\n" << RESET;
        cout << YELLOW << "  [S] Submit Solution  |  [B] Back\n";
        cout << CYAN << "  ----------------------------------------------------------\n" << RESET;
        cout << WHITE << "  Command: " << RESET;
        string cmd; getline(cin, cmd);
        if(cmd=="S" || cmd=="s") submitSolution(pid);
    }

    void showProblemsPage() {
        while(true) {
            clearScreen();
            auto all = problems.getAll();
            User* u = users.getUser(currentUser);
            cout << CYAN << BOLD << "\n  ==========================================================\n";
            cout << "            ONLINE CODING JUDGE SYSTEM - Problems           \n";
            cout << "  ==========================================================\n" << RESET;
            cout << GREEN << "  User: " << BOLD << currentUser << RESET;
            cout << GREEN << "  |  Score: " << YELLOW << u->score << RESET;
            cout << GREEN << "  |  Solved: " << YELLOW << u->solvedProblems.size() << "/20" << RESET << "\n";
            cout << CYAN << "  ----------------------------------------------------------\n" << RESET;
            cout << YELLOW << "  [S] Search  |  [ID] View/Submit  |  [B] Back\n";
            cout << CYAN << "  ----------------------------------------------------------\n" << RESET;
            cout << GREEN << BOLD << "\n  EASY (100 points)\n" << RESET;
            for(auto* p : all) if(p->difficulty=="Easy")
                cout << "  " << YELLOW << setw(2) << p->id << RESET << ". " << setw(25) << left << p->title << GREEN << p->difficulty << RESET << "\n";
            cout << YELLOW << BOLD << "\n  MEDIUM (200 points)\n" << RESET;
            for(auto* p : all) if(p->difficulty=="Medium")
                cout << "  " << YELLOW << setw(2) << p->id << RESET << ". " << setw(25) << left << p->title << YELLOW << p->difficulty << RESET << "\n";
            cout << RED << BOLD << "\n  HARD (300 points)\n" << RESET;
            for(auto* p : all) if(p->difficulty=="Hard")
                cout << "  " << YELLOW << setw(2) << p->id << RESET << ". " << setw(25) << left << p->title << RED << p->difficulty << RESET << "\n";
            cout << CYAN << "\n  ----------------------------------------------------------\n" << RESET;
            cout << WHITE << "  Command: " << RESET;
            string cmd; getline(cin, cmd);
            if(cmd=="B"||cmd=="b") break;
            else if(cmd=="S"||cmd=="s") {
                cout << "  Search keyword: "; string kw; getline(cin, kw);
                auto results = searchIndex.searchPrefix(kw);
                clearScreen();
                cout << CYAN << BOLD << "\n  Search Results for: '" << kw << "'\n";
                cout << "  ==========================================================\n" << RESET;
                if(results.empty()) cout << RED << "  No matches.\n" << RESET;
                else {
                    for(int id : results) {
                        AVLNode* p = problems.search(id);
                        if(p) cout << "  " << YELLOW << setw(2) << id << RESET << ". " << setw(25) << left << p->title
                                   << " (" << diffColor(p->difficulty) << p->difficulty << RESET << ")\n";
                    }
                    cout << CYAN << "\n  ----------------------------------------------------------\n" << RESET;
                    cout << YELLOW << "  Enter ID to view, or B to go back: " << RESET;
                    string choice; getline(cin, choice);
                    if(choice!="B" && choice!="b") {
                        try { int pid = stoi(choice); if(problems.search(pid)) showProblemDetail(pid); }
                        catch(...) { cout << RED << "  Invalid ID\n" << RESET; cin.get(); }
                    }
                }
                if(results.empty()) { cout << "\n  Press Enter..."; cin.get(); }
            } else {
                try {
                    int pid = stoi(cmd);
                    if(problems.search(pid)) showProblemDetail(pid);
                    else { cout << RED << "  Invalid ID\n" << RESET; cin.get(); }
                } catch(...) { cout << RED << "  Invalid command\n" << RESET; cin.get(); }
            }
        }
    }

    void showHistory() {
        clearScreen();
        cout << CYAN << BOLD << "\n  ==========================================================\n";
        cout << "  Submission History - " << currentUser << "\n";
        cout << "  ==========================================================\n" << RESET;
        auto subs = history.getUser(currentUser);
        if(subs.empty()) cout << YELLOW << "\n  No submissions yet.\n" << RESET;
        else {
            for(auto* s : subs) {
                bool ac = (s->verdict.find("AC")!=string::npos);
                cout << (ac ? GREEN : RED);
                cout << "\n  [" << s->problemId << "] " << titles[s->problemId] << "\n";
                cout << "  Verdict: " << BOLD << s->verdict << RESET;
                cout << "\n  Time: " << s->timestamp << "\n";
            }
        }
        cout << "\n  Press Enter..."; cin.get();
    }

    void showLeaderboard() {
        clearScreen();
        cout << CYAN << BOLD << "\n  ==========================================================\n";
        cout << "  Leaderboard (Top 10)\n";
        cout << "  ==========================================================\n" << RESET;
        auto top = leaderboard.top(10);
        int rank=1;
        for(auto& [name,score] : top) {
            if(name == currentUser) cout << GREEN << BOLD;
            else cout << RESET;
            cout << "  " << setw(2) << rank++ << ". " << setw(15) << left << name << "  " << YELLOW << score << " points" << RESET << "\n";
        }
        cout << "\n  Press Enter..."; cin.get();
    }

    void showRecommendations() {
        clearScreen();
        cout << CYAN << BOLD << "\n  ==========================================================\n";
        cout << "  Recommended Problems\n";
        cout << "  ==========================================================\n" << RESET;
        cout << "  Enter problem ID: ";
        string inp; getline(cin, inp);
        try {
            int id = stoi(inp);
            User* u = users.getUser(currentUser);
            auto recs = recommender->recommend(id, u->solvedProblems);
            clearScreen();
            cout << CYAN << BOLD << "\n  Recommendations based on Problem " << id << ": " << titles[id] << "\n";
            cout << "  ==========================================================\n" << RESET;
            if(recs.empty()) cout << YELLOW << "\n  No recommendations.\n" << RESET;
            else {
                cout << GREEN << "\n  Try these next:\n" << RESET;
                for(int rid : recs) {
                    AVLNode* p = problems.search(rid);
                    if(p) cout << "  " << YELLOW << setw(2) << rid << RESET << ". " << setw(25) << left << p->title
                               << " (" << diffColor(p->difficulty) << p->difficulty << RESET << ")\n";
                }
                cout << CYAN << "\n  ----------------------------------------------------------\n" << RESET;
                cout << YELLOW << "  Enter ID to view, or B to go back: " << RESET;
                string choice; getline(cin, choice);
                if(choice!="B" && choice!="b") {
                    try { int pid = stoi(choice); if(problems.search(pid)) showProblemDetail(pid); }
                    catch(...) {}
                }
            }
        } catch(...) { cout << RED << "  Invalid ID\n" << RESET; cin.get(); }
        cout << "\n  Press Enter..."; cin.get();
    }

    void showLearningPath() {
        clearScreen();
        cout << CYAN << BOLD << "\n  ==========================================================\n";
        cout << "  Learning Path Generator\n";
        cout << "  ==========================================================\n" << RESET;
        int start, target;
        cout << "  Start problem ID: "; cin >> start;
        cout << "  Target problem ID: "; cin >> target; cin.ignore();
        auto path = recommender->path(start, target);
        clearScreen();
        cout << CYAN << BOLD << "\n  Learning Path: " << titles[start] << " -> " << titles[target] << "\n";
        cout << "  ==========================================================\n" << RESET;
        if(path.empty()) cout << RED << "\n  No path found.\n" << RESET;
        else {
            cout << GREEN << "\n  Path length: " << path.size() << " problems\n" << RESET;
            cout << "\n  ";
            for(size_t i=0; i<path.size(); i++) {
                if(i>0) cout << CYAN << "  ->  " << RESET;
                cout << BOLD << titles[path[i]] << RESET;
            }
            cout << "\n\n" << YELLOW << "  Follow this path to build skills progressively.\n" << RESET;
        }
        cout << "\n  Press Enter..."; cin.get();
    }

    void mainMenu() {
        while(loggedIn) {
            clearScreen();
            User* u = users.getUser(currentUser);
            cout << CYAN << BOLD << "\n  ==========================================================\n";
            cout << "            ONLINE CODING JUDGE SYSTEM                      \n";
            cout << "  ==========================================================\n" << RESET;
            cout << GREEN << "  Welcome, " << BOLD << currentUser << RESET;
            cout << GREEN << "  |  Score: " << YELLOW << u->score << RESET;
            cout << GREEN << "  |  Solved: " << YELLOW << u->solvedProblems.size() << "/20" << RESET << "\n";
            cout << CYAN << "  ----------------------------------------------------------\n" << RESET;
            cout << "\n  1. View All Problems & Submit\n";
            cout << "  2. Submission History\n";
            cout << "  3. Leaderboard\n";
            cout << "  4. Recommended Problems\n";
            cout << "  5. Learning Path\n";
            cout << "  6. Logout\n";
            cout << CYAN << "  ----------------------------------------------------------\n" << RESET;
            cout << WHITE << "  Choice: " << RESET;
            string ch; getline(cin, ch);
            if(ch=="1") showProblemsPage();
            else if(ch=="2") showHistory();
            else if(ch=="3") showLeaderboard();
            else if(ch=="4") showRecommendations();
            else if(ch=="5") showLearningPath();
            else if(ch=="6") { loggedIn=false; currentUser=""; break; }
        }
    }

public:
    OnlineJudgeSystem() : loggedIn(false) {
        recommender = new RecommendationEngine(&graph);
        loadProblems();
        leaderboard.rebuild(users.all());
    }
    ~OnlineJudgeSystem() { delete recommender; }

    void run() {
        while(true) {
            clearScreen();
            cout << CYAN << BOLD << "\n  ==========================================================\n";
            cout << "            ONLINE CODING JUDGE SYSTEM                      \n";
            cout << "            Practice * Compete * Improve                    \n";
            cout << "  ==========================================================\n" << RESET;
            cout << "\n  1. Register\n";
            cout << "  2. Login\n";
            cout << "  3. Exit\n";
            cout << CYAN << "  ----------------------------------------------------------\n" << RESET;
            cout << WHITE << "  Choice: " << RESET;
            string ch; getline(cin, ch);
            if(ch=="1") {
                clearScreen();
                cout << CYAN << BOLD << "\n  Register New Account\n";
                cout << "  ==========================================================\n" << RESET;
                string u,p;
                cout << "  Username: "; getline(cin, u);
                cout << "  Password: "; getline(cin, p);
                if(u.empty()||p.empty()) cout << RED << "\n  Error: Username/password cannot be empty.\n" << RESET;
                else if(users.registerUser(u,p)) cout << GREEN << "\n  Account created! Please login.\n" << RESET;
                else cout << RED << "\n  Username already exists.\n" << RESET;
                cout << "\n  Press Enter..."; cin.get();
            } else if(ch=="2") {
                clearScreen();
                cout << CYAN << BOLD << "\n  Login\n";
                cout << "  ==========================================================\n" << RESET;
                string u,p;
                cout << "  Username: "; getline(cin, u);
                cout << "  Password: "; getline(cin, p);
                if(users.login(u,p)) {
                    currentUser = u; loggedIn = true;
                    cout << GREEN << "\n  Login successful! Welcome back, " << u << ".\n" << RESET;
                    cout << "\n  Press Enter..."; cin.get();
                    mainMenu();
                } else {
                    cout << RED << "\n  Invalid username or password.\n" << RESET;
                    cout << "\n  Press Enter..."; cin.get();
                }
            } else if(ch=="3") {
                clearScreen();
                cout << GREEN << BOLD << "\n  Thank you for using the Online Coding Judge System!\n";
                cout << "  Keep coding and improving your skills!\n";
                cout << "  ==========================================================\n" << RESET;
                cout << "\n";
                break;
            }
        }
    }
};

int main() {
    OnlineJudgeSystem judge;
    judge.run();
    return 0;
}