#include"illegalCharError.h"
#include<iostream>
#include<string>

IllegalCharError::IllegalCharError(std::string details):Error("Illegal Character",details){}