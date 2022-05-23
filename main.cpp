#include <iostream>

#include "User.h"
#include "console.h"

using namespace std;

int main() {
    // TODO: Create user
    auto user = new User(
            prompt_string("Please enter the name of the credit card holder: "),
            prompt_string("Please enter the address of the credit card holder: "),
            prompt_int_min("Please enter the number of members in your group: ", 1),
            prompt_string("Please enter the emergency contact details: "),
            prompt_int_min("Please enter the number of days this car will be rented out for: ", 1)
    );

    return 0;
}