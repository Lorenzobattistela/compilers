// token.c

#include "token.h"

const char* token_to_string(token_t token) {
    switch (token) {
        case TOKEN_EOF:                return "TOKEN_EOF";
        case TOKEN_ABSTRACT:           return "TOKEN_ABSTRACT";
        case TOKEN_ASSERT:             return "TOKEN_ASSERT";
        case TOKEN_BOOLEAN:            return "TOKEN_BOOLEAN";
        case TOKEN_BREAK:              return "TOKEN_BREAK";
        case TOKEN_BYTE:               return "TOKEN_BYTE";
        case TOKEN_CASE:               return "TOKEN_CASE";
        case TOKEN_CHAR:               return "TOKEN_CHAR";
        case TOKEN_CLASS:              return "TOKEN_CLASS";
        case TOKEN_CONST:              return "TOKEN_CONST";
        case TOKEN_CONTINUE:           return "TOKEN_CONTINUE";
        case TOKEN_DEFAULT:            return "TOKEN_DEFAULT";
        case TOKEN_DO:                 return "TOKEN_DO";
        case TOKEN_DOUBLE:             return "TOKEN_DOUBLE";
        case TOKEN_ELSE:               return "TOKEN_ELSE";
        case TOKEN_ENUM:               return "TOKEN_ENUM";
        case TOKEN_EXTENDS:            return "TOKEN_EXTENDS";
        case TOKEN_FINAL:              return "TOKEN_FINAL";
        case TOKEN_FINALLY:            return "TOKEN_FINALLY";
        case TOKEN_FLOAT:              return "TOKEN_FLOAT";
        case TOKEN_GOTO:               return "TOKEN_GOTO";
        case TOKEN_IF:                 return "TOKEN_IF";
        case TOKEN_IMPLEMENTS:         return "TOKEN_IMPLEMENTS";
        case TOKEN_IMPORT:             return "TOKEN_IMPORT";
        case TOKEN_INSTANCEOF:         return "TOKEN_INSTANCEOF";
        case TOKEN_INT:                return "TOKEN_INT";
        case TOKEN_INTERFACE:          return "TOKEN_INTERFACE";
        case TOKEN_LONG:               return "TOKEN_LONG";
        case TOKEN_NATIVE:             return "TOKEN_NATIVE";
        case TOKEN_NEW:                return "TOKEN_NEW";
        case TOKEN_PACKAGE:            return "TOKEN_PACKAGE";
        case TOKEN_PRIVATE:            return "TOKEN_PRIVATE";
        case TOKEN_PUBLIC:             return "TOKEN_PUBLIC";
        case TOKEN_PROTECTED:          return "TOKEN_PROTECTED";
        case TOKEN_RETURN:             return "TOKEN_RETURN";
        case TOKEN_SHORT:              return "TOKEN_SHORT";
        case TOKEN_STATIC:             return "TOKEN_STATIC";
        case TOKEN_STRICTFP:           return "TOKEN_STRICTFP";
        case TOKEN_SUPER:              return "TOKEN_SUPER";
        case TOKEN_SWITCH:             return "TOKEN_SWITCH";
        case TOKEN_SYNCHRONIZED:       return "TOKEN_SYNCHRONIZED";
        case TOKEN_THIS:               return "TOKEN_THIS";
        case TOKEN_THROW:              return "TOKEN_THROW";
        case TOKEN_THROWS:             return "TOKEN_THROWS";
        case TOKEN_TRANSIENT:          return "TOKEN_TRANSIENT";
        case TOKEN_TRY:                return "TOKEN_TRY";
        case TOKEN_VOLATILE:           return "TOKEN_VOLATILE";
        case TOKEN_WHILE:              return "TOKEN_WHILE";
        case TOKEN_IDENT:              return "TOKEN_IDENT";
        case TOKEN_NUMBER:             return "TOKEN_NUMBER";
        case TOKEN_ADD:                return "TOKEN_ADD";
        case TOKEN_SUBTRACT:           return "TOKEN_SUBTRACT";
        case TOKEN_MULTIPLY:           return "TOKEN_MULTIPLY";
        case TOKEN_DIVIDE:             return "TOKEN_DIVIDE";
        case TOKEN_MOD:                return "TOKEN_MOD";
        case TOKEN_LESSTHAN:           return "TOKEN_LESSTHAN";
        case TOKEN_GREATERTHAN:        return "TOKEN_GREATERTHAN";
        case TOKEN_GREATHEREQTHAN:     return "TOKEN_GREATHEREQTHAN";
        case TOKEN_LESSEQTHAN:         return "TOKEN_LESSEQTHAN";
        case TOKEN_EQUAL:              return "TOKEN_EQUAL";
        case TOKEN_DIFF:               return "TOKEN_DIFF";
        case TOKEN_LOGNOT:             return "TOKEN_LOGNOT";
        case TOKEN_LOGAND:             return "TOKEN_LOGAND";
        case TOKEN_LOGOR:              return "TOKEN_LOGOR";
        case TOKEN_INCREMENT:         return "TOKEN_INCREMENT";
        case TOKEN_DECREMENT:         return "TOKEN_DECREMENT";
        case TOKEN_LPARENTHESIS:      return "TOKEN_LPARENTHESIS";
        case TOKEN_RPARENTHESIS:      return "TOKEN_RPARENTHESIS";
        case TOKEN_LBRACE:            return "TOKEN_LBRACE";
        case TOKEN_RBRACE:            return "TOKEN_RBRACE";
        case TOKEN_LSQBRACKET:        return "TOKEN_LSQBRACKET";
        case TOKEN_RSQBRACKET:        return "TOKEN_RSQBRACKET";
        case TOKEN_COMMA:             return "TOKEN_COMMA";
        case TOKEN_DOT:               return "TOKEN_DOT";
        case TOKEN_SEMICOLON:         return "TOKEN_SEMICOLON";
        case TOKEN_ERROR:             return "TOKEN_ERROR";
        default:                      return "UNKNOWN_TOKEN";
    }
}
