#pragma once
#include<string>

class Position{
    public:
    int idx,ln,col;
    Position(int, int, int);
    void advance(char&);
    Position copy() const;
};