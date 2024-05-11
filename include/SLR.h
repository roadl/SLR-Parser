#ifndef SLR_H
# define SLR_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char *read_file(const char *input_file);
char **split_string(char *str, int *num_tokens);

#endif