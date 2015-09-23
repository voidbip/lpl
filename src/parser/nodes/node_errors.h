#ifndef __NODE_ERRORS__H
#define __NODE_ERRORS__H
#include <exception>


class divByZeroError : public std::exception {
    virtual const char* what() const throw();
};


class syntaxError : public std::exception {
    virtual const char* what() const throw();
};


#endif
