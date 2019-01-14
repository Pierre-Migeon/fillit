/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:10:42 by pmigeon           #+#    #+#             */
/*   Updated: 2019/01/13 17:39:28 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"
#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

uint16_t	convert_to_binary(char *str)
{
	uint16_t number;
        int bit;
        int i;

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

int	frt(int x)
{ 
	if (x == 0 || x == 1) 
		return x;  
	int i = 1; 
	int result = 1; 
	while (result <= x) 
	{ 
		i++; 
		result = i * i; 
	}
	return (i - 1);
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

/*
void	move_piece(uint16_t *board, int boardsize, uint16_t pieces)
{
	
}
*/

uint16_t	genmask(int boardsize, int row)
{
	uint16_t mask;

	mask = 65535;
	mask >>= (16 - boardsize);
	mask <<= ((16 - boardsize) - boardsize*row);
	return (mask);
}

void	place_piece(uint16_t *board, int boardsize, t_mino *pieces)
{
	int			row;
	uint16_t	mask;

	row = pieces->y;
	while (row < boardsize)
	{
		mask = genmask(boardsize, row);
		board[row] |= ((pieces->tertimino & mask) >> pieces->x);
		++row;
	}
}

int	piece_fit(uint16_t *board, int boardsize, t_mino *pieces)
{
	int 		row;
	uint16_t 	mask;

	row = pieces->y;
	while (row < boardsize)
	{
		mask = genmask(boardsize, row);
		if (((pieces->tertimino & mask) >> pieces->x) == (((pieces->tertimino >> pieces->x) << pieces->x) & mask))
		{
			if (board[row] & ((pieces->tertimino & mask) >> pieces->x))
				return (0);
		}
		else
			return (0);
		++row;
	}
	return (1);
}

int	r_solve(int boardsize, t_mino *pieces, uint16_t *board)
{
	if (!pieces->tertimino)
	{
		print_board(board, boardsize);
		return (1);
	}
	while (pieces->y < boardsize)
	{
		pieces->x = 0;
		while (pieces->x < boardsize)
		{
			if (piece_fit(board, boardsize, pieces))
			{
				place_piece(board, boardsize, pieces);
				print_board(board, boardsize);
				if (r_solve(boardsize, pieces + 1, board))
					return (1);
				//move_piece(board, boardsize, pieces);
			}
			pieces->x++;
		}
		pieces->y++;
	}
	return (1);
}

void	solve(char **str)
{
	int 		i;
	int 		boardsize;
	t_mino		pieces[27];
	uint16_t	board[11] = {0};
	char		alpha_id;

	alpha_id = 'A';
	i = 0;
	while(str[i])
		++i;
	boardsize = frt(4*i);
	i = -1;
	while (str[++i])
	{
		pieces[i].tertimino = convert_to_binary(str[i]);
		pieces[i].x = 0;
		pieces[i].y = 0;
		pieces[i].id = alpha_id++;
	}
	pieces[i].tertimino = 0;
	while (boardsize <= 10)
	{
		if (r_solve(boardsize, pieces, board) == 1)
			break;
	}
}

void	ft_strshift(char *str, unsigned int n)
{
	char	*buf;
	int		len;

	if (!str)
		return ;
	len = ft_strlen(str);
	if ((n %= len) == 0 || !(buf = ft_strnew(len)))
		return ;
	ft_memcpy(buf, str + n, len - n);
	ft_memcpy(buf + len - n, str, n);
	ft_memcpy(str, buf, len);
	ft_strdel(&buf);
}

int	check_row1(char *str)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (str[i] == '#')
			return (0);
		++i;
	}
	return (1);
}

int	check_col1(char *str)
{
	int i;

	i = 0;
	while (i <= 15)
	{
		if (str[i] == '#')
			return (0);
		i += 5;
	}
	return (1);
}

void	ft_strrevolve(char *str, unsigned int wide, unsigned int tall)
{
	unsigned int	row;
	unsigned int	w;

	row = -1;
	while (++row < tall)
	{
		w = -1;
		while (++w < wide - 2)
			str[row * wide + w] = str[row * wide + w + 1];
		str[row * wide + w] = '.';
	}
}

int	check_shape(char *str)
{
	int i;
	int touch;

	i = 0;
	touch = 0;
	while (str[i] && i < 22)
	{
		if (str[i] == '#')
		{
			if (i % 5 < 3)
				if (str[i + 1] == '#')
					++touch;
			if ( i % 5 > 0)
				if (str[i - 1] == '#')
					++touch;
			if (i / 5 < 3)
				if (str[i + 5] == '#')
					++touch;
			if (i / 5 > 0)
				 if (str[i - 5] == '#')
					++touch;
		}
		++i;
	}
	return (touch == 6 || touch == 8);
}

int	check_piece(char *str)
{
	int hash;
	int dots;
	int i;

	hash = 0;
	i = 0;
	dots = 0;
	while (str[i])
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
			if (str[i] != '\n')
				return (1);
		if (str[i] != '#' && str[i] != '.' && str[i] != '\n')
			return (1);
		if (str[i] == '#')
			++hash;
		if (str[i] == '.')
			++dots;
		++i;
	}
	if (hash != 4 || i != 20 || dots != 12)
 		return (1);
	return (0);
}

int	valid_input(int fd, char **str)
{
	char 	buf[22];
	int 	bits_read;
	int 	i;

	i = 0;
	while ((bits_read = read(fd, buf, 21)) > 19 && i < 26) 
	{
		buf[20] = '\0';
		str[i] = ft_strdup(buf);
		if (check_piece(str[i]) == 1 || check_shape(str[i]) == 0)
			return (1);
		while (check_row1(str[i]))
			ft_strshift(str[i], 5);
		while (check_col1(str[i]))
			ft_strrevolve(str[i], 5, 4);
		convert_to_binary(str[i]);
		++i;
	}
	str[i] = NULL;
	return (0);
}

int		main(int argc, char **argv)
{
	int 	fd;
	char 	**stored_array;

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
