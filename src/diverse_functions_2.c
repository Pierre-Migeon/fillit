/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diverse_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 18:24:48 by pmigeon           #+#    #+#             */
/*   Updated: 2019/01/28 14:27:11 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		retfunc(t_mino *pieces, int boardsize)
{
	pieces->y = boardsize;
	pieces->x = boardsize;
	return (0);
}

void	clear_board(uint16_t board[16])
{
	int i;

	i = 0;
	while (i < 16)
	{
		board[i] = 0;
		i++;
	}
}

t_mino	*findlast(t_mino pieces[27], int i)
{
	int j;

	j = i - 1;
	while (j >= 0)
	{
		if (pieces[j].tertimino == pieces[i].tertimino)
			return (&pieces[j]);
		--j;
	}
	return (0);
}

t_mino	*piece_gen(char **str, t_mino pieces[27])
{
	int		i;
	int		boardsize[2];
	char	alpha_id;

	alpha_id = 'A';
	i = 0;
	while (str[i])
		++i;
	boardsize[0] = frt(4 * i);
	boardsize[1] = 16;
	i = -1;
	while (str[++i])
	{
		pieces[i].tertimino = convert_to_binary(str[i]);
		pieces[i].x = 0;
		pieces[i].y = 0;
		pieces[i].id = alpha_id++;
		pieces[i].last = findlast(pieces, i);
		free(str[i]);
	}
	pieces[i].tertimino = 0;
	pieces[0].boardsize[0] = boardsize[0];
	pieces[0].boardsize[1] = boardsize[1];
	return (pieces);
}

void	freethem(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
