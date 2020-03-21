#ifndef _TRUST_ACCOUNT_H_
#define _TRUST_ACCOUNT_H_


# include "Savings_Account.h"
class Trust_Account: public Savings_Account{
    friend std::ostream & operator<<(std::ostream &os, Trust_Account &account);
private:
    static constexpr const char * def_name = "Unnamed Trust Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;
    static constexpr double deposit_bonus = 50;
    static constexpr double deposit_min_for_bonus = 5000;
    static constexpr int max_withdraw_times = 3;    
    static constexpr double max_withdraw_percent = 0.2;
    int withdraw_times;
public:
    Trust_Account(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
//    ~Trust_Account();
    bool deposit(double amount);
    bool withdraw(double amount);

};

#endif // _TRUST_ACCOUNT_H_
