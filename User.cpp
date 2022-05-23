#include "User.h"

using namespace std;

User::User(const string& newAddress, const string& newEmergencyContact, const string& newCardHolder, const int newMemberCount, const int newRentalDays) {
    address = newAddress;
    emergencyContact = newEmergencyContact;
    cardHolder = newCardHolder;
    memberCount = newMemberCount;
    rentalDays = newRentalDays;
}

User User::createUser() {

}