#pragma once
#include<string>
#include<memory>
#include"token.h"

class Node{
    public:
    virtual ~Node() = default;
    virtual std::string to_string() const = 0;
};

class NumberNode : public Node{
    Token tok;
    public:
    NumberNode(Token tok) : tok(tok){}
    std::string to_string()const override{
        return tok.getValue();
    }
};

class BinOpNode : public Node{
    std::unique_ptr<Node> left;
    Token op;
    std::unique_ptr<Node> right;
    public:
    BinOpNode(std::unique_ptr<Node> left, Token op, std::unique_ptr<Node> right):left(std::move(left)), op(op), right(std::move(right)){}
    std::string to_string()const override{
        return "("+left->to_string()+", "+op.getValue()+", "+right->to_string()+")";
    }
};