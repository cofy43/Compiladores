%{
#include <iostream>
#include <string>
using namespace std;

#include "headers/Symbols.hpp"
#include "headers/Lexer.hpp"

int line=1;
%}

%option c++
%option outfile="Lexer.cpp"
%option yyclass="Lexer"

%%

"int" { return INT; }
"float" { return FLOAT; }
[a-zA-Z_]([a-zA-Z0-9_])* { return ID; }
"if" { return IF; }
"while" { return WHILE; }
"else" { return ELSE; }
[0-9]+ { return NUM; }
"," { return COMA; }
";" { return PYC; }
"(" { return LPAR; }
")" { return RPAR; }
"{" { return LBRA; }
"}" { return RBRA; }
"+" { return MAS; }
"-" { return MENOS; }
"*" { return MUL; }
"/" { return DIV; }
"=" { return ASIG; }

[ \t\r]+ {}
"\n" 	 {line++;}
.    	 { cout << "ERROR LEXICO " << yytext << endl;}
%%
int yyFlexLexer::yywrap(){
    return 1;
}
int Lexer::getLine()
{
    return line;
}