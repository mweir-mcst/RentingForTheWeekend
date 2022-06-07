#include <iostream>
#include <string>

#include "User.h"
#include "console.h"

using namespace std;

// Initialize a user
User::User(const string& newCardHolder, const string& newAddress, const int newMemberCount, const string& newEmergencyContact, const int newRentalDays, const int newVehicle, const bool newRoadsideAssistance, const bool newGasFillCoverage, const bool newDriverFaultCoverage) {
    address = newAddress;
    emergencyContact = newEmergencyContact;
    cardHolder = newCardHolder;
    memberCount = newMemberCount;
    rentalDays = newRentalDays;
    vehicle = newVehicle;
    roadsideAssistance = newRoadsideAssistance;
    gasFillCoverage = newGasFillCoverage;
    driverFaultCoverage = newDriverFaultCoverage;
}

void User::edit() {

    cout << "We will go through and replace info.\n";
    // Prompt the user for the basic info
    cardHolder = prompt_string("Please enter the name of the credit card holder: ");
    address = prompt_string("Please enter the address of the credit card holder: ");
    memberCount = prompt_int_min("Please enter the number of members in your group: ", 1);
    emergencyContact = prompt_string("Please enter the emergency contact details: ");
    rentalDays = prompt_int_min("Please enter the number of days this car will be rented out for: ", 1);

    // Use the member count to recommend a car
    cout << "Based on the number of members in your group, we recommend the ";
    if (memberCount <= 2) {
        cout << "Nissan Altima ($800)";
        vehicle = 1;
    } else if (memberCount <= 4) {
        cout << "Ferrari ($5000)";
        vehicle = 2;
    } else {
        cout << "Subaru Forester ($1200)";
        vehicle = 3;
    }
    cout << "." << endl;

    string wantsRecommended = prompt_string_choices("Would you like this car? (y/n) ", {"Y", "y", "N", "n"});

    // If they don't want the recommended car, give them the list of cars to pick from
    if (wantsRecommended == "N" || wantsRecommended == "n") {
        cout << "What kind of car would you like?" << endl
             << "1) Nissan Altima ($800)" << endl
             << "2) Ferrari ($5000)" << endl
             << "3) Subaru Forester ($1200)" << endl;

        vehicle = prompt_int_min_max("Please enter your vehicle of choice by inputting the number next to your choice: ", 1, 3);
    }

    // Prompt the user for insurances / services
    string roadsideAssistanceChoice = prompt_string_choices("Would you like roadside assistance? (y/n) ", {"Y", "y", "N", "n"});
    string gasFillCoverageChoice = prompt_string_choices("Would you like gas fill coverage? (y/n) ", {"Y", "y", "N", "n"});
    string driverFaultCoverageChoice = prompt_string_choices("Would you like driver fault coverage? (y/n) ", {"Y", "y", "N", "n"});

    roadsideAssistance = roadsideAssistanceChoice == "Y" || roadsideAssistanceChoice == "y";
    gasFillCoverage = gasFillCoverageChoice == "Y" || gasFillCoverageChoice == "y";
    driverFaultCoverage = driverFaultCoverageChoice == "Y" || driverFaultCoverageChoice == "y";
}

void User::displayBill() const {

    // Total cost
    int cost = 0;

    // Display basics
    cout << "Card Holder: " << cardHolder << endl
         << "Address: " << address << endl
         << "Amount of group members: " << memberCount << ". Cost (20 * Member Count):  $" << memberCount * 20 << endl
         << "Emergency Contact Details: " << emergencyContact << endl
         << "Length of Rental in Days: " << rentalDays << ". Cost (75 * Rental Days): $" << rentalDays * 75 << endl
         << "Current Vehicle: ";

    // Add to cost
    cost += memberCount * 20;
    cost += rentalDays * 75;

    // Prints price of selected vehicle
    switch(vehicle) {
        case 1:
            cout << "Nissan Altima. Cost: $800" << endl;
            cost += 800;
            break;
        case 2:
            cout << "Ferrari. Cost: $5000" << endl;
            cost += 5000;
            break;
        case 3:
            cout << "Subaru Forester. Cost: $1200" << endl;
            cost += 1200;
            break;
        default:
            cout << "Something has gone wrong, and we cannot retrieve your vehicle of choice.";
    }

    // Various coverages
    if (roadsideAssistance) {
        cout << "Roadside Assistance: $150" << endl;
        cost += 150;
    }
    if (gasFillCoverage) {
        cout << "Gas Fill Coverage: $150" << endl;
        cost += 150;
    }
    if (driverFaultCoverage) {
        cout << "Driver Fault Coverage: $150" << endl;
        cost += 150;
    }

    // Final Cost
    cout << "Final Bill: $" << cost << endl;
}

User createUser() {
    // Create a new user and immediately edit it
    User user;
    user.edit();
    return user;
}

bool findUser(const string& cardHolder, vector<User>& users, User& user, int& index) {
    // Loop through the users until it finds one
    for (int i = 0; i < users.size(); i++) if (users[i].cardHolder == cardHolder) {
        user = users[i];
        index = i;
        return true;
    }
    return false;
}