#include "../includes/bank.hpp"

//https://stackoverflow.com/questions/61518284/error-non-const-static-data-member-must-be-initialized-out-of-line
int Bank::id_generator = 0;

Bank::Bank() {
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
    Account account = create_account(id_generator);
    set_client_account(account);
    id_generator++;
    return account.get_id();
}

void Bank::deposit(int id, int amount) {
    std::map<int, Account>::iterator account = get_client_account().find(id);

    if (account == get_client_account().end()) {
        throw std::runtime_error("Account is not yet created\n");
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