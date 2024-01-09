#include "../includes/bank.hpp"

//https://stackoverflow.com/questions/61518284/error-non-const-static-data-member-must-be-initialized-out-of-line
int Bank::id_generator = 0;

Bank::Bank(): _liquidity(0) {
    std::cout << "HELLO FROM BANK\n";
}

Bank::Bank(int liquidity): _liquidity(liquidity) {}

int Bank::get_liquidity() const {
    return this->_liquidity;
}

std::map<int, Account> Bank::get_client_account() const {
    return this->_clientAccount;
}

void Bank::set_client_account(Account account) {
    this->_clientAccount.insert(std::make_pair(account.get_id(), account));
}

int Bank::make_account() {
    std::cout << "-------------------CREATING ACCOUNT-------------------" << std::endl;
    Account account = create_account(id_generator);
    set_client_account(account);
    id_generator++;
    return account.get_id();
}

void Bank::deposit(int id, int amount) {
    auto account = get_client_account().find(id);
    std::cout << "-------------------DEPOSITING-------------------" << std::endl;
    if (account == get_client_account().end()) {
        throw std::runtime_error("Account is not yet created\n"); //TODO try to use std::cerr instead
    }
    int inflow = amount * 0.05;
    int after_tax = amount - inflow;
    account->second.set_value(account->second.get_value() + after_tax);
    this->_liquidity += inflow;
    std::cout << "TEST: " << account->second.get_value() << std::endl;
}

void Bank::withdraw(int id, int amount) {
    auto account = get_client_account().find(id);
    if (account == get_client_account().end()) {
        std::cerr << "Not found account with id: " << id << std::endl;
        return;
    }
    if (amount > account->second.get_value()) {
        std::cerr << "You don't have enough money to withdraw" << std::endl;
        return;
    }
    account->second.set_value(account->second.get_value() - amount);
}

void Bank::delete_account(int id) {
    auto account = get_client_account().find(id);
    if (account == get_client_account().end()) {
        std::cerr << "Not found account with id: " << id << std::endl;
        return;
    }
    this->_clientAccount.erase(account);
}

void Bank::take_loan(int id, int amount) {
    auto account = get_client_account().find(id);
    if (account == get_client_account().end()) {
        std::cerr << "Not found account with id: " << id << std::endl;
        return;
    }
    if (amount <= 0) {
        std::cerr << "Loan can't be 0 or negative" << std::endl;
        return;
    }

}

Bank::~Bank() {
    std::cout << "BYE BYE FROM BANK\n";
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
    p_os << "Bank information's : " << std::endl;
    p_os << "Liquidity : " << p_bank.get_liquidity() << std::endl;
    for (auto& [id, client] : p_bank.get_client_account())
        p_os << id << client.get_value() << std::endl;
    return (p_os);
}