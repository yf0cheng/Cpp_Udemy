#include "Trust_Account.h"

std::ostream & operator<<(std::ostream &os, Trust_Account &account){
    os << "[Trust Account: " << account.name << ":" << account.balance << ", " << account.int_rate << "%]";
    return os;
}

Trust_Account::Trust_Account(std::string name, double balance, double int_rate)
: Savings_Account(name, balance, int_rate), withdraw_times(0){
}

virtual bool Trust_Account::deposit(double amount) override{
    if (amount >= deposit_min_for_bonus){
        Account::deposit(deposit_bonus);
        std::cout << "bonus " << deposit_bonus << std::endl;
    }
    return Savings_Account::deposit(amount);    
}

virtual bool Trust_Account::withdraw(double amount) override{
    if (withdraw_times >= max_withdraw_times){
        std:: cout << "Trust account only allows 3 withdraws." << std:: endl;
        return false;
    }else if (amount > balance*max_withdraw_percent){
        std:: cout << "exceed" << max_withdraw_percent*100 << "% of balance" << std:: endl;
        return false;
    }else{
        withdraw_times +=1;
        std:: cout << "withdraw times:" << withdraw_times<< std::endl;
        return Savings_Account::withdraw(amount);
    }
        
}
