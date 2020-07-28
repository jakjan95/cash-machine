#pragma once
#include <iostream>
#include <memory>

#include "Account.hpp"

class CashMachine {
public:
    ~CashMachine() = default;
    CashMachine(std::unique_ptr<Account> user, size_t cashAmount)
        : user_{std::move(user)}, cashAmount_{cashAmount} {}

    enum class Action {
        Exit = 0,
        GetBalance,
        Withdraw,
        Deposit,
    };

    void deposit() {
        size_t amountToDeposit;
        std::cout << "Enter amount to deposit: ";
        std::cin >> amountToDeposit;

        user_->depositMoney(amountToDeposit);
        cashAmount_ += amountToDeposit;
        std::cout << "action sucesfully\n";
    }

    void withdraw() {
        size_t amountToWithdraw;
        std::cout << "Enter amount to withdraw: ";
        std::cin >> amountToWithdraw;

        if (cashAmount_ > amountToWithdraw && user_->canWithdraw(amountToWithdraw)) {
            user_->withdrawMoney(amountToWithdraw);
            cashAmount_ -= amountToWithdraw;
            std::cout << "action sucesfully\n";
        }
    }

    void getBalance() const {
        std::cout << "You have got: " << user_->getBalance() << "$\n;";
    }

    void printMenu() const {
        std::cout << "*** MENU ***\n"
                  << "1 - balance\n"
                  << "2 - withdraw\n"
                  << "3 - deposit\n"
                  << "0 - exit\n";
    }

    void exit() {
        std::cout << "Exit\n";
        std::exit(0);
    }

    void makeAction(Action action) {
        switch (action) {
        case Action::Exit:
            exit();
            break;
        case Action::Withdraw:
            withdraw();
            break;
        case Action::Deposit:
            deposit();
            break;
        case Action::GetBalance:
            getBalance();
            break;
        }
    }

    void mainLoop() {
        std::cout << " ATM \n";
        while (true) {
            printMenu();
            std::cout << "Enter option ... ";
            size_t option;
            std::cin.clear();
            std::cin >> option;
            makeAction(static_cast<Action>(option));
        }
        exit();
    }

private:
    std::unique_ptr<Account> user_;
    size_t cashAmount_;
};
