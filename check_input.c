/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:37:29 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/01/22 15:30:31 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		++i;
	}
	str[i] = NULL;
	return (0);
}
