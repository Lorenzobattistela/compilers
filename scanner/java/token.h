#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
    TOKEN_EOF=0,
    TOKEN_ABSTRACT,
    TOKEN_ASSERT,
    TOKEN_BOOLEAN,
    TOKEN_BREAK,
    TOKEN_BYTE,
    TOKEN_CASE,
    TOKEN_CHAR,
    TOKEN_CLASS,
    TOKEN_CONST,
    TOKEN_CONTINUE,
    TOKEN_DEFAULT,
    TOKEN_DO,
    TOKEN_DOUBLE,
    TOKEN_ELSE,
    TOKEN_ENUM,
    TOKEN_EXTENDS,
    TOKEN_FINAL,
    TOKEN_FINALLY,
    TOKEN_FLOAT,
    TOKEN_GOTO,
    TOKEN_IF,
    TOKEN_IMPLEMENTS,
    TOKEN_IMPORT,
    TOKEN_INSTANCEOF,
    TOKEN_INT,
    TOKEN_INTERFACE,
    TOKEN_LONG,
    TOKEN_NATIVE,
    TOKEN_NEW,
    TOKEN_PACKAGE,
    TOKEN_PRIVATE,
    TOKEN_PUBLIC,
    TOKEN_PROTECTED,
    TOKEN_RETURN,
    TOKEN_SHORT,
    TOKEN_STATIC,
    TOKEN_STRICTFP,
    TOKEN_SUPER,
    TOKEN_SWITCH,
    TOKEN_SYNCHRONIZED,
    TOKEN_THIS,
    TOKEN_THROW,
    TOKEN_THROWS,
    TOKEN_TRANSIENT,
    TOKEN_TRY,
    TOKEN_VOLATILE,
    TOKEN_WHILE,
    TOKEN_IDENT,
    TOKEN_NUMBER,
    TOKEN_ADD,
    TOKEN_SUBTRACT,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_MOD,
    TOKEN_LESSTHAN,
    TOKEN_GREATERTHAN,
    TOKEN_GREATHEREQTHAN,
    TOKEN_LESSEQTHAN,
    TOKEN_EQUAL,
    TOKEN_DIFF,
    TOKEN_LOGNOT,
    TOKEN_LOGAND,
    TOKEN_LOGOR,
    TOKEN_INCREMENT,
    TOKEN_DECREMENT,
    TOKEN_LPARENTHESIS,
    TOKEN_RPARENTHESIS,
    TOKEN_LBRACE,
    TOKEN_RBRACE,
    TOKEN_LSQBRACKET,
    TOKEN_RSQBRACKET,
    TOKEN_COMMA,
    TOKEN_DOT,
    TOKEN_ERROR,
} token_t;

const char* token_to_string(token_t token);

#endif