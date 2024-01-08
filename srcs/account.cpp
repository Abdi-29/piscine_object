#include "../includes/account.hpp"
#include "../includes/bank.hpp"

//Account::Account() {
//    std::cout << "HELLO\n";
//}
//
//Account::Account(int id, int value): _id(id), _value(value) {}

int Account::get_id() const {
    return this->_id;
}

int Account::get_value() const {
    return this->_value;
}

void Account::set_id(int id) {
    this->_id = id;
}

void Account::set_value(int value) {
    this->_value = value;
}

Account Bank::create_account(int id) {
    Account account = Account();
    account.set_id(id);
    return account;
}

std::ostream& operator << (std::ostream& p_os, const Account& p_account) {
    p_os << "[" << p_account.get_id() << "] - [" << p_account.get_value() << "]";
    return (p_os);
}