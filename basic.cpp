#include<iostream>
#include<string>
#include"lexer.h"
#include"error.h"
#include"bparser.h"

using namespace std;

int main(){
    string inp;
    while(true){
        cout<<"basic >";
        getline(cin,inp);
        Lexer lexer(inp);
        try{
            auto tokens = lexer.make_tokens();
            //for(const auto& tok:tokens)
            //cout<<tok.getValue()<<" ";
            //cout<<endl;
            BParser parse = BParser(tokens);
            unique_ptr<Node> ast = parse.parse();
            cout<<ast->to_string()<<endl;
        }catch(Error &e){
            cout<<e.to_string()<<endl;
        }
    }
    return 0;
}
//TODO: the position constructor should get two more parameters filename and file content
// so should the lexer get file name