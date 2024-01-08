#ifndef ACCOUNT
#define ACCOUNT

#include <iostream>

class Account {
private:
    int _id;
    int _value;

public:
//    Account();
//    Account(int id, int value);

    int get_id() const;
    int get_value() const;

    void set_id(int id);
    void set_value(int value);
};

std::ostream& operator << (std::ostream& p_os, const Account& p_account);

#endif