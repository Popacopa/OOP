#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>

class TypeError {
    public:
        TypeError() {
                    std::cin.clear();
                    std::cin.ignore();
        }
        std::string what() {
                    return message;
        }
    private:
        std::string message =  "\x1b[31mTypeError! Expected int\x1b[0m\n";
};


#endif