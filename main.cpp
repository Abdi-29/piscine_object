#include "includes/bank.hpp"

int main() {
    Bank bank;

    int account1 = bank.make_account();
    int account2 = bank.make_account();

    bank.deposit(account1, 4000);
    std::cout << bank;
    return 0;
}
