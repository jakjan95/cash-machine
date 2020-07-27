#include <iostream>

int main() {
    //Login interface:
    std::string userLogin = "1111";
    std::string userPin = "1111";

    std::string enteredLogin = "1111";
    std::string enteredPin = "1111";

    std::cout << "*** Cash Mashine ***\n";
    std::cout << "Enter login: ";
    std::cin >> enteredLogin;
    std::cout << "Enter pin: ";
    std::cin >> enteredPin;

    std::cout << "You login in!\n";

    //Money managment
    int balance = 1000;
    while (true) {
        std::cout << "1-balance \n2-withdraw \n3-deposit\n4-exit\n";
        char option;
        std::cin >> option;
        switch (option) {
        case '1':
            std::cout << "Your balance is: " << balance << "$\n";
            break;
        case '2':
            int amountToWithdraw;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amountToWithdraw;
            balance -= amountToWithdraw;
            std::cout << "Your balance after withdraw is: " << balance << "$\n";
            break;
        case '3':
            int amountToDeposit;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amountToDeposit;
            balance += amountToDeposit;
            std::cout << "Your balance after deposit is: " << balance << "$\n";
            break;
        case '4':
            std::cout<<"Goodbye!\n";
            exit(0);
            break;
        default:
            std::cout << "Wrong option";
        }
    }

    return 0;
}
