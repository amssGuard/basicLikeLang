#pragma once
#include"token.h"
#include<string>
#include<vector>
#include<memory>
#include"node.h"
#include <functional>

class BParser{
    private:
    std::vector<Token> tokens;
    int tok_idx;
    Token current_tok;
    public:
    BParser(std::vector<Token>);
    Token advance();
    std::unique_ptr<Node> factor();
    std::unique_ptr<Node> term();
    std::unique_ptr<Node> expr();
    std::unique_ptr<Node> BinOp(std::function<std::unique_ptr<Node>()> func,TokenType,TokenType);
    std::unique_ptr<Node> parse();
};