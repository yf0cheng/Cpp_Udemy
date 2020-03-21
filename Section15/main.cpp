/*
// Section 15 Challenge
// Inheritance

You are provided with a simple Account class hierarchy that contains
Account - Base class
Savings Account - Derived class

An Account has a name and a balance.
A Savings Account is an Account and adds an interest rate.

I have also provided some Account helper functions in Account_Util.h and Account_Util.cpp
that make it easy to display, deposit to, and withdraw from a vector of Accounts and Savings Accounts.

Please refer to the source code provided and the video explanation of this challenge for more details.

Your challenge is the following:

1. Add a Checking account class to the Account hierarchy
    A Checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction.
    Every withdrawal transaction will be assessed this flat fee.

2. Add a Trust account class to the Account hierarchy
    A Trust account has a name, a balance, and an interest rate
    The Trust account deposit works just like a savings account deposit.
    However, any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account.
    
    The Trust account withdrawal should only allow 3 withdrawals per year and each of these must be less than 20% of the account balance.
    You don't have to keep track of calendar time for this application, just make sure the 4th withdrawal fails :)
    
Hints: 
    Reuse existing functionality!!
    Think about what the Base class will be for the new classes.
    Add helper functions to Account_Util.h and Account_Util.cpp if you wish to work with your new classes.
    (You don't have to, but it will make your main much easier to use)
    
Have fun!!  You are no longer beginner C++ programmers!

If you want more practice with operator overloading you can overload += and -= for deposit and withdrawal :)

*/
// Section 15
// Challenge 
#include <iostream>
#include <vector>
#include "Savings_Account.h"
#include "Account_Util.h"
#include "Checking_Account.h"
#include "Trust_Account.h"

using namespace std;

int main() {
    cout.precision(2);
    cout << fixed;
   
    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account {});
    accounts.push_back(Account {"Larry"});
    accounts.push_back(Account {"Moe", 2000} );
    accounts.push_back(Account {"Curly", 5000} );
    
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts,2000);
    
    // Savings 

    vector<Savings_Account> sav_accounts;
    sav_accounts.push_back(Savings_Account {} );
    sav_accounts.push_back(Savings_Account {"Superman"} );
    sav_accounts.push_back(Savings_Account {"Batman", 2000} );
    sav_accounts.push_back(Savings_Account {"Wonderwoman", 5000, 5.0} );

    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
    
    // Checking Accounts
    vector<Checking_Account> chk_accounts;
    chk_accounts.push_back(Checking_Account {});
    chk_accounts.push_back(Checking_Account {"AAA"});
    chk_accounts.push_back(Checking_Account {"BBB", 2000} );
    chk_accounts.push_back(Checking_Account {"CCC", 5000} );
    
    display(chk_accounts);
    deposit(chk_accounts, 1000);
    withdraw(chk_accounts,2000);
    
    
    // Trust 

    vector<Trust_Account> trs_accounts;
    trs_accounts.push_back(Trust_Account {} );
    trs_accounts.push_back(Trust_Account {"Superwoman"} );
    trs_accounts.push_back(Trust_Account {"Batwoman", 2000} );
    trs_accounts.push_back(Trust_Account {"Wonderman", 5000, 5.0} );

    display(trs_accounts);
    deposit(trs_accounts, 1000);
    deposit(trs_accounts, 5000);
    withdraw(trs_accounts, 6000);
    withdraw(trs_accounts, 200);
    withdraw(trs_accounts, 200);
    withdraw(trs_accounts, 200);
    withdraw(trs_accounts, 200);
    return 0;
}

