#include<iostream>
#include<string>
#include"lexer.h"

using namespace std;

int main(){
    string inp;
    while(true){
        cout<<"basic >";
        getline(cin,inp);
        Lexer lexer(inp);
        auto tokens = lexer.make_tokens();
        for(const auto& tok:tokens)
            cout<<tok.getValue()<<" ";
        cout<<endl;
    }
    return 0;
}
//TODO:LPAREN, RPAREN and EOF