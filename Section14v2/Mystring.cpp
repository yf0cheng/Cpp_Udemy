#include <iostream>
#include <cstring>
#include "Mystring.h"

 // No-args constructor
Mystring::Mystring() 
    : str{nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) 
    : str {nullptr} {
        if (s==nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[strlen(s)+1];
            strcpy(str, s);
        }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[strlen(source.str)+ 1];
        strcpy(str, source.str);
 //       std::cout << "Copy constructor used" << std::endl;

}

// Move constructor
Mystring::Mystring( Mystring &&source) 
    :str(source.str) {
        source.str = nullptr;
//        std::cout << "Move constructor used" << std::endl;
}

 // Destructor
Mystring::~Mystring() {
    delete [] str;
}

 // Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
//    std::cout << "Using copy assignment" << std::endl;

    if (this == &rhs) 
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=( Mystring &&rhs) {
 //   std::cout << "Using move assignment" << std::endl;
    if (this == &rhs) 
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}


// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &in, Mystring &rhs) {
    char *buff = new char[1000];
    in >> buff;
    rhs = Mystring{buff};
    delete [] buff;
    return in;
}

// overloaded ==
bool operator==(const Mystring &lhs, const Mystring &rhs){
    return (std::strcmp(lhs.str, rhs.str)==0);
}
bool operator!=(const Mystring &lhs, const Mystring &rhs){
    return (std::strcmp(lhs.str, rhs.str)!=0);
}
bool operator<(const Mystring &lhs, const Mystring &rhs){
    return (std::strcmp(lhs.str, rhs.str)<0);
}
bool operator>(const Mystring &lhs, const Mystring &rhs){
    return (std::strcmp(lhs.str, rhs.str)>0);
}
Mystring operator-(const Mystring &lhs) {
    char *buff = new char [std::strlen(lhs.str)+1];
    std::strcpy(buff, lhs.str);
//    std::cout<< "strlen(buff):" <<std::strlen(buff) <<std::endl;
    for (size_t i {0}; i< std::strlen(buff); i++)
        buff[i] = std::tolower(buff[i]);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    char *buff = new char [ std::strlen(lhs.str) + std::strlen(rhs.str) + 1 ];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring & operator+=(Mystring &lhs, const Mystring &rhs){
    lhs = lhs + rhs;
    return lhs;
}

Mystring operator* (const Mystring &lhs, int a)  {
    char *buff = new char [std::strlen( lhs.str ) * a +1];
    for (size_t i = 0; i<a; i++){
        std::strcat(buff, lhs.str );
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

Mystring & operator *=(Mystring &lhs, int a){
    lhs = lhs * a;
    return lhs;
}

Mystring & operator ++(Mystring &lhs){ // pre-increment, to upper case before use it
    char *buff = new char [std::strlen(lhs.str)+1];
    std::strcpy(buff, lhs.str);
    for (size_t i =0; i<std::strlen(buff); i++)
        buff[i] = std::toupper(buff[i]);
    Mystring temp {buff};
    lhs = temp;
    delete [] buff;
    return lhs;
}

Mystring operator ++(Mystring &lhs, int){
    Mystring temp {lhs};
    ++(lhs);
    return temp;
}
/*
*/