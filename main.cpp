#include <iostream>

#include "console.h"
#include "file_manager.h"
#include "User.h"

using namespace std;

void manageUsers(vector<User>& users) {
    cout << "1) Add new user" << endl
        << "2) Edit user" << endl
        << "3) Remove user" << endl;

    User user;
    string cardHolder;
    int index;

    switch (prompt_int_min_max("Choose an option (1-3): ", 1, 3)) {
        case 1:
            users.push_back(createUser());
            break;
        case 2:
            cardHolder = prompt_string("Enter card holder of user: ");
            if (!findUser(cardHolder, users, user, index)) {
                cout << "No user exists with cardholder name " << cardHolder << "." << endl;
                return;
            }
            user.edit();
            break;
        case 3:
            cardHolder = prompt_string("Enter card holder of user: ");
            if (!findUser(cardHolder, users, user, index)) {
                cout << "No user exists with cardholder name " << cardHolder << "." << endl;
                return;
            }
            users.erase(users.begin() + index);
            cout << "Removed " << cardHolder << " from the system.";
            break;
    };
}


int main() {

    // Vector of users get's created from
    vector<User> users = load_from_file();

    // Variables
    bool running = true;
    string strPrompt;
    int choice;
    int location;

    while (running) {
        cout << "Welcome to the Alamo Car Renting Service! How may we help you today?" << endl
            << "1) Add, remove, or edit user(s)" << endl
            << "2) Display user's bill" << endl
            << "3) Exit program" << endl;
      
        string cardHolder;
        User user;
        int index;
        switch(prompt_int_min_max("Enter menu option: ", 1, 5)) {
            case 1:
                manageUsers(users);
            case 2:
                cardHolder = prompt_string("Enter card holder of user: ");
                if (!findUser(cardHolder, users, user, index)) {
                    cout << "No user exists with cardholder name " << cardHolder << "." << endl;
                    break;
                }
                user.displayBill();
                break;
            case 3:
                running = false;
                break;
        }
    }

    save_to_file(users);
    return 0;
}
