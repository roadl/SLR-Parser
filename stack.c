#include "SLR.h"

void init_stack(Stack *s)
{
	s->top = 0;
	s->arr[0] = 1;
}

int is_empty(Stack *s)
{
	if (s->top == -1)
		return 1;
	return 0;
}

int is_full(Stack *s)
{
	if (s->top == STACK_SIZE - 1)
		return 1;
	return 0;
}

int push(Stack *s, int n)
{
	if (is_full(s))
		return -1;
	s->top++;
	s->arr[s->top] = n;
	return n;
}

int pop(Stack *s)
{
	int n;

	if (is_empty(s))
		return -1;
	n = s->arr[s->top--];
	return n;
}