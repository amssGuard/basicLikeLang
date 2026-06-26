#include<string>
#include"error.h"

using namespace std;

Error::Error(Position posStart,Position posEnd,string errorName,string errorDetail):
posStart(posStart),
posEnd(posEnd),
errorName(errorName),errorDetail(errorDetail){}



string Error::to_string(){
    return errorName+" : "+errorDetail+" at line Number "+std::to_string(posStart.ln+1)+" on "+std::to_string(posStart.col+1)+"th character";
}