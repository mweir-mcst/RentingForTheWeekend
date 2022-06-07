/*
 Name: Matthew Weir & Xander Russell
 Program Name: Renting for the Weekend
 Date: 6/3/2022
 Extra Thing: Load/save users to/from file
 */

#include <iostream>

#include "console.h"
#include "file_manager.h"
#include "User.h"

using namespace std;

void manageUsers(vector<User>& users) {
    // Prompt the user for how they want to manage a user.
    cout << "1) Add new user" << endl
        << "2) Edit user" << endl
        << "3) Remove user" << endl;

    User user;
    string cardHolder;
    int index;

    switch (prompt_int_min_max("Choose an option (1-3): ", 1, 3)) {
        case 1:
            // Run the create user function and add it to the users vector
            users.push_back(createUser());
            break;
        case 2:
            // Pick a user
            cardHolder = prompt_string("Enter card holder of user: ");
            if (!findUser(cardHolder, users, user, index)) {
                cout << "No user exists with cardholder name " << cardHolder << "." << endl;
                return;
            }
            // Edit that user
            user.edit();
            break;
        case 3:
            // Pick a user
            cardHolder = prompt_string("Enter card holder of user: ");
            if (!findUser(cardHolder, users, user, index)) {
                cout << "No user exists with cardholder name " << cardHolder << "." << endl;
                return;
            }
            // Remove the index of the user
            users.erase(users.begin() + index);
            cout << "Removed " << cardHolder << " from the system.\n";
            break;
    };
}


int main() {
    // Load users from file
    vector<User> users = load_from_file();

    // Variables
    bool running = true;
    string strPrompt;
    int choice;
    int location;

    while (running) {
        // Prompt the user for the action they want to take
        cout << "Welcome to the Alamo Car Renting Service! How may we help you today?" << endl
            << "1) Add, remove, or edit user(s)" << endl
            << "2) Display user's bill" << endl
            << "3) Exit program" << endl;
      
        string cardHolder;
        User user;
        int index;
        switch(prompt_int_min_max("Enter menu option: ", 1, 5)) {
            case 1:
                // Manage the users
                manageUsers(users);
                break;
            case 2:
                // Pick a user
                cardHolder = prompt_string("Enter card holder of user: ");
                if (!findUser(cardHolder, users, user, index)) {
                    cout << "No user exists with cardholder name " << cardHolder << "." << endl;
                    break;
                }
                // Display their bill
                user.displayBill();
                break;
            case 3:
                // Exit the program
                running = false;
                break;
        }
    }

    cout << "\nHave a good day!";

    // Save users to file
    save_to_file(users);
    return 0;
}
