# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlaberro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 11:10:26 by tlaberro          #+#    #+#              #
#    Updated: 2017/11/28 11:47:40 by tlaberro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAG = -Wall\
	   -Werror\
	   -Wextra\
	   -o\

SRC = main.c\
	  ft_display.c\
	  Libft/libft.a

INC = include.h\

all:
	@gcc $(FLAG) $(NAME) -I $(INC) $(SRC)

clean:
	@rm -rf $(NAME)

fclean: clean

re: fclean all
