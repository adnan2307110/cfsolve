#include <iostream>
#include <string>
#include <vector>
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
    Voter(string i, string n)
    {
        id = i;
        name = n;
        hasVoted = false;
    }

    string getID()
    {
        return id;
    }
    string getName()
    {
        return name;
    }
    bool   voted()
    {
        return hasVoted;
    }

    void setVoted()
    {
        hasVoted = true;
    }

    string getPassword()
    {
        
        return id.substr(id.size() - 3);
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

    Candidate(int i, string n, string p)
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
        cout << v.getName() << " voted for "
             << c.name << " (" << c.post << ")" << endl;
    }
};
// Initialize static member
int Election::totalVotes = 0;

// ======================
// Eligibility
// ======================
bool checkEligibility(Voter &v)
{
    // Check if ID is 7 characters, starts with '2', and the second digit is between '0' and '4'
    if (v.id.size() == 7 && v.id[0] == '2' &&
            (v.id[1] >= '0' && v.id[1] <= '4'))
    {
        return true;
    }
    return false;
}



// ======================
// Clear Screen
// ======================
void clearScreen()
{
    for (int i = 0; i < 52; i++) cout << "\n";
}

// ======================
// Main
// ======================
int main()
{
    // Candidate setup
    vector<Candidate> candidates =
    {
        {101, "Kamal", "VP"}, {102, "Rahim", "VP"}, {103, "Selina", "VP"},
        {201, "Nusrat", "GS"}, {202, "Karim", "GS"}, {203, "Farhan", "GS"},
        {301, "Anika", "AGS"}, {302, "Hasan", "AGS"}, {303, "Tanvir", "AGS"}
    };

    // Voter setup
    vector<Voter> voters =
    {
        {"2307112", "Adnan"}, {"2307111", "Arnay"},
        {"2307113", "Galib"}, {"2307114", "Jisan"},
        {"2307115", "Udoy"}
    };

    Election e;

    cout << "==== Welcome to the Voting System ====\n";
    

    string id;
    // Modified: Use a while loop to continue login attempts until all known voters have voted.
    while (Election::totalVotes < voters.size())
    {
        cout << "\n--- Voter Login --- (" << Election::totalVotes/3 << "/" << voters.size() << " voted)\n";
        cout << "Enter your ID to login: ";

        // Clear input buffer before reading ID (to handle potential lingering newlines from previous loops)
        if (Election::totalVotes > 0)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (!(cin >> id))
        {
            cout << "Invalid input! Exiting.\n";
            break;
        }

        // Find the voter in the vector
        Voter* currentVoter = nullptr;
        for (auto &v : voters)
        {
            if (v.getID() == id)
            {
                currentVoter = &v;
                break;
            }
        }

        if (currentVoter)
        {
            string password;
            cout << "Enter your password : ";
            if (!(cin >> password))
            {
                cout << "Invalid input! Exiting.\n";
                break;
            }

            // Handle wrong password: restart the login process
            if (password != currentVoter->getPassword())
            {
                cout << "Wrong password! Access denied. Please try again.\n";
                continue;
            }

            // Check eligibility and voting status
            if (!checkEligibility(*currentVoter))
            {
                cout << currentVoter->getName() << " is NOT eligible to vote!\n";
            }
            else if (currentVoter->voted())
            {
                cout << " You have already Voted! \n";
            }
            else
            {
                // Voting Process
                cout << "\nHello, " << currentVoter->getName()
                     << "! You will now vote for each post.\n";

                string posts[3] = {"VP", "GS", "AGS"};
                for (string post : posts)
                {
                    bool validChoice = false;

                    // Modified: Loop until a valid candidate ID is entered for the current post
                    while (!validChoice)
                    {
                        cout << "\n-- " << post << " Candidates --\n";
                        for (auto &c : candidates)
                        {
                            if (c.post == post)
                            {
                                cout << c.id << ". " << c.name << endl;
                            }
                        }

                        int choice;
                        cout << "Enter candidate ID for " << post << ": ";

                        // Robust input check
                        if (!(cin >> choice))
                        {
                            cout << "Invalid input! Please enter a number.\n";
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            continue; // Restart the while loop for this post
                        }

                        // Validate and cast vote
                        for (auto &c : candidates)
                        {
                            if (c.id == choice && c.post == post)
                            {
                                e.castVote(*currentVoter, c);
                                validChoice = true;
                                break;
                            }
                        }

                        if (!validChoice)
                        {
                            cout << "Invalid candidate ID for " << post << "! Please choose from the list.\n";
                        }
                    } // End while (!validChoice)
                } // End for (string post : posts)

                currentVoter->setVoted();
                cout << "\nThank you for voting, " << currentVoter->getName() << "!\n";
                cout << "Your votes have been recorded.\n";
                // Wait for user to press enter before clearing screen
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear any remaining newline
                cout << "\nPress Enter to continue...";
                cin.get();
                clearScreen();
            }
        }
        else
        {
            cout << "Invalid UID. Try again!\n";
        }
    } // End while (Election::totalVotes < voters.size())

    cout << "\n--- Election Results ---\n";
    string posts[3] = {"VP", "GS", "AGS"};
    for (string post : posts)
    {
        cout << "\nResults for " << post << ":\n";
        // Simple display of results
        for (auto &c : candidates)
        {
            if (c.post == post)
            {
                cout << c.name << ": " << c.votes << " votes\n";
            }
        }
    }
    cout << "\nTotal Votes Cast: " << Election::totalVotes << endl;
    return 0;
}