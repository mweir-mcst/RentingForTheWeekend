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

User* createUser() {
    string cardHolder = prompt_string("Please enter the name of the credit card holder: ");
    string address = prompt_string("Please enter the address of the credit card holder: ");
    int memberCount = prompt_int_min("Please enter the number of members in your group: ", 1);
    string emergencyContact = prompt_string("Please enter the emergency contact details: ");
    int rentalDays = prompt_int_min("Please enter the number of days this car will be rented out for: ", 1);

    cout << "What kind of car would you like?" << endl
        << "1) Nissan Altima ($800)" << endl
        << "2) Ferrari ($5000)" << endl
        << "3) Subaru Forester ($1200)" << endl;

    int carChoice = prompt_int_min_max("Please enter your vehicle of choice by inputting the number next to your choice: ", 1, 3);

    string roadsideAssistanceChoice = prompt_string_choices("Would you like roadside assistance? (y/n) ", {"Y", "y", "N", "n"});
    string gasFillCoverage = prompt_string_choices("Would you like gas fill coverage? (y/n) ", {"Y", "y", "N", "n"});
    string driverFaultCoverage = prompt_string_choices("Would you like driver fault coverage? (y/n) ", {"Y", "y", "N", "n"});

    return new User(
            cardHolder,
            address,
            memberCount,
            emergencyContact,
            rentalDays,
            carChoice,
            roadsideAssistanceChoice == "Y" || roadsideAssistanceChoice == "y",
            gasFillCoverage == "Y" || gasFillCoverage == "y",
            driverFaultCoverage == "Y" || driverFaultCoverage == "y"
    );
}

User* displayBill(User a) {
    cout << "Card Holder: " << a.cardHolder << endl
         << "Address: " << a.address << endl
         << "Amount of group members: " << a.memberCount << ". Cost (20 * Member Count):  $" << a.memberCount * 20 << endl
         << "Emergency Contact Details: " << a.emergencyContact << endl
         << "Length of Rental in Days: " << a.rentalDays << ". Cost (75 * Rental Days): $" << a.rentalDays * 75 << endl
         << "a";
}