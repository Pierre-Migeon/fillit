# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 15:01:58 by ghdesfos          #+#    #+#              #
#    Updated: 2019/01/22 16:15:43 by pmigeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = check_input.c\
		conversion_functions.c\
		diverse_functions.c\
		main.c\
		print.c\
		shift_input_to_right_position.c
OBJ = $(SRC:.c=.o)
FLAGS =-g -Wall -Wextra -Werror
LIBFT_FOL = libft
LIBFT_NAME = ft
HEAD_FOL = .

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_FOL)
	gcc $(FLAGS) -L$(LIBFT_FOL) -l$(LIBFT_NAME) -o $@ $^ -I$(HEAD_FOL)

%.o: %.c fillit.h
	gcc $(FLAGS) -I$(HEAD_FOL) -c -o $@ $<

clean:
	/bin/rm -f $(OBJ)
	make clean -C $(LIBFT_FOL)

fclean: clean
	/bin/rm -f $(NAME)
	make fclean -C $(LIBFT_FOL)

re: fclean all
