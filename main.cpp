#include <iostream>

#include "console.h"
#include "file_manager.h"
#include "User.h"

using namespace std;

// My function to find the user in the list.
bool customFind(vector<User*> vect, string key) {


    // Loop through the vector, checking each value in each row and the first column.
    for (int i = 0; i <= vect.size()-1; i++) {
        //cout << "At row " << i << ", there is " << vect[i][0] << "\n\n";
        // If key found, print as such,leave the function.
        if (vect[i]->cardHolder == key) {
            cout << "User Found!\n";
            return false;
        }
    }
    // If key not found, print as such, and leave.
    cout << "User not found.\n\n";
    return true;
}


int main() {
    vector<User> users = load_from_file();

    bool running = true;

    string strPrompt;

    int choice;

    while (running) {
        cout << "Welcome to the Alamo Car Renting Service! How may we help you today?" << endl
            << "1) Add, remove, or edit user(s)" << endl
            << "2) Choose a different car" << endl
            << "3) Add or remove services" << endl
            << "4) Display user's bill" << endl
            << "5) Exit program" << endl;

        switch(prompt_int_min_max("Enter menu option: ", 1, 5)) {
            case 1:
                // TODO: Add user
            case 2:
                // TODO: Choose car
                break;
            case 3:
                do {
                    strPrompt = prompt_string("Please enter the name of the card holder: ");
                } while (customFind(users, strPrompt));
                break;
            case 4:
                // TODO: Display bill
                break;
            case 5:
                running = false;
                break;
        }
    }

    save_to_file(users);
    return 0;
}
