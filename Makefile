SHELL = /bin/sh
CC = gcc
FLAGS = -std=c99
CFLAGS = -Werror -Wall -Wextra -c -g

NAME = get_next_line.a
SOURCES = **\
BONUS = **\
HEADERS = get_next_line.h
OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJECTS = $(BONUS:.c=.o)

PREFIX = $(DESTDIR)/usr/local
BINDIR = $(PREFIX)/bin

all: $(NAME)

$(NAME): $(OBJECTS)
	ar	rcs $(NAME) $(OBJECTS)

$(OBJECT): $(SRC)
	$(CC)	$(FLAGS)	$(CFLAGS) -o	$(NAME)	$(OBJECTS)	$(HEADERS)

bonus: $(OBJECTS)	$(BONUS_OBJECTS)
	ar	rcs	$(NAME)	$(OBJECTS)	$(BONUS_OBJECTS)

clean:
	rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
	@echo	"[INFO] Library [$(NAME) removed!"

#Re-make everything.
re: fclean all

.PHONY:
	all clean fclean re
