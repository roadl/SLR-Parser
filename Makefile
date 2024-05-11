CC = gcc
CFLAGS = 
LDIR = ./include
HEADER = SLR.h
SDIR = ./
SRCS = main.c parseFile.c SLR.c stack.c init.c
OBJS = $(SRCS:.c=.o)
NAME = syntax_analyzer

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $^ -o $@ -I$(LDIR)

re: fclean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean
