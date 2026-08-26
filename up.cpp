#include <iostream>
#include <string>
#include <limits>
using namespace std;

// ======================
// Voter Class
// ======================
class Voter
{
    string id;
    string name;
    bool hasVoted;

public:
    Voter(string i = "", string n = "")
    {
        id = i;
        name = n;
        hasVoted = false;
    }

    string getID() { return id; }
    string getName() { return name; }
    bool voted() { return hasVoted; }
    void setVoted() { hasVoted = true; }

    string getPassword()
    {

        return id.substr(id.size() - 3);
    }

    bool operator==(const Voter &v)
    {
        return id == v.id;
    }

    // (2) !=
    bool operator!=(const Voter &v) const
    {
        return id != v.id;
    }

    friend bool checkEligibility(Voter &v);
};

// ======================
// Candidate Class
// ======================
class Candidate
{
public:
    int id;
    string name;
    string post;
    int votes;

    Candidate(int i = 0, string n = "", string p = "")
    {
        id = i;
        name = n;
        post = p;
        votes = 0;
    }

    // (3) >
    bool operator>(const Candidate &c) const
    {
        return votes > c.votes;
    }

    // (4) <
    bool operator<(const Candidate &c) const
    {
        return votes < c.votes;
    }

    // (5) ++  (prefix increment)
    Candidate &operator++()
    {
        votes++;
        return *this;
    }

    // (6) <<
    friend ostream &operator<<(ostream &out, const Candidate &c)
    {
        out << c.name << " (" << c.post << ") - " << c.votes << " votes";
        return out;
    }
};

// ======================
// Election Class
// ======================
class Election
{
public:
    static int totalVotes;
    void castVote(Voter &v, Candidate &c)
    {
        ++c; // uses overloaded ++
        totalVotes++;
        cout << v.getName() << " voted for " << c.name
             << " (" << c.post << ")" << endl;
    }
};

int Election::totalVotes = 0;

// ======================
// Eligibility Check
// ======================
bool checkEligibility(Voter &v)
{
    string id = v.getID();
    if (id.size() == 7 && id[0] == '2' && (id[1] >= '0' && id[1] <= '4'))
        return true;
    return false;
}

// ======================
// Clear Screen
// ======================
void clearScreen()
{
    for (int i = 0; i < 30; i++)
        cout << "\n";
}

// ======================
// Main
// ======================
int main()
{
    const int candidateCount = 6;
    const int voterCount = 6;

    Candidate candidates[candidateCount] = {
        {101, "Kamal", "VP"}, {102, "Rahim", "VP"}, {201, "Nusrat", "GS"}, {202, "Karim", "GS"}, {301, "Anika", "AGS"}, {302, "Tanvir", "AGS"}};

    Voter voters[voterCount] = {
        {"2307110", "Adnan"},
        {"2307111", "Arnay"},
        {"2307112", "Adnan"},
        {"2307113", "Galib"},
        {"2307114", "Jisan"},
        {"2307115", "Udoy"},

    };

    Election e;
    cout << "==== Welcome to the Voting System ====\n";

    string id;
    while (Election::totalVotes < voterCount * 3)
    {
        cout << "\n--- Voter Login --- (" << Election::totalVotes / 3
             << "/" << voterCount << " voted)\n";
        cout << "Enter your ID: ";
        cin >> id;

        Voter *currentVoter = nullptr;
        for (int i = 0; i < voterCount; i++)
        {
            if (voters[i].getID() == id)
            {
                currentVoter = &voters[i];
                break;
            }
        }

        if (currentVoter)
        {
            string password;
            cout << "Enter password: ";
            cin >> password;

            if (password != currentVoter->getPassword())
            {
                cout << "Wrong password! Try again.\n";
                continue;
            }

            if (!checkEligibility(*currentVoter))
            {
                cout << "Not eligible!\n";
            }
            else if (currentVoter->voted())
            {
                cout << "Already voted!\n";
            }
            else
            {
                string posts[3] = {"VP", "GS", "AGS"};
                for (int p = 0; p < 3; p++)
                {
                    cout << "\n-- " << posts[p] << " Candidates --\n";
                    for (int i = 0; i < candidateCount; i++)
                        if (candidates[i].post == posts[p])
                            cout << candidates[i].id << ". " << candidates[i].name << endl;

                    int choice;
                    cout << "Enter candidate ID for " << posts[p] << ": ";
                    cin >> choice;
                    bool validChoice = false;
                    string post = posts[p];

                    for (int i = 0; i < candidateCount; i++)
                    {
                        if (candidates[i].id == choice && candidates[i].post == posts[p])
                        {
                            e.castVote(*currentVoter, candidates[i]);
                            validChoice = true;
                            break;
                        }
                        
                    }
                    if (!validChoice)
                        {
                            cout << "Invalid candidate ID for " << post << "! Please choose from the list.\n";
                            p--;
                        }
                }
                currentVoter->setVoted();
                cout << "\nThanks, " << currentVoter->getName() << "!\n";
                cout << "Press Enter to continue...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
                clearScreen();
            }
        }
        else
        {
            cout << "Invalid ID!\n";
        }
    }

    cout << "\n--- Election Results ---\n";
    string posts[3] = {"VP", "GS", "AGS"};

    for (int p = 0; p < 3; p++)
    {
        cout << "\nResults for " << posts[p] << ":\n";
        Candidate winner;
        bool found = false;
        for (int i = 0; i < candidateCount; i++)
        {
            if (candidates[i].post == posts[p])
            {
                cout << candidates[i] << endl; // uses <<
                if (!found || candidates[i] > winner)
                    winner = candidates[i];
                found = true;
            }
        }
        cout << "🏆 Winner: " << winner.name << " (" << winner.votes << " votes)\n";
    }

    cout << "\nTotal Votes Cast: " << Election::totalVotes << endl;
    return 0;
}
