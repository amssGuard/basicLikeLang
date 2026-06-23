#pragma once
#include"error.h"
#include<string>

class IllegalCharError : public Error{
    public:
    IllegalCharError(std::string details);
};