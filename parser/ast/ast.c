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
) 
{
    struct stmt *s = malloc(sizeof(*s));
    s -> kind = kind;
    s -> expr = expr;
    s -> body = body;
    s -> next = next;
    return s;
}


// EXPRESSION BLOCK --------------------------------------------------------------------------------------- //
typedef enum {
    EXPR_ADD,
    EXPR_SUB,
    EXPR_MUL,
    EXPR_DIV,
    EXPR_NAME,
    EXPR_INTEGER_LITERAL,
    EXPR_BOOLEAN_LITERAL,
    EXPR_STRING_LITERAL,
    EXPR_CHAR_LITERAL
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
)
{
    struct expr *e = malloc(sizeof(*e));
    e -> kind = kind;
    e -> left = L;
    e -> right = R;
};

struct expr *expr_create_name(const char *name) {
    struct expr *e = malloc(sizeof(*e));
    e -> kind = EXPR_NAME;
    e -> name = name;
    return e;
};

struct expr *expr_create_integer_literal(int i) {
    struct expr *e = malloc(sizeof(*e));
    e -> kind = EXPR_INTEGER_LITERAL;
    e -> integer_value = i;
    return e;
};

struct expr *expr_create_boolean_literal(int b) {
    struct expr *e = malloc(sizeof(*e));
    e -> kind = EXPR_BOOLEAN_LITERAL;
    e -> integer_value = b;
    return e;
};

struct expr *expr_create_char_literal(char c) {
    struct expr *e = malloc(sizeof(*e));
    e -> kind = EXPR_CHAR_LITERAL;
    e -> integer_value = c;
    return e;
};

struct expr *expr_create_string_literal(const char *str) {
    struct expr *e = malloc(sizeof(*e));
    e -> kind = EXPR_STRING_LITERAL;
    e -> string_literal = str;
    return e;
};

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
    struct param_list *params;
};

struct type *type_create(type_t kind, struct type *subtype, struct param_list *params) {
    struct type *t = malloc(sizeof(*t));
    t -> kind = kind;
    t -> subtype = subtype;
    t -> params = params;
    return t;
}

struct param_list {
    char *name;
    struct type *type;
    struct param_list *next;
};

struct param_list *param_list_create(char *name, struct type *type, struct param_list *next) {
    struct param_list *p = malloc(sizeof(*p));
    p -> name = name;
    p -> type = type;
    p -> next = next;
}


// PRINTING HELPERS ---------------------------------------------------------------------------------------//


void print_decl(struct decl *d, int indent);
void print_stmt(struct stmt *s, int indent);
void print_expr(struct expr *e, int indent);
void print_type(struct type *t, int indent);
void print_param_list(struct param_list *p, int indent);

void print_stmt(struct stmt *s, int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }

    switch (s->kind) {
        case STMT_DECL:
            printf("Declaration: %s\n", s->decl->name);
            if (s->decl->type) {
                for (int i = 0; i < indent + 1; i++) {
                    printf("  ");
                }
                printf("Type:\n");
                print_type(s->decl->type, indent + 2);
            }
            if (s->decl->value) {
                for (int i = 0; i < indent + 1; i++) {
                    printf("  ");
                }
                printf("Value:\n");
                print_expr(s->decl->value, indent + 2);
            }
            break;
        case STMT_EXPR:
            printf("Expression:\n");
            print_expr(s->expr, indent + 1);
            break;
        case STMT_RETURN:
            printf("Return:\n");
            if (s->expr) {
                print_expr(s->expr, indent + 1);
            }
            break;
        // Handle other statement types here
        default:
            printf("Unknown statement type\n");
            break;
    }

    if (s->next) {
        print_stmt(s->next, indent);
    }
}

void print_expr(struct expr *e, int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }

    switch (e->kind) {
        case EXPR_NAME:
            printf("Name: %s\n", e->name);
            break;
        case EXPR_INTEGER_LITERAL:
            printf("Integer Literal: %d\n", e->integer_value);
            break;
        case EXPR_BOOLEAN_LITERAL:
            printf("Boolean Literal: %s\n", e->integer_value ? "true" : "false");
            break;
        case EXPR_STRING_LITERAL:
            printf("String Literal: \"%s\"\n", e->string_literal);
            break;
        case EXPR_CHAR_LITERAL:
            printf("Char Literal: '%c'\n", e->integer_value);
            break;
        case EXPR_ADD:
            printf("Addition:\n");
            break;
        case EXPR_SUB:
            printf("Subtraction:\n");
            break;
        case EXPR_MUL:
            printf("Multiplication:\n");
            break;
        case EXPR_DIV:
            printf("Division:\n");
            break;
        default:
            printf("Unknown expression type\n");
            break;
    }

    if (e->left) {
        print_expr(e->left, indent + 1);
    }
    if (e->right) {
        print_expr(e->right, indent + 1);
    }
}


void print_type(struct type *t, int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    switch (t->kind) {
        case TYPE_VOID:
            printf("Type: void\n");
            break;
        
        case TYPE_BOOLEAN:
            printf("Type: boolean\n");
            break;
        
        case TYPE_CHARACTER:
            printf("Type: character\n");
            break;

        case TYPE_INTEGER:
            printf("Type: integer\n");
            break;

        case TYPE_STRING:
            printf("Type: string\n");
            break;

        case TYPE_ARRAY:
            printf("Type: array\n");
            break;
        
        case TYPE_FUNCTION:
            printf("Type: function\n");
            break;

        default:
            printf("Unknown type\n");
            break;
    }

    if (t->subtype) {
        print_type(t->subtype, indent + 1);
    }
}

void print_param_list(struct param_list *p, int indent) {
    while (p) {
        for (int i = 0; i < indent; i++) {
            printf("  ");
        }

        printf("Parameter: %s\n", p->name);
        for (int i = 0; i < indent + 1; i++) {
            printf("  ");
        }
        printf("Type:\n");
        print_type(p->type, indent + 2);

        p = p->next;
    }
}

void print_decl(struct decl *d, int indent) {
    while (d) {
        for (int i = 0; i < indent; i++) {
            printf("  ");
        }

        printf("Declaration: %s\n", d->name);
        if (d->type) {
            for (int i = 0; i < indent + 1; i++) {
                printf("  ");
            }
            printf("Type:\n");
            print_type(d->type, indent + 2);
        }
        if (d->value) {
            for (int i = 0; i < indent + 1; i++) {
                printf("  ");
            }
            printf("Value:\n");
            print_expr(d->value, indent + 2);
        }
        if (d->code) {
            for (int i = 0; i < indent + 1; i++) {
                printf("  ");
            }
            printf("Code:\n");
            print_stmt(d->code, indent + 2);
        }

        d = d->next;
    }
}

int main() {
    struct decl *d = decl_create(
        "square",
        type_create(TYPE_FUNCTION,
            type_create(TYPE_INTEGER,0,0),
            param_list_create(
                "x",
                type_create(TYPE_INTEGER,0,0),
                0
            )
        ),
        0,
        stmt_create(
            STMT_RETURN,0,0,
            expr_create(
                EXPR_MUL,
                expr_create_name("x"),
                expr_create_name("x")
            ),
            0,0,0,0
        ),
        0
    );

    printf("AST:\n");
    print_decl(d, 1); // Start printing with an initial indent of 1
    return 0;
}