#include"error.h"
#include<string>

class IllegalCharError : Error{
    public:
    IllegalCharError(std::string details);
};