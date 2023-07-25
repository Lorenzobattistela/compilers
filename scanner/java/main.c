#include "token.h"
#include <stdio.h>

extern FILE *yyin;
extern int yylex();
extern char *yytext;

int main() {
    yyin = fopen("test.java", "r");
    if(!yyin) {
        printf("Could not open test.java\n");
        return 1;
    }
    while(1) {
        token_t t = yylex();
        if(t==TOKEN_EOF) break;
        printf("token: %d, tokenCode: %s text: %s\n", t, token_to_string(t), yytext);
    }
}