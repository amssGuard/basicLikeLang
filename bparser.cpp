#include"bparser.h"

BParser::BParser(std::vector<Token> tokens):tokens(tokens),tok_idx(0),current_tok(tokens[0]){}

Token BParser::advance(){
    tok_idx++;
    if(tok_idx<tokens.size()){
        current_tok = tokens[tok_idx];
    }
    return current_tok;
}