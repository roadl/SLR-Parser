#include "SLR.h"

void init_CFG(CFG *cfg)
{
	// cfg[0] 설정: CODE -> VDECL CODE
    cfg[0].LHS = strdup("CODE");
    cfg[0].size = 2;
    cfg[0].RHS = (char **)malloc(sizeof(char *) * cfg[0].size);
    cfg[0].RHS[0] = strdup("VDECL");
    cfg[0].RHS[1] = strdup("CODE");

    // cfg[1] 설정: CODE -> FDECL CODE
    cfg[1].LHS = strdup("CODE");
    cfg[1].size = 2;
    cfg[1].RHS = (char **)malloc(sizeof(char *) * cfg[1].size);
    cfg[1].RHS[0] = strdup("FDECL");
    cfg[1].RHS[1] = strdup("CODE");

    // cfg[2] 설정: CODE -> ''
    cfg[2].LHS = strdup("CODE");
    cfg[2].size = 1;
    cfg[2].RHS = (char **)malloc(sizeof(char *) * cfg[2].size);
    cfg[2].RHS[0] = strdup("");

    // cfg[3] 설정: VDECL -> vtype id semi
    cfg[3].LHS = strdup("VDECL");
    cfg[3].size = 3;
    cfg[3].RHS = (char **)malloc(sizeof(char *) * cfg[3].size);
    cfg[3].RHS[0] = strdup("vtype");
    cfg[3].RHS[1] = strdup("id");
    cfg[3].RHS[2] = strdup("semi");

    // cfg[4] 설정: VDECL -> vtype ASSIGN semi
    cfg[4].LHS = strdup("VDECL");
    cfg[4].size = 3;
    cfg[4].RHS = (char **)malloc(sizeof(char *) * cfg[4].size);
    cfg[4].RHS[0] = strdup("vtype");
    cfg[4].RHS[1] = strdup("ASSIGN");
    cfg[4].RHS[2] = strdup("semi");

    // cfg[5] 설정: ASSIGN -> id assign RHS
    cfg[5].LHS = strdup("ASSIGN");
    cfg[5].size = 3;
    cfg[5].RHS = (char **)malloc(sizeof(char *) * cfg[5].size);
    cfg[5].RHS[0] = strdup("id");
    cfg[5].RHS[1] = strdup("assign");
    cfg[5].RHS[2] = strdup("RHS");

    // cfg[6] 설정: RHS -> EXPR
    cfg[6].LHS = strdup("RHS");
    cfg[6].size = 1;
    cfg[6].RHS = (char **)malloc(sizeof(char *) * cfg[6].size);
    cfg[6].RHS[0] = strdup("EXPR");

    // cfg[7] 설정: RHS -> literal
    cfg[7].LHS = strdup("RHS");
    cfg[7].size = 1;
    cfg[7].RHS = (char **)malloc(sizeof(char *) * cfg[7].size);
    cfg[7].RHS[0] = strdup("literal");

    // cfg[8] 설정: RHS -> character
    cfg[8].LHS = strdup("RHS");
    cfg[8].size = 1;
    cfg[8].RHS = (char **)malloc(sizeof(char *) * cfg[8].size);
    cfg[8].RHS[0] = strdup("character");

    // cfg[9] 설정: RHS -> boolstr
    cfg[9].LHS = strdup("RHS");
    cfg[9].size = 1;
    cfg[9].RHS = (char **)malloc(sizeof(char *) * cfg[9].size);
    cfg[9].RHS[0] = strdup("boolstr");

	// cfg[10] 설정: EXPR -> E
    cfg[10].LHS = strdup("EXPR");
    cfg[10].size = 1;
    cfg[10].RHS = (char **)malloc(sizeof(char *) * cfg[10].size);
    cfg[10].RHS[0] = strdup("E");

    // cfg[11] 설정: E -> E addsub T
    cfg[11].LHS = strdup("E");
    cfg[11].size = 3;
    cfg[11].RHS = (char **)malloc(sizeof(char *) * cfg[11].size);
    cfg[11].RHS[0] = strdup("E");
    cfg[11].RHS[1] = strdup("addsub");
    cfg[11].RHS[2] = strdup("T");

    // cfg[12] 설정: E -> T
    cfg[12].LHS = strdup("E");
    cfg[12].size = 1;
    cfg[12].RHS = (char **)malloc(sizeof(char *) * cfg[12].size);
    cfg[12].RHS[0] = strdup("T");

    // cfg[13] 설정: T -> T multdiv F
    cfg[13].LHS = strdup("T");
    cfg[13].size = 3;
    cfg[13].RHS = (char **)malloc(sizeof(char *) * cfg[13].size);
    cfg[13].RHS[0] = strdup("T");
    cfg[13].RHS[1] = strdup("multdiv");
    cfg[13].RHS[2] = strdup("F");

    // cfg[14] 설정: T -> F
    cfg[14].LHS = strdup("T");
    cfg[14].size = 1;
    cfg[14].RHS = (char **)malloc(sizeof(char *) * cfg[14].size);
    cfg[14].RHS[0] = strdup("F");

    // cfg[15] 설정: F -> ( E )
    cfg[15].LHS = strdup("F");
    cfg[15].size = 3;
    cfg[15].RHS = (char **)malloc(sizeof(char *) * cfg[15].size);
    cfg[15].RHS[0] = strdup("(");
    cfg[15].RHS[1] = strdup("E");
    cfg[15].RHS[2] = strdup(")");

    // cfg[16] 설정: F -> id
    cfg[16].LHS = strdup("F");
    cfg[16].size = 1;
    cfg[16].RHS = (char **)malloc(sizeof(char *) * cfg[16].size);
    cfg[16].RHS[0] = strdup("id");

    // cfg[17] 설정: F -> num
    cfg[17].LHS = strdup("F");
    cfg[17].size = 1;
    cfg[17].RHS = (char **)malloc(sizeof(char *) * cfg[17].size);
    cfg[17].RHS[0] = strdup("num");

    // cfg[18] 설정: FDECL -> vtype id lparen ARG rparen lbrace BLOCK RETURN rbrace
    cfg[18].LHS = strdup("FDECL");
    cfg[18].size = 9;
    cfg[18].RHS = (char **)malloc(sizeof(char *) * cfg[18].size);
    cfg[18].RHS[0] = strdup("vtype");
    cfg[18].RHS[1] = strdup("id");
    cfg[18].RHS[2] = strdup("lparen");
    cfg[18].RHS[3] = strdup("ARG");
    cfg[18].RHS[4] = strdup("rparen");
    cfg[18].RHS[5] = strdup("lbrace");
    cfg[18].RHS[6] = strdup("BLOCK");
    cfg[18].RHS[7] = strdup("RETURN");
    cfg[18].RHS[8] = strdup("rbrace");

    // cfg[19] 설정: ARG -> vtype id MOREARGS
    cfg[19].LHS = strdup("ARG");
    cfg[19].size = 3;
    cfg[19].RHS = (char **)malloc(sizeof(char *) * cfg[19].size);
    cfg[19].RHS[0] = strdup("vtype");
    cfg[19].RHS[1] = strdup("id");
    cfg[19].RHS[2] = strdup("MOREARGS");

	// cfg[20] 설정: ARG -> ''
	cfg[20].LHS = strdup("ARG");
    cfg[20].size = 1;
    cfg[20].RHS = (char **)malloc(sizeof(char *) * cfg[20].size);
    cfg[20].RHS[0] = strdup("");

    // cfg[21] 설정: MOREARGS -> comma vtype id MOREARGS
    cfg[21].LHS = strdup("MOREARGS");
    cfg[21].size = 4;
    cfg[21].RHS = (char **)malloc(sizeof(char *) * cfg[21].size);
    cfg[21].RHS[0] = strdup("comma");
    cfg[21].RHS[1] = strdup("vtype");
    cfg[21].RHS[2] = strdup("id");
    cfg[21].RHS[3] = strdup("MOREARGS");

    // cfg[22] 설정: MOREARGS -> ''
    cfg[22].LHS = strdup("MOREARGS");
    cfg[22].size = 1;
    cfg[22].RHS = (char **)malloc(sizeof(char *) * cfg[22].size);
    cfg[22].RHS[0] = strdup("");

    // cfg[23] 설정: BLOCK -> STMT BLOCK
    cfg[23].LHS = strdup("BLOCK");
    cfg[23].size = 2;
    cfg[23].RHS = (char **)malloc(sizeof(char *) * cfg[23].size);
    cfg[23].RHS[0] = strdup("STMT");
    cfg[23].RHS[1] = strdup("BLOCK");

    // cfg[24] 설정: BLOCK -> ''
    cfg[24].LHS = strdup("BLOCK");
    cfg[24].size = 1;
    cfg[24].RHS = (char **)malloc(sizeof(char *) * cfg[24].size);
    cfg[24].RHS[0] = strdup("");

    // cfg[25] 설정: STMT -> VDECL
    cfg[25].LHS = strdup("STMT");
    cfg[25].size = 1;
    cfg[25].RHS = (char **)malloc(sizeof(char *) * cfg[25].size);
    cfg[25].RHS[0] = strdup("VDECL");

    // cfg[26] 설정: STMT -> ASSIGN semi
    cfg[26].LHS = strdup("STMT");
    cfg[26].size = 2;
    cfg[26].RHS = (char **)malloc(sizeof(char *) * cfg[26].size);
    cfg[26].RHS[0] = strdup("ASSIGN");
    cfg[26].RHS[1] = strdup("semi");

    // cfg[27] 설정: STMT -> if lparen COND rparen lbrace BLOCK rbrace ELSE
    cfg[27].LHS = strdup("STMT");
    cfg[27].size = 8;
    cfg[27].RHS = (char **)malloc(sizeof(char *) * cfg[27].size);
    cfg[27].RHS[0] = strdup("if");
    cfg[27].RHS[1] = strdup("lparen");
    cfg[27].RHS[2] = strdup("COND");
    cfg[27].RHS[3] = strdup("rparen");
    cfg[27].RHS[4] = strdup("lbrace");
    cfg[27].RHS[5] = strdup("BLOCK");
    cfg[27].RHS[6] = strdup("rbrace");
    cfg[27].RHS[7] = strdup("ELSE");

    // cfg[28] 설정: STMT -> while lparen COND rparen lbrace BLOCK rbrace
    cfg[28].LHS = strdup("STMT");
    cfg[28].size = 7;
    cfg[28].RHS = (char **)malloc(sizeof(char *) * cfg[28].size);
    cfg[28].RHS[0] = strdup("while");
    cfg[28].RHS[1] = strdup("lparen");
    cfg[28].RHS[2] = strdup("COND");
    cfg[28].RHS[3] = strdup("rparen");
    cfg[28].RHS[4] = strdup("lbrace");
    cfg[28].RHS[5] = strdup("BLOCK");
    cfg[28].RHS[6] = strdup("rbrace");

    // cfg[29] 설정: COND -> boolstr COND'
    cfg[29].LHS = strdup("COND");
    cfg[29].size = 2;
    cfg[29].RHS = (char **)malloc(sizeof(char *) * cfg[29].size);
    cfg[29].RHS[0] = strdup("boolstr");
    cfg[29].RHS[1] = strdup("COND'");

	// cfg[30] 설정: COND' -> comp COND
	cfg[30].LHS = strdup("COND'");
    cfg[30].size = 2;
    cfg[30].RHS = (char **)malloc(sizeof(char *) * cfg[30].size);
    cfg[30].RHS[0] = strdup("comp");
    cfg[30].RHS[1] = strdup("COND");

    // cfg[31] 설정: COND' -> ''
    cfg[31].LHS = strdup("COND'");
    cfg[31].size = 1;
    cfg[31].RHS = (char **)malloc(sizeof(char *) * cfg[31].size);
    cfg[31].RHS[0] = strdup("");

    // cfg[32] 설정: ELSE -> else lbrace BLOCK rbrace
    cfg[32].LHS = strdup("ELSE");
    cfg[32].size = 4;
    cfg[32].RHS = (char **)malloc(sizeof(char *) * cfg[32].size);
    cfg[32].RHS[0] = strdup("else");
    cfg[32].RHS[1] = strdup("lbrace");
    cfg[32].RHS[2] = strdup("BLOCK");
    cfg[32].RHS[3] = strdup("rbrace");

    // cfg[33] 설정: ELSE -> ''
    cfg[33].LHS = strdup("ELSE");
    cfg[33].size = 1;
    cfg[33].RHS = (char **)malloc(sizeof(char *) * cfg[33].size);
    cfg[33].RHS[0] = strdup("");

    // cfg[34] 설정: RETURN -> return RHS semi
    cfg[34].LHS = strdup("RETURN");
    cfg[34].size = 3;
    cfg[34].RHS = (char **)malloc(sizeof(char *) * cfg[34].size);
    cfg[34].RHS[0] = strdup("return");
    cfg[34].RHS[1] = strdup("RHS");
    cfg[34].RHS[2] = strdup("semi");

	for (int i = 0; i < 35; i++)
	{
		printf("%s ->", cfg[i].LHS);
		for (int j = 0; j < cfg[i].size; j++)
		{
			printf(" %s", cfg[i].RHS[j]);
		}
		printf("\n");
	}
}

void init_table(int **table)
{

}