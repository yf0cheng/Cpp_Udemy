#ifndef _MYSTRING_H_
#define _MYSTRING_H_

class Mystring
{
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &in, Mystring &rhs);

private:
    char *str;      // pointer to a char[] that holds a C-style string
public:
    Mystring();                                                         // No-args constructor
    Mystring(const char *s);                                   // Overloaded constructor
    Mystring(const Mystring &source);                 // Copy constructor
    Mystring( Mystring &&source);                        // Move constructor
    ~Mystring();                                                       // Destructor
    
    Mystring &operator=(const Mystring &rhs);   // Copy assignment
    Mystring &operator=(Mystring &&rhs);           // Move assignment
    
    void display() const;
    
    int get_length() const;                                       // getters
    const char *get_str() const;
    
    bool operator==(const Mystring &rhs);
    bool operator!=(const Mystring &rhs);
    bool operator< (const Mystring &rhs);
    bool operator> (const Mystring &rhs);
    
    Mystring operator-  () const; // make lowercase
    Mystring operator+ (const Mystring &rhs) const; // concatenate 
    Mystring & operator+=  (const Mystring &rhs); 
    Mystring operator*  (int a) const;
    Mystring & operator*=  (int a);
    
    Mystring & operator++  (); // pre-increment   to uppercase
    Mystring operator++ (int); // post-increment
    
};

#endif // _MYSTRING_H_