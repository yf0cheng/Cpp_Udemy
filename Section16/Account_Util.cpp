#include <iostream>
#include "Account_Util.h"

void display(const std::vector<Account *> &accounts){
    for (const auto a:accounts){
        std::cout << *a << std::endl;
    }
}

void deposit(std::vector<Account *> &accounts, double amount){
    for (const auto a:accounts){
        if (a->deposit(amount))
            std::cout << "Deposited " << amount << " to " << *a << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << *a << std::endl;   
    }

}
void withdraw(std::vector<Account *> &accounts, double amount){
    for (const auto a:accounts){
        if (a->withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << *a << std::endl;
        else
            std::cout << "Failed Withdrew of " << amount << " from " << *a << std::endl;   
    }
}

