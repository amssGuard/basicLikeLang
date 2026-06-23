#include"lexer.h"
#include"illegalCharError.h"
#include<iostream>
#include<cctype>

Lexer::Lexer(const std::string& text):text(text),pos(-1),current_char(' '){
    advance();
};
void Lexer::advance(){
    pos++;
    current_char = (pos<text.length())?text[pos]:'\0';
}

Token Lexer::make_number(){
    std::string numStr = "";
    int dot_count = 0;
    while(current_char != '\0' &&
      (std::isdigit(current_char) || current_char == '.')){
        if(current_char=='.'){
            if(dot_count==1) break;
            dot_count+=1;
            numStr+=".";
        }else numStr += current_char;
        advance();
    }
    if(dot_count==1) return Token(TokenType::FLOAT,numStr);
    return Token(TokenType::INT,numStr);
}

std::vector<Token> Lexer::make_tokens(){
    std::vector<Token> tokens;
    while(current_char!='\0'){
        if(current_char == '\t'||current_char==' '){
            advance();
        } 
        else if(current_char == '+'){
            tokens.push_back(Token(TokenType::PLUS,"+"));
            advance();
        }
        else if(current_char == '-'){
            tokens.push_back(Token(TokenType::MINUS,"-"));
            advance();
        }
        else if(current_char == '*'){
            tokens.push_back(Token(TokenType::MUL,"*"));
            advance();
        }
        else if(current_char == '/'){
            tokens.push_back(Token(TokenType::DIV,"/"));
            advance();
        }
        else if(current_char == '('){
            tokens.push_back(Token(TokenType::LPAREN,"("));
            advance();
        }
        else if(current_char == ')'){
            tokens.push_back(Token(TokenType::RPAREN,")"));
            advance();
        }
        else if(std::isdigit(current_char)){
            tokens.push_back(make_number());
        }
        else{
            char c = current_char;
            advance();
            IllegalCharError(std::string("'")+c+"'");
            return {};
        }
    }
    tokens.push_back(Token(TokenType::EOF_TOKEN,"EOF"));
    return tokens;
}