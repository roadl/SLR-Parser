CC = c++
CFLAGS = 
LDIR = ./include
HEADER = SLR.h
SDIR = ./src
SRCS = main.cpp parseFile.cpp SLR.cpp init.cpp
OBJS = $(SRCS:.c=.o)
NAME = syntax_analyzer

all: $(NAME)

$(NAME): $(addprefix $(SDIR)/, $(SRCS))
	$(CC) $(CFLAGS) $^ -o $@ -I$(LDIR)

re: fclean all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

.PHONY: all re clean fclean
