/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:28:51 by pmigeon           #+#    #+#             */
/*   Updated: 2019/01/22 19:46:44 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct	s_mino
{
	uint16_t	tertimino;
	char		id;
	int		x;
	int		y;
	uint16_t	cache;
}				t_mino;

int				check_shape(char *str);
int				check_piece(char *str);
int				valid_input(int fd, char **str);

uint16_t		convert_to_binary(char *str);
char			*convert_to_string(int boardsize, t_mino *pieces);

void			makedots(char *str, int length, int boardsize);
int				frt(int x);
uint16_t		genmask(int row, int on, int boardsize);
t_mino			*t_mino_rewinder(t_mino *pieces);

void			print_binary(uint16_t row, int boardsize);
void			print_board(uint16_t *board, int boardsize);

void			ft_strshift(char *str, unsigned int n);
int				check_row1(char *str);
int				check_col1(char *str);
void			ft_strrevolve(char *str, unsigned int wide, unsigned int tall);

void			play_piece(uint16_t *board, int boardsize, t_mino *pieces);
int				piece_fit(uint16_t *board, int boardsize, t_mino *pieces);
int				r_solve(int boardsize, t_mino *pieces, uint16_t *board);
void			solve(char **str);
int				main(int argc, char **argv);

# endif
