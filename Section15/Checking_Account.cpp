#include "Checking_Account.h"

std::ostream& operator<<(std::ostream &os, const Checking_Account &account){
    os << "[Checking_Account: " << account.name << ": " << account.balance << ", withdraw rate $" <<account.withdraw_fee << "]";
    return os;
}

Checking_Account::Checking_Account(std::string name, double balance)
: Account(name, balance){
}

bool Checking_Account::withdraw(double amount){
    amount = amount + withdraw_fee;
    return Account::withdraw(amount);
}

