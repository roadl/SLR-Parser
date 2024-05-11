#include "SLR.h"

// SN 을 실행함
// Stack에 n을 넣고 spliter 위치 오른쪽으로 증가
void shift(Stack *s, int *spliter, int n)
{
	push(s, n);
	*spliter++;
}

// RN 을 실행함
// Stack에서 N번째 룰의 크기만큼 pop, goto 실행
void reduce(Stack *s, CFG *cfg, char **tokens, int n)
{
	int size = cfg[n].size;

	for (int i = 0; i < size; i++)
		pop(s);
	//push(s, table[get_goto(tokens[s->top])]);
}

char *step(int state, char *token)
{

}

void SLR_parsing(char **tokens, int token_num)
{
	Stack s;
	CFG cfg[CFG_SIZE];
	int spliter = 0;
	int **table;

	init_stack(&s);
	init_CFG(cfg);

	printf("init done\n");

	exit(EXIT_SUCCESS);

	while (spliter < token_num)
	{
        char *action;
        int state;

        state = s.arr[s.top];
        action = step(state, tokens[spliter]);
        if (strncmp(action, "S", 1) == 0)
            shift(&s, &spliter, action[2] - '0');
        if (strncmp(action, "R", 1) == 0)
            reduce(&s, cfg, tokens, action[2] - '0');
        if (strncmp(action, "acc", 3) == 0)
            break ;
	}
}

Symbol get_symbol(char *str) {
    if (strcmp(str, "vtype") == 0) return vtype;
    if (strcmp(str, "id") == 0) return id;
    if (strcmp(str, "semi") == 0) return semi;
    if (strcmp(str, "assign") == 0) return assign;
    if (strcmp(str, "literal") == 0) return literal;
    if (strcmp(str, "character") == 0) return character;
    if (strcmp(str, "boolstr") == 0) return boolstr;
    if (strcmp(str, "addsub") == 0) return addsub;
    if (strcmp(str, "multdiv") == 0) return multdiv;
    if (strcmp(str, "lparen") == 0) return lparen;
    if (strcmp(str, "rparen") == 0) return rparen;
    if (strcmp(str, "num") == 0) return num;
    if (strcmp(str, "lbrace") == 0) return lbrace;
    if (strcmp(str, "rbrace") == 0) return rbrace;
    if (strcmp(str, "comma") == 0) return comma;
    if (strcmp(str, "if") == 0) return if_sym;
    if (strcmp(str, "while") == 0) return while_sym;
    if (strcmp(str, "comp") == 0) return comp;
    if (strcmp(str, "else") == 0) return else_sym;
    if (strcmp(str, "return") == 0) return return_sym;
    if (strcmp(str, "$") == 0) return dollar;
    if (strcmp(str, "CODE") == 0) return CODE;
    if (strcmp(str, "VDECL") == 0) return VDECL;
    if (strcmp(str, "ASSIGN") == 0) return ASSIGN;
    if (strcmp(str, "RHS") == 0) return RHS;
    if (strcmp(str, "EXPR") == 0) return EXPR;
    if (strcmp(str, "E") == 0) return E;
    if (strcmp(str, "T") == 0) return T;
    if (strcmp(str, "F") == 0) return F;
    return -1;
}