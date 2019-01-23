/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:37:44 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/01/22 15:31:19 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_binary(uint16_t row, int boardsize)
{
	int bit;
	int i;

	bit = 32768;
	i = 0;
	while (bit && i < boardsize)
	{
		ft_putchar('0' + ((bit & row) && 1));
		bit >>= 1;
		++i;
	}
}

void	print_board(uint16_t *board, int boardsize)
{
	int row;

	row = 0;
	while (row < boardsize)
	{
		print_binary(board[row++], boardsize);
		write(1, "\n", 1);
	}
	printf("That was the board boardsize of %i\n", boardsize);
}
