#pragma once
#include"token.h"
#include<string>
#include<vector>
#include<set>
#include"Position.h"

class Lexer{
    private:
    std::string text;
    Position pos;
    char current_char;
    Token make_number();

    public:
    Lexer(const std::string& text);
    void advance();
    std::vector<Token> make_tokens();
};