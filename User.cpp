#include <iostream>
#include <string>

#include "User.h"
#include "console.h"

using namespace std;

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
    cardHolder = prompt_string("Please enter the name of the credit card holder: ");
    address = prompt_string("Please enter the address of the credit card holder: ");
    memberCount = prompt_int_min("Please enter the number of members in your group: ", 1);
    emergencyContact = prompt_string("Please enter the emergency contact details: ");
    rentalDays = prompt_int_min("Please enter the number of days this car will be rented out for: ", 1);

    cout << "What kind of car would you like?" << endl
        << "1) Nissan Altima ($800)" << endl
        << "2) Ferrari ($5000)" << endl
        << "3) Subaru Forester ($1200)" << endl;

    vehicle = prompt_int_min_max("Please enter your vehicle of choice by inputting the number next to your choice: ", 1, 3);

    string roadsideAssistanceChoice = prompt_string_choices("Would you like roadside assistance? (y/n) ", {"Y", "y", "N", "n"});
    string gasFillCoverageChoice = prompt_string_choices("Would you like gas fill coverage? (y/n) ", {"Y", "y", "N", "n"});
    string driverFaultCoverageChoice = prompt_string_choices("Would you like driver fault coverage? (y/n) ", {"Y", "y", "N", "n"});

    roadsideAssistance = roadsideAssistanceChoice == "Y" || roadsideAssistanceChoice == "y";
    gasFillCoverage = gasFillCoverageChoice == "Y" || gasFillCoverageChoice == "y";
    driverFaultCoverage = driverFaultCoverageChoice == "Y" || driverFaultCoverageChoice == "y";
}

void User::displayBill() {
    cout << "Card Holder: " << cardHolder << endl
         << "Address: " << address << endl
         << "Amount of group members: " << memberCount << ". Cost (20 * Member Count):  $" << memberCount * 20 << endl
         << "Emergency Contact Details: " << emergencyContact << endl
         << "Length of Rental in Days: " << rentalDays << ". Cost (75 * Rental Days): $" << rentalDays * 75 << endl
         << "a";
}

User createUser() {
    User user;
    user.edit();
    return user;
}