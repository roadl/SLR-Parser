#include "SLR.h"

char *read_file(const char *input_file) {
    char *buffer = NULL;
    long length;
    FILE *file = fopen(input_file, "rb");

    if (file) {
        fseek(file, 0, SEEK_END);
        length = ftell(file);
        fseek(file, 0, SEEK_SET);
        buffer = (char *)malloc(length + 1);

        if (buffer) {
            fread(buffer, 1, length, file);
            buffer[length] = '\0'; // Null-terminate the string
        }

        fclose(file);
    }

    return buffer;
}

char **split_string(char *input_string, int *token_num) {
    // 문자열을 복사하여 변경하지 않고 사용
    const char *delimiter = " \n\t";
    char *input_copy = strdup(input_string); // 문자열 복사

    // 토큰 개수 세기
    char *token = strtok(input_copy, delimiter);
    int count = 0;
    while (token) {
        count++;
        token = strtok(NULL, delimiter);
    }

    // 토큰을 저장할 배열 동적 할당
    char **tokens = (char **)malloc((count + 1) * sizeof(char *));
    if (!tokens) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    // 다시 토큰화하여 배열에 저장
    strcpy(input_copy, input_string); // 다시 원래 문자열로 복사
    token = strtok(input_copy, delimiter);
    for (int i = 0; i < count; i++) {
        tokens[i] = strdup(token);
        token = strtok(NULL, delimiter);
    }
    tokens[count] = strdup("$");

    free(input_copy); // 복사된 문자열 메모리 해제
    *token_num = count + 1;
    return tokens;
}