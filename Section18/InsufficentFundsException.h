#ifndef _INSUFFICENTFUNDSEXCEPTION_H_
#define _INSUFFICENTFUNDSEXCEPTION_H_
#include <exception>

class InsufficentFundsException : public std::exception{
public:
    InsufficentFundsException() noexcept = default;
    virtual ~InsufficentFundsException() = default;
    virtual const char *what() const noexcept{
        return "Insufficent funds exception";
    } 

};

#endif // _INSUFFICENTFUNDSEXCEPTION_H_
