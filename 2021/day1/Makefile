# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/13 09:53:50 by sbienias          #+#    #+#              #
#    Updated: 2021/05/13 09:53:50 by sbienias         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

SRC = main.c

BONUS = main2.c

OBJS = $(SRC:.c=.o)
CFLAGS = -Wall -Werror -Wextra
NAME = advent
LIBFTPATH = ../libft
LIBRARY = libft.a

all: $(LIBRARY) $(NAME)

$(LIBRARY):
	make -C $(LIBFTPATH)

$(NAME): $(SRC) 
	$(CC) -g $(CFLAGS) $(SRC) -L $(LIBFTPATH) -lft -o $(NAME)

bonus: $(BONUS)
	$(CC) -g $(CFLAGS) $(BONUS) -L $(LIBFTPATH) -lft

clean:
	/bin/rm -f $(OBJS) a.out

fclean: clean
	/bin/rm -f $(NAME) $(LIBRARY)
	make -C $(LIBFTPATH) fclean

re: fclean all
