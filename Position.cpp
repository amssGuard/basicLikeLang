#include"Position.h"

using namespace std;

Position::Position(int idx, int ln, int col):idx(idx),ln(ln),col(col){}

void Position::advance(char& current_char){
    idx++;
    col++;
    if(current_char=='\n'){
        ln++;
        col=0;
    }
}

Position Position::copy()const{
    return Position(idx,ln,col);
}