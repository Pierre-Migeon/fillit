# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/22 15:01:58 by ghdesfos          #+#    #+#              #
#    Updated: 2019/02/02 16:31:24 by pmigeon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = ./src/check_input.c\
		./src/conversion_functions.c\
		./src/diverse_functions.c\
		./src/diverse_functions_2.c\
		./src/diverse_functions_3.c\
		./src/main.c\
		./src/print.c\
		./src/shift_input_to_right_position.c
OBJ = $(SRC:.c=.o)
FLAGS =-Wall -Wextra -Werror
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
