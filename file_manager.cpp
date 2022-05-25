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
        } else {
            currentUserInfo.push_back(currentValue);
        }
    }

    return users;
}