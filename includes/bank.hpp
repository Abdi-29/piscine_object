#ifndef BANK
#define BANK

#include <iostream>
#include <map>
#include "account.hpp"

class Bank {
private:
    int _liquidity;
    std::map<int, Account> _clientAccount;

public:
    static int id_generator;

public:
    Bank();
    Bank(int liquidity);
    ~Bank();

    static Account create_account(int id);
    int make_account();
    int get_liquidity() const;
    std::map<int, Account> get_client_account() const;

    void set_client_account(Account account);
    void set_liquidity(int liquidity);
    void deposit(int id, int amount);
};

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);

#endif