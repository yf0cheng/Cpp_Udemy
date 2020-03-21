/*
Section 18
Challenge
/***********************************************************************************************************
For this challenge we want to integrate our own user-defined exception classes into the Account class
hierarchy.

The account classes are provided for you.
Also, the IllegalBalanceException.h file contains the declaration for the IllegalBalanceException class.

What I would like you to do is:
1. Derive IllegalBalanceException from std::exception and implement the what() method to provide an exception message.
   This exception object should be thrown from the Account class constructor if an account object is created with a negative 
   balance.
   
2. Derive InsufficentFundsException from std::exception and implement the what() method to provide an exception message.
   This exception object should be thrown if a withdraw results in a negative balance.
   You should throw this exception object from the Account withdraw method.
   
That's it - good luck!
Test your code in the main driver.

Have fun and experiment!
*/
#include <iostream>
#include <memory>
#include "Account.h"
#include "Checking_Account.h"
#include "Savings_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"

using namespace std;

int main() {
    try{
        std::unique_ptr <Account> Joes_account = std::make_unique<Checking_Account>("Joe",100);
        std::cout << "Use Joe's account" << std::endl;
        Joes_account->withdraw(150);
        std::cout << "withdraw successfully" << std::endl;
    }
    catch(const IllegalBalanceException &ex){
        std::cerr << ex.what() << std::endl;
    }
    catch(const InsufficentFundsException &ex){
        std::cerr << ex.what() << std::endl;
    }
    // test your code here
    std::cout << "Program completed successfully" << std::endl;
    return 0;
}

