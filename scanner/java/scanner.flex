%{
#include "token.h"
%}
DIGIT [0-9]
LETTER [a-zA-Z]
%%
(" "|\t|\n) /* skip whitespace */
abstract { return TOKEN_ABSTRACT; }
assert { return TOKEN_ASSERT; }
boolean { return TOKEN_BOOLEAN; }
break { return TOKEN_BREAK; }
byte { return TOKEN_BYTE; }
case { return TOKEN_CASE; }
char { return TOKEN_CHAR; }
class { return TOKEN_CLASS; }
const { return TOKEN_CONST; }
continue { return TOKEN_CONTINUE; }
default { return TOKEN_DEFAULT; }
do { return TOKEN_DO; }
double { return TOKEN_DOUBLE; }
else { return TOKEN_ELSE; }
enum { return TOKEN_ENUM; }
extends { return TOKEN_EXTENDS; }
final { return TOKEN_FINAL; }
finally { return TOKEN_FINALLY; }
float { return TOKEN_FLOAT; }
goto { return TOKEN_GOTO; }
if { return TOKEN_IF; }
implements { return TOKEN_IMPLEMENTS; }
import { return TOKEN_IMPORT; }
instanceof { return TOKEN_INSTANCEOF; }
int { return TOKEN_INT; }
interface { return TOKEN_INTERFACE; }
long { return TOKEN_LONG; }
native { return TOKEN_NATIVE; }
new { return TOKEN_NEW; }
package { return TOKEN_PACKAGE; }
private { return TOKEN_PRIVATE; }
public { return TOKEN_PUBLIC; }
protected { return TOKEN_PROTECTED; }
return { return TOKEN_RETURN; }
short { return TOKEN_SHORT; }
static { return TOKEN_STATIC; }
strictfp { return TOKEN_STRICTFP; }
super { return TOKEN_SUPER; }
switch { return TOKEN_SWITCH; }
synchronized { return TOKEN_SYNCHRONIZED; }
this { return TOKEN_THIS; }
throw { return TOKEN_THROW; }
throws { return TOKEN_THROWS; }
transient { return TOKEN_TRANSIENT; }
try { return TOKEN_TRY; }
volatile { return TOKEN_VOLATILE; }
while { return TOKEN_WHILE; }
{LETTER}+ { return TOKEN_IDENT; }
{DIGIT}+ { return TOKEN_NUMBER; }
\+ { return TOKEN_ADD; }
\- { return TOKEN_SUBTRACT; }
\* { return TOKEN_MULTIPLY; }
\/ { return TOKEN_DIVIDE; }
\% { return TOKEN_MOD; }
\< { return TOKEN_LESSTHAN; }
\> { return TOKEN_GREATERTHAN; }
\>\= { return TOKEN_GREATHEREQTHAN; }
\<\= { return TOKEN_LESSEQTHAN; }
\=\= { return TOKEN_EQUAL; }
\!\= { return TOKEN_DIFF; }
\! { return TOKEN_LOGNOT; }
\&\& { return TOKEN_LOGAND; }
\|\| { return TOKEN_LOGOR; }
\+\+ { return TOKEN_INCREMENT; }
\-\- { return TOKEN_DECREMENT; }
\( { return TOKEN_LPARENTHESIS; }
\) { return TOKEN_RPARENTHESIS; }
\{ { return TOKEN_LBRACE; }
\} { return TOKEN_RBRACE; }
\[ { return TOKEN_LSQBRACKET; }
\] { return TOKEN_RSQBRACKET; }
\, { return TOKEN_COMMA; }
\. { return TOKEN_DOT; }
. { return TOKEN_ERROR; }
%%
int yywrap() { return 1; }
