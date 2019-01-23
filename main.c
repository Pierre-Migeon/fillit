/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:10:42 by pmigeon           #+#    #+#             */
/*   Updated: 2019/01/22 20:20:44 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	play_piece(uint16_t *board, int boardsize, t_mino *pieces)
{
	int			row;
	int			prow;
	uint16_t		mask;

	row = pieces->y;
	prow = 0;
	while (row < boardsize && prow < 4)
	{
		mask = genmask(prow, 1, boardsize);
		board[row] ^= (((pieces->tertimino & mask) << 4*prow)  >> pieces->x);
		++prow;
		++row;
	}
}

int		piece_fit(uint16_t *board, int boardsize, t_mino *pieces)
{
	int 		row;
	int			prow;
	uint16_t 	pmask;
	uint16_t	rowmask;

	row = pieces->y;
	prow = 0;
	while (prow < 4)
	{
		pmask = genmask(prow, 1, boardsize);
		if (row == boardsize)
			if ((((pieces->tertimino & pmask)) << 4*prow) >> pieces->x)
				return (0);
		if (board[row] & ((((pieces->tertimino & pmask)) << 4*prow) >> pieces->x))
			return (0);
		rowmask = genmask(0, 0, boardsize);
		if ((board[row] | ((((pieces->tertimino & pmask)) << 4*prow) >> pieces->x)) & rowmask)
			return (0);
		++prow;
		++row;
	}
	return (1);
}


int		retfunc(uint16_t *board, int boardsize, t_mino *pieces)
{
	play_piece(board, boardsize, pieces);
	return (1);
}

int	r_solve(int boardsize, t_mino *pieces, uint16_t *board)
{
	if (!pieces->tertimino)
	{
		//ft_putstr(convert_to_string(boardsize, t_mino_rewinder(pieces - 1)));
		return (1);
	}
	while (pieces->y < boardsize)
	{
		pieces->x = 0;
		while (pieces->x < boardsize)
		{
			if (piece_fit(board, boardsize, pieces))
			{
				play_piece(board, boardsize, pieces);
				print_board(board, boardsize);
				if (r_solve(boardsize, pieces + 1, board))
					return (1); //retfunc(board, boardsize, pieces));
				play_piece(board, boardsize, pieces);
				if (pieces->tertimino == (pieces + 1)->cache && ((pieces + 1)->x == boardsize - 1) && ((pieces + 1)->y == boardsize - 1))
					return (0);
			}
			pieces->x++;
		}
		pieces->y++;
	}
	pieces->y = 0;
	pieces->cache = pieces->tertimino;
	return (0);
}

int	edge_check(int boardsize, uint16_t board[16])
{
	int i;

	i = boardsize - 1;
	if (board[i] != 0)
		return (0);
	while (i >= 0)
	{
		if (((board[i] & ((uint16_t)1 << (16 - boardsize))) && 1) != 0)
			return (0);
		--i;
	}
	return (1);
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

void	solve(char **str)
{
	int 		i;
	int 		boardsize[2];
	t_mino		pieces[27];
	char		alpha_id;
	uint16_t	board[16] = {0};

	alpha_id = 'A';
	i = 0;
	while(str[i])
		++i;
	boardsize[0] = frt(4*i);
	boardsize[1] = 16;
	pieces[i].tertimino = 0;
	while (--i >= 0)
	{
		pieces[i].tertimino = convert_to_binary(str[i]);
		pieces[i].x = 0;
		pieces[i].y = 0;
		pieces[i].id = alpha_id + i;
	}
	while (boardsize[1] >= boardsize[0])
	{
		if (r_solve(boardsize[1], pieces, board) == 1)
		{
			if (edge_check(boardsize[1], board))
			{
				clear_board(board);
				boardsize[1]--;
			}
			else
			{	
				ft_putstr(convert_to_string(boardsize[1], pieces));
				break;
			}
		}
		else
		{
			clear_board(board);
			r_solve(++boardsize[1], pieces, board);
			ft_putstr(convert_to_string(boardsize[1], pieces));
			break;
		}
	}
}

int		main(int argc, char **argv)
{
	int 		fd;
	char 		**stored_array;

	if (!(stored_array = (char **)ft_memalloc(sizeof(char *) * 26)))
		return (1);
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (1);
	if (valid_input(fd, stored_array) == 1)
	{
		ft_putstr("error");
		return (1);
	}
	solve(stored_array);
	return (0);
}
