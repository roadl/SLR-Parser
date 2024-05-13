#include "SLR.h"

// get symbol enum by str
// ex) "COND" -> COND (type Symbol)
Symbol get_symbol(char *str);

// print tree by argument root node
void print_tree(Node* node, std::string prefix = "", bool is_last = true);
// print error (current state stack, parsing stack) and exit
void print_error(char **tokens, int spliter, int token_num);

// print stack functions
template<typename T>
void printStack(const stack<T> &stk);
void printNodeStack(const stack<Node *>& stk);

char *table[TABLE_ROW][TABLE_COL];  // parsing table
stack<int> state_stack;             // state stack
stack<Node *> parsing_stack;        // parsing stack (substring in spliter left)
int step;                           // parsing step, using error print

// Sn 을 실행함
// Stack에 n을 넣고 spliter 위치 오른쪽으로 증가
void shift(int *spliter, char *token, int n)
{
    //printf("S%d\n", n);

	state_stack.push(n);
    parsing_stack.push(new Node(token));
	(*spliter)++;
    step++;
}

// Rn 을 실행함
// Stack에서 cfg[n]번째 룰의 크기만큼 pop, cfg[n].LHS 추가
void reduce(CFG *cfg, int n)
{
	int size = cfg[n].size;
    Node *node = new Node(cfg[n].LHS);
    Node *temp;

    //printf("R%d\n", n);

	for (int i = 0; i < size; i++)
    {
		state_stack.pop();
        temp = parsing_stack.top();
        parsing_stack.pop();
        node->childs.push_back(temp);
        temp->parent = node;
    }

    parsing_stack.push(node);

    step++;
}

// GOTO action
// Execute after Reduce
void GOTO(int state)
{
    state = atoi(table[state][get_symbol(parsing_stack.top()->token)]);
    
    //printf("G%d\n", state);

    state_stack.push(state);

    step++;
}

void SLR_parsing(char **tokens, int token_num)
{
	CFG cfg[CFG_SIZE];
	int spliter = 0;

    // add init state
    state_stack.push(0);

    // init CFG, table (parsing from resource folder)
	init_CFG(cfg);
    init_table(table);

    // parsing loop
	while (spliter < token_num)
	{
        char *action;
        int state;

        // get current state, action, next state
        state = state_stack.top();
        action = table[state][get_symbol(tokens[spliter])];
        int next_state = atoi(action + 1);

        // // debug code
        // printf("Step%d state:%d, action:%s, spliter:%d\n", i, state, action, spliter);

        // printStack(state_stack);
        // printStack(parsing_stack);

        // if state is out of range, print error, exit
        if (next_state > TABLE_ROW)
        {
            cout << "Error occured at step " << step << ", No State " << next_state \ 
                << " in parsing table" << endl;
            print_error(tokens, spliter, token_num);
        }

        // check table first character
        // if s -> shift, r -> reduce and goto, acc -> accept and print tree, exit
        // else -> no action in table, error! print error, exit
        if (strncmp(action, "s", 1) == 0)
            shift(&spliter, tokens[spliter], atoi(action + 1));
        else if (strncmp(action, "r", 1) == 0)
        {
            reduce(cfg, atoi(action + 1));
            GOTO(state_stack.top());
        }
        else if (strcmp(action, "acc") == 0)
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
        else
        {
            cout << "Error occured at step " << step << ", No action in table[" \
                << state << "][" << tokens[spliter] << "]" << endl;
            print_error(tokens, spliter, token_num);
        }
    }
}

void print_error(char **tokens, int spliter, int token_num)
{
    printStack(state_stack);
    printNodeStack(parsing_stack);
    cout << tokens[spliter] << " | ";
    for (int i = spliter + 1; i < token_num; i++)
        cout << tokens[i] << " ";  
    cout << endl;

    Node *n = new Node("CODE");

    while (!parsing_stack.empty())
    {
        n->childs.push_back(parsing_stack.top());
        parsing_stack.pop();
    }

    print_tree(n);

    exit(EXIT_FAILURE);
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
    std::stack<T> reversedStack;

    // 원래 스택을 역순으로 복사
    while (!temp.empty()) {
        reversedStack.push(temp.top());
        temp.pop();
    }

    std::cout << "State Stack: ";
    
    // 역순으로 출력
    while (!reversedStack.empty()) {
        std::cout << reversedStack.top() << " ";
        reversedStack.pop();
    }

    cout << endl;
}

void printNodeStack(const std::stack<Node *>& stk) {
    std::stack<Node *> temp = stk;
    std::stack<string> reversedStack;

    // 원래 스택을 역순으로 복사
    while (!temp.empty()) {
        reversedStack.push(temp.top()->token);
        temp.pop();
    }

    std::cout << "Token Stack: ";
    
    // 역순으로 출력
    while (!reversedStack.empty()) {
        std::cout << reversedStack.top() << " ";
        reversedStack.pop();
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