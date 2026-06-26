#pragma once
#include<string>
#include"Position.h"

class Error{
    private:
    Position posStart, posEnd;
    std::string errorName,errorDetail;
    public:
    Error(Position postStart, Position posEnd,std::string errorName,std::string detail);

    std::string to_string();
};