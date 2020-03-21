/*
Section 20
Challenge 1 - Deque Challenge

A Palindrome is a string that reads the same backwards or forwards.
Simple examples are:
madam
bob
toot
radar

An entire phrase can also be a palindome, for example:
A Toyota's a toyota
A Santa at NASA
A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!

For the purposes of this assignment we will only consider alpha characters and omit all other characters.
We will also not be considering case.
So,
A Santa at Nasa, will be processed as:
ASANTAATNASA

A common method to solve this problem is to compare the string to its reverse and
if the are equal then it must be a palindrome. But we will use a deque.

I am providing the main driver for you which will automatically run several test cases.
You challenge is to write the following function:

bool is_palindrome(const std::string &s) {

This function will expect a string and it must determine if that string is a palindrome and return true if it is, or false if it is not.

So,

is_palindrome("A Santa at Nasa");   will return true 
is_palindrome("Hello");   will return false

Please use a deque to solve the problem.
Good luck and have fun!
*/
// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

template <typename T>
void display(std::deque<T> &d){
    for (auto &c:d)
        std::cout << c << " " ;
}


bool is_palindrome(const std::string& s)
{
    std::deque<char> Toback;
    std::deque<char> Tofront;
//    std::copy(s.begin(),s.end(),Tofront.begin(), ::toupper);
//    std::string alphabat {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    for (auto c: s){
        if ( std::isalpha(c) ){
            Toback.push_back(std::toupper(c));
            Tofront.push_front(std::toupper(c));
        }
    }

    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    return Toback==Tofront;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}