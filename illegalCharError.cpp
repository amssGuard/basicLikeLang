#include"illegalCharError.h"
#include<iostream>
#include<string>

IllegalCharError::IllegalCharError(Position posStart, Position posEnd, std::string details):Error(posStart,posEnd,"Illegal Character",details){}