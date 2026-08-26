#include <iostream>
#include <string>
#include <iomanip>
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
        // Last 3 digits of ID
        if (id.size() >= 3)
            return id.substr(id.size() - 3);
        else
            return id;
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
        c.votes++;
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
    for (int i = 0; i < 40; i++)
        cout << "\n";
}

// ======================
// Main
// ======================
int main()
{
    const int candidateCount = 9;
    const int voterCount = 6;

    Candidate candidates[candidateCount] = {
        {101, "Kamal", "VP"}, {102, "Rahim", "VP"}, {103, "Selina", "VP"}, {201, "Nusrat", "GS"}, {202, "Karim", "GS"}, {203, "Farhan", "GS"}, {301, "Anika", "AGS"}, {302, "Hasan", "AGS"}, {303, "Tanvir", "AGS"}};

    Voter voters[voterCount] = {
        {"2307110", "Adnan"},
        {"2307112", "Adnan"},
        {"2307111", "Arnay"},
        {"2307113", "Galib"},
        {"2307114", "Jisan"},
        {"2307115", "Udoy"}};

    Election e;

    cout << "==== Welcome to the Voting System ====\n";

    string id;
    while (Election::totalVotes < voterCount * 3)
    {
        cout << "\n--- Voter Login --- (" << Election::totalVotes / 3
             << "/" << voterCount << " voted)\n";
        cout << "Enter your ID: ";
        cin >> id;
        Voter *currentVoter;
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
            cout << "Enter your password: ";
            cin >> password;

            if (password != currentVoter->getPassword())
            {
                cout << "Wrong password! Access denied.\n";
                continue;
            }

            if (!checkEligibility(*currentVoter))
            {
                cout << currentVoter->getName() << " is NOT eligible to vote!\n";
            }
            else if (currentVoter->voted())
            {
                cout << "You have already voted!\n";
            }
            else
            {
                cout << "\nHello, " << currentVoter->getName()
                     << "! You will now vote for each post.\n";

                string posts[3] = {"VP", "GS", "AGS"};
                for (int p = 0; p < 3; p++)
                {
                    bool validChoice = false;
                    while (!validChoice)
                    {
                        cout << "\n-- " << posts[p] << " Candidates --\n";
                        for (int i = 0; i < candidateCount; i++)
                        {
                            if (candidates[i].post == posts[p])
                            {
                                cout << candidates[i].id << ". " << candidates[i].name << endl;
                            }
                        }

                        int choice;
                        cout << "Enter candidate ID for " << posts[p] << ": ";
                        cin >> choice;
                        /*if (!(cin >> choice))
                        {
                            cout << "Invalid input! Please enter a number.\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue;
                        }*/

                        for (int i = 0; i < candidateCount; i++)
                        {
                            if (candidates[i].id == choice &&
                                candidates[i].post == posts[p])
                            {
                                e.castVote(*currentVoter, candidates[i]);
                                validChoice = true;
                                break;
                            }
                        }

                        if (!validChoice)
                            cout << "Invalid candidate ID! Try again.\n";
                    }
                }

                currentVoter->setVoted();
                cout << "\nThank you for voting, " << currentVoter->getName() << "!\n";
                cout << "Your votes have been recorded.\n";

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\nPress Enter to continue...";
                cin.get();
                clearScreen();
            }
        }
        else
        {
            cout << "Invalid ID. Try again!\n";
        }
    }

    cout << "\n--- Election Results ---\n";
    string posts[3] = {"VP", "GS", "AGS"};
    for (int p = 0; p < 3; p++)
    {
        cout << "\nResults for " << posts[p] << ":\n";
        for (int i = 0; i < candidateCount; i++)
        {
            if (candidates[i].post == posts[p])
            {
                cout << candidates[i].name << ": " << candidates[i].votes << " votes\n";
            }
        }
    }

    cout << "\nTotal Votes Cast: " << Election::totalVotes << endl;
    return 0;
}
