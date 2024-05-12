#ifndef SLR_H
# define SLR_H

# define STACK_SIZE	100
# define CFG_SIZE	36

# define TABLE_ROW	76
# define TABLE_COL	40

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

# include <iostream>
# include <stack>
# include <vector>

using namespace std;

// cfg struct
// LHS -> RHS, size = |RHS|
typedef struct cfg
{
	char *LHS;
	char **RHS;
	int size;
} CFG;

typedef enum symbol {
    vtype, id, semi, assign, literal, character, boolstr, addsub, multdiv = 8,
    lparen, rparen, num, lbrace, rbrace, comma, if_sym, while_sym, comp, else_sym = 18,
    return_sym, dollar, CODE, VDECL, ASSIGN, RHS, EXPR, E, T, F, FDECL, ARG, MOREARGS = 31, 
	BLOCK, STMT, COND, _COND, ELSE, RETURN, ERROR = 38
} Symbol;

class Node
{
public:
	char *token;
	vector<Node *> childs;
	Node *parent;

	Node(char *token) { this->token = token; parent = nullptr; };
	~Node() {};
};

// get string from file and split string using delemeter
// functions in paresFile.c
char *read_file(const char *input_file);
char **split_string(char *str, int *num_tokens);

// SLR parsing
void SLR_parsing(char **tokens, int token_num);

// init functions
// functiosn in init.c
void init_CFG(CFG *cfg);
void init_table(char *table[TABLE_ROW][TABLE_COL]);

#endif