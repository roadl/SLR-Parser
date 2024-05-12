#include "SLR.h"

Symbol get_symbol(char *str);
void print_tree(Node* node, std::string prefix = "", bool is_last = true);

template<typename T>
void printStack(const stack<T> &stk);
void printStackString(const stack<Node *> &stk);

char *table[TABLE_ROW][TABLE_COL];
stack<int> state_stack;
stack<Node *> parsing_stack;

// SN 을 실행함
// Stack에 n을 넣고 spliter 위치 오른쪽으로 증가
void shift(int *spliter, char *token, int n)
{
    printf("S%d\n", n);

	state_stack.push(n);
    parsing_stack.push(new Node(token));
	(*spliter)++;
}

// RN 을 실행함
// Stack에서 N번째 룰의 크기만큼 pop, goto 실행
void reduce(CFG *cfg, int n)
{
	int size = cfg[n].size;
    Node *node = new Node(cfg[n].LHS);
    Node *temp;

    printf("R%d\n", n);

    if (size == 0)
        printf("size = 0, %s\n", cfg[n].LHS);

	for (int i = 0; i < size; i++)
    {
		state_stack.pop();
        temp = parsing_stack.top();
        parsing_stack.pop();
        node->childs.push_back(temp);
        temp->parent = node;
    }

    parsing_stack.push(node);

    int state = state_stack.top();

    state = atoi(table[state][get_symbol(parsing_stack.top()->token)]);
    
    printf("G%d\n", state);

    state_stack.push(state);
}

// char *step(int state, char *token)
// {

// }

void SLR_parsing(char **tokens, int token_num)
{
	CFG cfg[CFG_SIZE];
	int spliter = 0, i = 0;

    state_stack.push(0);

	init_CFG(cfg);
    init_table(table);

	while (spliter < token_num)
	{
        char *action;
        int state;

        state = state_stack.top();
        action = table[state][get_symbol(tokens[spliter])];

        // printf("Step%d state:%d, action:%s, spliter:%d\n", i, state, action, spliter);

        // printStack(state_stack);
        // printStack(parsing_stack);

        if (strncmp(action, "s", 1) == 0)
            shift(&spliter, tokens[spliter], atoi(action + 1));
        if (strncmp(action, "r", 1) == 0)
            reduce(cfg, atoi(action + 1));
        if (strcmp(action, "acc") == 0)
        {
            printf("Accept!!!\n");

            Node *n = new Node("CODE");

            while (!parsing_stack.empty())
            {
                n->childs.push_back(parsing_stack.top());
                parsing_stack.pop();
            }

            print_tree(n);

            exit(EXIT_SUCCESS);
        }
        i++;
	}
}

void print_tree(Node* node, string prefix, bool is_last) {
    if (!node) return;

    std::cout << prefix;
    std::cout << (is_last ? "└── " : "├── ");
    std::cout << node->token << std::endl;

    if (!node->childs.empty()) {
        for (int i = node->childs.size() - 1; i >= 0; --i) {
            bool child_is_last = (i == 0); // 마지막 자식인지 확인
            print_tree(node->childs[i], prefix + (is_last ? "    " : "│   "), child_is_last);
        }
    }
}

template<typename T>
void printStack(const std::stack<T>& stk) {
    std::stack<T> temp = stk;

    std::cout << "Stack elements: ";
    while (!temp.empty()) {
        std::cout << temp.top() << " ";
        temp.pop();
    }
    std::cout << std::endl;
}

void printStackString(const std::stack<Node *>& stk) {
    std::stack<Node *> temp = stk;

    std::cout << "Stack elements: ";
    while (!temp.empty()) {
        printf("%s ", temp.top()->token);
        temp.pop();
    }
    std::cout << std::endl;
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
    if (strcmp(str, "FDECL") == 0) return FDECL;
    if (strcmp(str, "ARG") == 0) return ARG;
    if (strcmp(str, "MOREARGS") == 0) return MOREARGS;
    if (strcmp(str, "BLOCK") == 0) return BLOCK;
    if (strcmp(str, "STMT") == 0) return STMT;
    if (strcmp(str, "COND") == 0) return COND;
    if (strcmp(str, "_COND") == 0) return _COND;
    if (strcmp(str, "ELSE") == 0) return ELSE;
    if (strcmp(str, "RETURN") == 0) return RETURN;
    return ERROR;
}