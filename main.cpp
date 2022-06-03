#include <iostream>

#include "console.h"
#include "file_manager.h"
#include "User.h"

using namespace std;

// My function to find the user in the list.
bool customFind(vector<User> vect, string key, int& location) {

    // If the key entered is X, we don't need to run this program, so we just leave.
    if (key == "x" || key == "X") {
        return false;
    }

    // Loop through the vector, checking each name value.
    for (int i = 0; i <= vect.size()-1; i++) {
        //cout << "At row " << i << ", there is " << vect[i][0] << "\n\n";
        // If key found, print as such, leave the function.
        if (vect[i]->cardHolder == key) {
            location = i;
            cout << "User Found!\n";
            return false;
        }
    }
    // If key not found, print as such, and leave.
    cout << "User not found.\n\n";
    return true;
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
            << "1) Add user" << endl
            << "2) Remove user" << endl
            << "3) Edit user" << endl
            << "4) Display user's bill" << endl
            << "5) Exit program" << endl;

        switch(prompt_int_min_max("Enter menu option: ", 1, 5)) {
            case 1:
                // TODO: Add user
            case 2:
                // TODO: Remove user
                break;
            case 3:
                // Get location in vector of user, run edit.
                do {
                    strPrompt = prompt_string("Please enter the name of the card holder : ");
                } while (customFind(users, strPrompt, location));
                users[location].edit();
                break;
            case 4:
                // Get location in vector of user, run display.
                do {
                    strPrompt = prompt_string("Please enter the name of the card holder: ");
                } while (customFind(users, strPrompt, location));
                users[location].displayBill();
                break;
            case 5:
                running = false;
                break;
        }
    }

    save_to_file(users);
    return 0;
}
