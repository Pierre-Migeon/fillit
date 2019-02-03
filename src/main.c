/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:10:42 by pmigeon           #+#    #+#             */
/*   Updated: 2019/02/02 16:29:59 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	play_piece(uint16_t *board, int boardsize, t_mino *pieces)
{
	int			row;
	int			prow;
	uint16_t	mask;

	row = pieces->y;
	prow = 0;
	while (row < boardsize && prow < 4)
	{
		mask = genmask(prow, 1, boardsize);
		board[row] ^= (((pieces->tetromino & mask) << 4 * prow) >> pieces->x);
		++prow;
		++row;
	}
}

int		piece_fit(uint16_t *board, int boardsize, t_mino *pieces)
{
	int			row;
	int			prow;
	uint16_t	pmask;
	uint16_t	rowmask;

	row = pieces->y;
	prow = 0;
	while (prow < 4)
	{
		pmask = genmask(prow, 1, boardsize);
		if (row == boardsize)
			if ((((pieces->tetromino & pmask)) << 4 * prow) >> pieces->x)
				return (retfunc(pieces, boardsize));
		if (board[row] & ((((pieces->tetromino & pmask)) << 4 * prow) \
					>> pieces->x))
			return (0);
		rowmask = genmask(0, 0, boardsize);
		if ((board[row] | ((((pieces->tetromino & pmask)) << 4 * prow) \
						>> pieces->x)) & rowmask)
			return (0);
		++prow;
		++row;
	}
	return (1);
}

int		r_solve(int boardsize, t_mino *pieces, uint16_t *board)
{
	if (!pieces->tetromino)
		return (1);
	pieces->y = (pieces->last) ? pieces->last->y : 0;
	while (pieces->y < boardsize)
	{
		pieces->x = (pieces->last && pieces->last->y == pieces->y) \
					? pieces->last->x : 0;
		while (pieces->x < boardsize)
		{
			if (piece_fit(board, boardsize, pieces))
			{
				play_piece(board, boardsize, pieces);
				if (r_solve(boardsize, pieces + 1, board))
					return (1);
				play_piece(board, boardsize, pieces);
			}
			pieces->x++;
		}
		pieces->y++;
	}
	return (0);
}

void	solve(t_mino *pieces, uint16_t board[16])
{
	char *tmp;

	while (pieces[0].boardsize[1] >= pieces[0].boardsize[0] - 1)
	{
		if (r_solve(pieces[0].boardsize[1], pieces, board) == 1)
		{
			clear_board(board);
			pieces[0].boardsize[1]--;
		}
		else
		{
			clear_board(board);
			r_solve(++pieces[0].boardsize[1], pieces, board);
			tmp = convert_to_string(pieces[0].boardsize[1], pieces);
			ft_putstr(tmp);
			free(tmp);
			break ;
		}
	}
}

int		main(int argc, char **argv)
{
	int			fd;
	char		**stored_array;
	uint16_t	board[16];
	t_mino		pieces[27];

	if (!(stored_array = (char **)ft_memalloc(sizeof(char *) * 27)))
		return (1);
	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file\n");
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (error(0, stored_array));
	if (valid_input(fd, stored_array) == 1)
		return (error(1, stored_array));
	clear_board(board);
	solve(piece_gen(stored_array, pieces), board);
	free(stored_array);
	return (0);
}
