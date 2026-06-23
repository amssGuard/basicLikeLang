#ifndef TOKEN_H

#define TOKEN_H



#include<string>



enum class TokenType {

    INT,

    FLOAT,

    PLUS,

    MINUS,

    MUL,

    DIV,

    LPAREN,

    RPAREN,

    EOF_TOKEN

};



class Token{

    private:

    TokenType type;

    std::string value;

    public:

    Token(TokenType type,const std::string& value="");



    std::string to_string() const;

    TokenType getType() const;

    std::string getValue() const;

};



#endif