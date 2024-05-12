#include "SLR.h"

void init_CFG(CFG *cfg)
{
    FILE *file = fopen("./resource/CFG.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    // 파일 읽기
    char line[100];
    int count = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        // 줄 끝에 개행 문자가 있는 경우 제거
        line[strcspn(line, "\n")] = 0;

        // LHS와 RHS 분리
        char *lhs = strtok(line, "->");
        char *rhs = strtok(NULL, "->");

        // 공백 제거
        lhs = strtok(lhs, " ");
        while (*rhs == ' ')
            rhs++;

        // CFG 구조체에 저장
        cfg[count].LHS = strdup(lhs);

        // RHS 토큰 분할 및 저장
        char *token;
        int size = 0;
        cfg[count].RHS = (char **)malloc(sizeof(char *) * 10);
        token = strtok(rhs, " ");
        if (strcmp(token, "''") == 0)
            token = NULL;
        while (token != NULL) {
            cfg[count].RHS[size] = strdup(token);
            token = strtok(NULL, " ");
            size++;
        }
        cfg[count].size = size;

        count++;
    }

    // 파일 닫기
    fclose(file);

	// for (int i = 0; i < 35; i++)
	// {
	// 	printf("%s ->", cfg[i].LHS);
    //     for (int j = 0; j < cfg[i].size; j++)
	// 	{
	// 		printf(" %s", cfg[i].RHS[j]);
	// 	}
	// 	printf("\n");
	// }
}

void init_table(char *table[TABLE_ROW][TABLE_COL])
{
    FILE *file = fopen("./resource/table.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    // 2차원 배열 동적 할당

    // 파일에서 테이블 읽어오기
    int row = 0;
    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        line[strlen(line) - 1] = '\0';
        strtok(line, "\t");
        int col = 0;
        char *token = strtok(NULL, "\t");
        while (token != NULL && strncmp(token, "\n", 1) != 0) {
            table[row][col] = strdup(token);
            col++;
            token = strtok(NULL, "\t");
        }
        row++;
    }
    table[TABLE_ROW - 1][TABLE_COL - 1] = strdup(" ");

    fclose(file);

    printf("%s\n", table[0][VDECL]);

    // printf("parsing done\n");

    // for (int i = 0; i < TABLE_ROW; i++)
    // {
    //     printf("[%d] ", i);
    //     for (int j = 0; j < TABLE_COL; j++)
    //     {
    //         printf("%d:%s ", j, table[i][j]);
    //     }
    //     printf("\n");
    // }
}