#include"bparser.h"
#include<memory>
#include"node.h"
#include"token.h"

using namespace std;

BParser::BParser(std::vector<Token> tokens):tokens(tokens),tok_idx(0),current_tok(tokens[0]){}

Token BParser::advance(){
    tok_idx++;
    if(tok_idx<tokens.size()){
        current_tok = tokens[tok_idx];
    }
    return current_tok;
}

unique_ptr<Node> BParser:: factor(){
    Token tok = current_tok;
    if(tok.getType()==TokenType::INT||tok.getType()==TokenType::FLOAT){
        advance();
        return make_unique<NumberNode>(tok);
    }
    //TO:DO error reporting
}

unique_ptr<Node> BParser:: term(){
    return BinOp([this](){ return factor(); }, TokenType::MUL,TokenType::DIV);
}

unique_ptr<Node> BParser:: expr(){
    return BinOp([this](){return term();},TokenType::PLUS,TokenType::MINUS);
}

unique_ptr<Node> BParser::BinOp(std::function<std::unique_ptr<Node>()> func,TokenType t1,TokenType t2){
    unique_ptr<Node> left = func();
    while(current_tok.getValue()!="\0"&&(current_tok.getType()==t1||current_tok.getType()==t2)){
        Token op = current_tok;
        advance();
        unique_ptr<Node> right = func();
        left = make_unique<BinOpNode>(std::move(left),op,std::move(right));
    }
    return left;
}

unique_ptr<Node> BParser::parse(){
    return expr();
}