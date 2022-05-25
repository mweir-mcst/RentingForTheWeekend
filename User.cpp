#include "User.h"
#include "console.h"

using namespace std;

User::User(const string& newCardHolder, const string& newAddress, const int newMemberCount, const string& newEmergencyContact, const int newRentalDays) {
    address = newAddress;
    emergencyContact = newEmergencyContact;
    cardHolder = newCardHolder;
    memberCount = newMemberCount;
    rentalDays = newRentalDays;
}