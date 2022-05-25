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
    return new User(
            prompt_string("Please enter the name of the credit card holder: "),
            prompt_string("Please enter the address of the credit card holder: "),
            prompt_int_min("Please enter the number of members in your group: ", 1),
            prompt_string("Please enter the emergency contact details: "),
            prompt_int_min("Please enter the number of days this car will be rented out for: ", 1);
            prompt_int_min_max("What kind of car would you like?\n1) Nissan Altima ($800)\n2) Ferrari ($5000)\n3) Subaru Forester ($1200)\nPlease enter your vehicle of choice by inputting the number next to your choice: ", 1, 3);
    );
}