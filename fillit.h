/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:28:51 by pmigeon           #+#    #+#             */
/*   Updated: 2018/12/03 17:31:23 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include <stdlib.h>

typedef    struct s_node
{
	uint16_t	tertimino;
	char		id;
	struct s_node	*next;
}    t_node;

int        ft_squrt(int size);
void    solve(char **str);
void    ft_strshift(char *str, unsigned int n);
int        check_row1(char *str);
int        check_col1(char *str);
void    ft_strrevolve(char *str, unsigned int wide, unsigned int tall);
int        check_shape(char *str);
int        check_piece(char *str);
int        valid_input(int fd, char **str);
int        main(int argc, char **argv);

# endif
