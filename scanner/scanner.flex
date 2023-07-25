%{
#include "token.h"
%}
DIGIT [0-9]
LETTER [a-zA-Z]
%%
(" "|\t|\n) /* skip whitespace */
\{ { return TOKEN_LBRACKET; }
\, { return TOKEN_COMMA; }
\} { return TOKEN_RBRACKET; }
\; { return TOKEN_SEMICOLON; }
{DIGIT}+ { return TOKEN_DIGIT; }
{LETTER}+ { return TOKEN_STRING; }
. { return TOKEN_ERROR; }
%%
int yywrap() { return 1; }

