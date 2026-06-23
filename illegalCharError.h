#pragma once
#include"error.h"
#include<string>
#include"Position.h"

class IllegalCharError : public Error{
    public:
    IllegalCharError(Position posStart,Position posEnd,std::string details);
};