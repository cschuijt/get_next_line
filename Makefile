# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cschuijt <cschuijt@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/30 23:32:13 by cschuijt      #+#    #+#                  #
#    Updated: 2022/10/30 23:40:41 by cschuijt      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

BUFFER_SIZE=1024
FLAGS=-Werror -Wall -Wextra -D BUFFER_SIZE=$(BUFFER_SIZE)
NAME=get_next_line.a
OBJECTS=get_next_line.o get_next_line_utils.o
BONUS_OBJECTS=
HEADER=get_next_line.h

$(NAME) : $(OBJECTS)

all : $(NAME)

re : fclean all

clean :
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean :
	rm -f $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

# test : re
# 	cc libftprintf.a test.c -o test
# 	./test

get_next_line.o : get_next_line.c $(HEADER)
	$(CC) $(FLAGS) -c get_next_line.c
	ar rcs $(NAME) get_next_line.o

get_next_line_utils.o : get_next_line_utils.c $(HEADER)
	$(CC) $(FLAGS) -c get_next_line_utils.c
	ar rcs $(NAME) get_next_line_utils.o
