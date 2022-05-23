#ifndef RENTINGFORTHEWEEKEND_USER_H
#define RENTINGFORTHEWEEKEND_USER_H

#include <string>

using namespace std;

class User {
public:
    string address, emergencyContact, cardHolder;
    int memberCount, rentalDays;

    User(string, string, int, string, int);
    static User createUser();
};

#endif