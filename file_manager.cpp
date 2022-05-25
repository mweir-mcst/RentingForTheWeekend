#include <fstream>
#include <string>
#include <vector>

#include "file_manager.h"
#include "User.h"

using namespace std;

vector<User*> load_from_file() {
    vector<User*> users;

    ifstream fin("users.txt");
    if (!fin.good()) return users;

    int currentUser = 0;
    string currentValue;
    vector<string> currentUserInfo;
    while (fin.peek() != EOF) {
        getline(fin, currentValue);
        if (currentValue.empty()) {
            currentUser++;
            users.push_back(new User(currentUserInfo[0], currentUserInfo[1], stoi(currentUserInfo[2]), currentUserInfo[3], stoi(currentUserInfo[4]), stoi(currentUserInfo[5]), currentUserInfo[6] == "true", currentUserInfo[7] == "true", currentUserInfo[8] == "true"));
            users.clear();
        } else {
            currentUserInfo.push_back(currentValue);
        }
    }

    fin.close();
    return users;
}

void save_to_file(vector<User*>& users) {
    ofstream fout("users.txt");

    for (User* user : users) fout << user->cardHolder << endl
        << user->address << endl
        << user->memberCount << endl
        << user->emergencyContact << endl
        << user->rentalDays << endl
        << user->vehicle << endl
        << user->roadsideAssistance << endl
        << user->gasFillCoverage << endl
        << user->driverFaultCoverage << endl << endl;

    fout.close();
}