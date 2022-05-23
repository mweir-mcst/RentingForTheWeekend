#ifndef RENTINGFORTHEWEEKEND_USER_H
#define RENTINGFORTHEWEEKEND_USER_H

#include <string>

using namespace std;

class User {
public:
    string address, emergencyContact, cardHolder;
    int memberCount, rentalDays;

    User(const string&, const string&, const string&, int, int);
    static User createUser();
};

#endif