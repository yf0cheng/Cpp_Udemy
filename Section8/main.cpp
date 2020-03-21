// Section 8 Challenge
/*
	For this program I will be using US dollars and cents.
	
    Write a program that asks the user to enter the following:
	An integer representing the number of cents 
    	
	You may assume that the number of cents entered is greater than or equal to zero
    
	The program should then display how to provide that change to the user.
	
	In the US:
		1 dollar is 100 cents
		1 quarter is 25 cents
		1 dime is 10 cents
		1 nickel is 5 cents, and
		1 penny is 1 cent.
		
	Here is a sample run:
	
	Enter an amount in cents :  92
	
	You can provide this change as follows:
	dollars    : 0
	quarters : 3
	dimes     : 1
	nickels   : 1
	pennies  : 2
	
	Feel free to use your own currency system.
	Also, think of how you might solve the problem using the modulo operator.

	Have fun and test your program!!

*/
#include <iostream>

using namespace std;

int main() {

    cout << "Enter an amount in cents :  ";
    int cents {};
    cin >> cents;
    
    int dollars {};
    dollars = cents / 100;
    cents = cents - dollars*100;
    cout << "dollars    : " << dollars << endl;
    
    int quarters {};
    quarters = cents / 25;
    cents = cents - quarters*25;
    cout << "quarters    : " << quarters << endl;
    
    int dimes {};
    dimes = cents / 10;
    cents = cents - dimes*10;
    cout << "dimes    : " << dimes << endl;
    
    int nickels {};
    nickels = cents / 5;
    cents = cents - nickels*5;
    cout << "nickels    : " << nickels << endl;

    cout << "pennies    : " << cents << endl;
    
    cout << endl;
    return 0;
}


