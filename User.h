#ifndef RENTINGFORTHEWEEKEND_USER_H
#define RENTINGFORTHEWEEKEND_USER_H

#include <string>

using namespace std;

class User {
public:
    string address, emergencyContact, cardHolder;
    int memberCount, rentalDays, vehicle;
    bool roadsideAssistance, gasFillCoverage, driverFaultCoverage;

    User(const string&, const string&, int, const string&, int, int, bool, bool, bool);
    User() = default;

    void edit();
};

User createUser();

#endif