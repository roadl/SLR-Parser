#include "SLR.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Input one file!!\n");
		return EXIT_FAILURE;
	}

	char *token_stream = read_file(argv[1]);

	if (!token_stream)
	{
		perror(argv[1]);
		return EXIT_FAILURE;
	}

	int token_num;
	char **tokens = split_string(token_stream, &token_num);

	for (int i = 0; i < token_num; i++)
		printf("[%d]: %s\n", i, tokens[i]);

	return EXIT_SUCCESS;
}