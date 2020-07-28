#include <iostream>

#include "Account.hpp"
#include "CashMachine.hpp"

int main() {
    Account firstUser("1111", "1111", 5000);
    CashMachine firstATM(std::make_unique<Account>(firstUser), 50000);
    firstATM.mainLoop();

    return 0;
}
