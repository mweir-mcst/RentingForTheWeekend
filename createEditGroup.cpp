//
// Created by SolveForX24 on 5/23/2022.
//

#include "console.h";
using namespace std;

void createGroup() {
    string prompt = prompt_string("Please enter the name of the credit card holder: ");
    // add to structure
    prompt = prompt_string("Please enter the address of the credit card holder: ");
    // add to structure
    int promptInt = prompt_int_min("Please enter the number of members in the group: ", 1);
    // add to structure
    prompt = prompt_string("Please enter the emergency contact details: ");
    // add to structure
    promptInt = prompt_int_min("Please enter the number of days this car will be rented out for: ", 1);
    // add to structure

    // return structure
}