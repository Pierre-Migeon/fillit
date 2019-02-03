/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:28:51 by pmigeon           #+#    #+#             */
/*   Updated: 2019/02/02 16:29:28 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAXBOARDSIZE 16

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct		s_mino
{
	uint16_t		tetromino;
	char			id;
	int				x;
	int				y;
	int				boardsize[2];
	struct s_mino	*last;
}					t_mino;

int					check_shape(char *str);
int					check_piece(char *str);
int					valid_input(int fd, char **str);
uint16_t			convert_to_binary(char *str);
char				*convert_to_string(int boardsize, t_mino *pieces);
void				makedots(char *str, int length, int boardsize);
int					frt(int x);
uint16_t			genmask(int row, int on, int boardsize);
void				print_binary(uint16_t row, int boardsize);
void				ft_strshift(char *str, unsigned int n);
int					check_row1(char *str);
int					check_col1(char *str);
void				ft_strrevolve(char *str, unsigned int wide, \
					unsigned int tall);
void				play_piece(uint16_t *board, int boardsize, t_mino *pieces);
int					piece_fit(uint16_t *board, int boardsize, t_mino *pieces);
int					r_solve(int boardsize, t_mino *pieces, uint16_t *board);
void				solve(t_mino *pieces, uint16_t board[16]);
void				clear_board(uint16_t board[16]);
void				freethem(char **str);
t_mino				*findlast(t_mino pieces[27], int i);
t_mino				*piece_gen(char **str, t_mino pieces[27]);
int					retfunc(t_mino *pieces, int boardsize);
int					error(int i, char **stored_array);

#endif
