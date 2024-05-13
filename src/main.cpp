#include "SLR.h"

// main
int main(int argc, char **argv)
{
	// check argument count
	// program name and input file require
	if (argc != 2)
	{
		fprintf(stderr, "Input one file!!\n");
		return EXIT_FAILURE;
	}

	// check and read input file
	char *token_stream = read_file(argv[1]);

	if (!token_stream)
	{
		perror(argv[1]);
		return EXIT_FAILURE;
	}

	// split file content to string array.
	int token_num;
	char **tokens = split_string(token_stream, &token_num);

	// // debug code
	// for (int i = 0; i < token_num; i++)
	// 	printf("[%d]: %s\n", i, tokens[i]);
	
	free(token_stream);

	// parsing start
	SLR_parsing(tokens, token_num);

	return 0;
}