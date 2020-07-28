#pragma once
#include <string>

class Account {
public:
    ~Account() = default;
    Account(const std::string& cardNumber, const std::string& pin, size_t balance)
        : cardNumber_{cardNumber}, pin_{pin}, balance_{balance} {}

    size_t getBalance() const {
        return balance_;
    }

    void withdrawMoney(size_t amount) {
        if (canWithdraw(amount)) {
            balance_ -= amount;
        }
    }

    void depositMoney(size_t amount) {
        balance_ += amount;
    }

    bool canWithdraw(size_t amount) const {
        return amount < balance_;
    }

private:
    std::string cardNumber_;
    std::string pin_;
    size_t balance_;
    //withdrawlimit?
};
