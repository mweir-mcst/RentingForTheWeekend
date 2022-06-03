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
    void editUser(const string&, const string&, int, const string&, int, int, bool, bool, bool);
};

User* createUser();
User* displayBill(User);

#endif