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

	// while (spliter < token_num)
	// {
	// 	printf("%d\n", s.arr[s.top]);
	// }
}