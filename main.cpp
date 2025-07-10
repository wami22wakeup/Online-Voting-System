#include <iostream>
#include <sstream>  // REQUIRED for stringstream + getline
#include <fstream>
#include <map>
#include <vector>
#include <ctime>
#include "encryption.h"
#include "utils.h"
using namespace std;

vector<string> candidates = {"Alice", "Bob", "Charlie", "NOTA"};
const string ADMIN_PASS = "admin123";

void castVote(string voterID) {
    if (hasVoted(voterID)) {
        cout << "You have already voted!\n";
        return;
    }

    cout << "\nCandidates:\n";
    for (int i = 0; i < candidates.size(); ++i) {
        cout << i + 1 << ". " << candidates[i] << endl;
    }

    int choice;
    cout << "Enter your choice (number): ";
    cin >> choice;

    if (choice < 1 || choice > candidates.size()) {
        cout << "Invalid choice!\n";
        return;
    }

    string voteData = voterID + "," + candidates[choice - 1];
    
    // Timestamp
    time_t now = time(0);
    voteData += "," + string(ctime(&now));

    // Encrypt
    string encryptedVote = encrypt(voteData);

    ofstream file("votes.csv", ios::app);
    file << encryptedVote << endl;

    markVoted(voterID);
    cout << "Vote cast successfully (EVM simulated beep 🔊)\n";
}

/*void showResults() {
    ifstream file("votes.csv");
    string line;
    map<string, int> result;

    while (getline(file, line)) {
        string decrypted = encrypt(line); // decrypt
        size_t firstComma = decrypted.find(",");
        size_t secondComma = decrypted.find(",", firstComma + 1);

        string candidate = decrypted.substr(firstComma + 1, secondComma - firstComma - 1);
        result[candidate]++;
    }

    cout << "\n=== Voting Results ===\n";
    for (auto &c : candidates) {
        cout << c << ": " << result[c] << " votes\n";
    }
}*/
void showResults() {
    ifstream file("votes.csv");
    string line;
    map<string, int> result;

    while (getline(file, line)) {
        string decrypted = encrypt(line); // decrypt

        // Use stringstream for safe splitting
        stringstream ss(decrypted);
        string voterID, candidate, timestamp;

        getline(ss, voterID, ',');
        getline(ss, candidate, ',');
        getline(ss, timestamp);  // rest of the line is timestamp

        result[candidate]++;
    }

    cout << "\n=== Voting Results ===\n";
    for (auto &c : candidates) {
        cout << c << ": " << result[c] << " votes\n";
    }
}

int main() {
    int choice;
    string voterID;

    while (true) {
        cout << "\n--- Online Voting System ---\n";
        cout << "1. Cast Vote\n2. View Results (Admin)\n3. Exit\nChoice: ";
        cin >> choice;

        switch (choice){
            case 1:{
                cout << "Enter Voter ID: ";
                cin >> voterID;
                castVote(voterID);
                break;

            }
                
            case 2:
                {
                    string pass;
                    cout << "Enter admin password: ";
                    cin >> pass;
                    if (pass == ADMIN_PASS) showResults();
                    else cout << "Access denied.\n";
                    break;
            }
            case 3:
                {
                    cout << "Thank you for voting!\n";
                    return 0;
            }
            default:
                {
                    cout << "Invalid choice.\n";
                }
        }
    }
}
