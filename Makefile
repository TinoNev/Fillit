# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 11:10:26 by tlaberro          #+#    #+#              #
#    Updated: 2018/01/18 14:53:38 by tlaberro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all,clean,fclean,re

CC = /usr/bin/gcc

RM = /bin/rm

NAME = fillit

SRC = ./fillit.c\
	  ./ft_annexe.c\
	  ./ft_annexe_two.c\
	  ./ft_atoibin.c\
	  ./ft_backtracking.c\
	  ./ft_backtracking_support.c\
	  ./ft_backtracking_support2.c\
	  ./ft_checkplace.c\
	  ./ft_convertstr.c\
	  ./ft_destvalue.c\
	  ./ft_display.c\
	  ./ft_error.c\
	  ./ft_isvalid.c\
	  ./ft_tabvalue.c\
	  ./ft_tetrinew.c\

OBJ = $(patsubst %.c,%.o,$(SRC))

LIBD = ./Libft/

LIBFT = $(LIBD)libft.a

CFLAGS = -Wall -Wextra -Werror
HEADER = ./fillit.h

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) $(LIBD) Makefile
	@$(MAKE) -C $(LIBD)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -I$(LIBD) -c $< -o $@

clean:
	@$(RM) -f $(OBJ)
	@$(MAKE) -C $(LIBD) clean

fclean: clean
	@$(RM) -f $(NAME)
	@$(MAKE) -C $(LIBD) fclean

re: fclean all
