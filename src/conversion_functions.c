/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:46:31 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/02/02 16:26:19 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

uint16_t	convert_to_binary(char *str)
{
	uint16_t	number;
	int			bit;
	int			i;

	bit = 32768;
	i = 0;
	number = 0;
	while (bit && str[i])
	{
		if (str[i] != '\n')
		{
			if (str[i] == '#')
				number |= bit;
			bit >>= 1;
		}
		i++;
	}
	return (number);
}

char		*convert_to_string(int boardsize, t_mino *pieces)
{
	char		*out;
	int			piece;
	uint16_t	bit;
	int			i;
	int			j;

	piece = 0;
	out = ft_strnew(boardsize * (boardsize + 1));
	makedots(out, boardsize * (boardsize + 1), boardsize);
	while (pieces[piece].tetromino && (i = -1) == -1)
	{
		j = 0;
		bit = 32768;
		while (bit && ++i > -1)
		{
			if (i > 0 && i % 4 == 0)
				j += boardsize - 3;
			if (bit & pieces[piece].tetromino)
				out[j + i + pieces[piece].x \
					+ (pieces[piece].y * (boardsize + 1))] = pieces[piece].id;
			bit >>= 1;
		}
		++piece;
	}
	return (out);
}
