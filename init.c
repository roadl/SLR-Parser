#include "SLR.h"

void init_CFG(CFG *cfg)
{
    FILE *file = fopen("CFG.txt", "r");
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
        //printf("rhs: %s\n", rhs);
        token = strtok(rhs, " ");
        while (token != NULL) {
            cfg[count].RHS[size] = strdup(token);
            token = strtok(NULL, " ");
            //printf("%s\n", token);
            size++;
        }
        cfg[count].size = size;

        count++;
    }

    // 파일 닫기
    fclose(file);

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