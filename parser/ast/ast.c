#include <stdio.h>
#include <stdlib.h>

// DECLARATION BLOCK -------------------------------------------------------------------------- //
struct decl {
    char *name;
    struct type *type;
    struct expr *value;
    struct stmt *code;
    struct decl *next;
};

struct decl *decl_create(
	char *name, struct type *type, struct expr *value, struct stmt *code, struct decl *next
)
{
	struct decl *d = malloc(sizeof(*d));
	d -> name = name;
	d -> type = type;
	d -> value = value;
	d -> code = code;
	d -> next = next;
	return d;
}


//  STATEMENT BLOCK ------------------------------------------------------------------------- //
typedef enum {
	STMT_DECL,
	STMT_EXPR,
	STMT_IF_ELSE,
	STMT_FOR,
	STMT_PRINT,
	STMT_RETURN,
	STMT_BLOCK
} stmt_t;

struct stmt {
	stmt_t kind;
	struct decl *decl;
	struct expr *init_expr;
	struct expr *expr;
	struct expr *next_expr;
	struct stmt *body;
	struct stmt *else_body;
	struct stmt *next;
};

struct stmt * stmt_create(
    stmt_t kind,
    struct decl *decl, struct expr *init_expr,
    struct expr *expr, struct expr *next_expr,
    struct stmt *body, struct stmt *else_body,
    struct stmt *next 
);


// EXPRESSION BLOCK --------------------------------------------------------------------------------------- //
typedef enum {
    EXPR_ADD,
    EXPR_SUB,
    EXPR_MUL,
    EXPR_DIV,
    EXPR_NAME,
    EXPR_INTEGER_LITERAL,
    EXPR_STRING_LITERAL
} expr_t;

struct expr {
    expr_t kind;
    struct expr *left;
    struct expr *right;
    const char *name;
    int integer_value;
    const char *string_literal;
};

struct expr *expr_create(
    expr_t kind, struct expr *L, struct expr *R
);

struct expr *expr_create_name(const char *name);
struct expr *expr_create_integer_literal(int i);
struct expr *expr_create_boolean_litearl(int b);
struct expr *expr_create_char_literal(char c);
struct expr *expr_create_string_literal(const char *str);

// TYPE BLOCK --------------------------------------------------------------------------------------- //
typedef enum {
    TYPE_VOID,
    TYPE_BOOLEAN,
    TYPE_CHARACTER,
    TYPE_INTEGER,
    TYPE_STRING,
    TYPE_ARRAY,
    TYPE_FUNCTION
} type_t;

struct type {
    type_t kind;
    struct type *subtype;
    struct params_list *params;
};

struct params_list {
    char *name;
    struct type *type;
    struct params_list *next;
};

int main() {return 0;}