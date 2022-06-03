#include <iostream>

#include "console.h"
#include "file_manager.h"
#include "User.h"

using namespace std;

int main() {
    vector<User> users = load_from_file();

    bool running = true;
    while (running) {
        cout << "Welcome to the Alamo Car Renting Service! How may we help you today?" << endl
            << "1) Add, remove, or edit user(s)" << endl
            << "2) Choose a different car" << endl
            << "3) Add or remove services" << endl
            << "4) Display user's bill" << endl
            << "5) Exit program" << endl;

        switch(prompt_int_min_max("Enter menu option: ", 1, 5)) {
            case 1:
                users.push_back(createUser());
                break;
            case 2:
                // TODO: Choose car
                break;
            case 3:
                // TODO: Add/remove services
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

