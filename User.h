#ifndef RENTINGFORTHEWEEKEND_USER_H
#define RENTINGFORTHEWEEKEND_USER_H

#include <string>

using namespace std;

class User {
public:
    string address, emergencyContact, cardHolder;
    int memberCount, rentalDays, vehicle;
    bool roadsideAssitance, gasFillCoverage, driverFaultCoverage;

    User(string, string, int, string, int, string, bool, bool, bool);
};

User* createUser();

#endif