#include<string>
#include"error.h"

using namespace std;

Error::Error(string errorName,string errorDetail):
errorName(errorName),errorDetail(errorDetail){}

Error::~Error(){}

string Error::to_string(){
    return errorName+" : "+errorDetail;
}