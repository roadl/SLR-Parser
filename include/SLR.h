#ifndef SLR_H
# define SLR_H

# define STACK_SIZE 100
# define CFG_SIZE 34

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

// stack struct
// functions in stack.c
typedef struct stack
{
	int arr[STACK_SIZE];
	int top;
} Stack;

// cfg struct
// LHS -> RHS, size = |RHS|
typedef struct cfg
{
	char *LHS;
	char **RHS;
	int size;
} CFG;

typedef enum symbol {
    vtype, id, semi, assign, literal, character, boolstr, addsub, multdiv,
    lparen, rparen, num, lbrace, rbrace, comma, if_sym, while_sym, comp, else_sym,
    return_sym, dollar, CODE, VDECL, ASSIGN, RHS, EXPR, E, T, F
} Symbol;

// get string from file and split string using delemeter
// functions in paresFile.c
char *read_file(const char *input_file);
char **split_string(char *str, int *num_tokens);

// SLR parsing
void SLR_parsing(char **tokens, int token_num);

// stack functions
// functions in parseFile.c
void init_stack(Stack *s);
int is_empty(Stack *s);
int is_full(Stack *s);
int push(Stack *s, int n);
int pop(Stack *s);

// init functions
// functiosn in init.c
void init_CFG(CFG *cfg);
void init_table(int **table);

#endif