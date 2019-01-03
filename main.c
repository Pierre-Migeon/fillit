/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:10:42 by pmigeon           #+#    #+#             */
/*   Updated: 2019/01/02 14:15:47 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "./libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

void	normalize(char *str)
{
	int i;
	int j;
	int swit;
	int yoffset;
	int xoffset;

	i = -1;
	swit = -1;
	while (i++ < 3)
	{
		j = i;
		while (j <= 20)
		{
			if (str[j] == '#')
			{
				if (swit == -1 && swit++)
				{
					xoffset = i;
					yoffset = j / 5;
					printf("xoffset is %i j is %i yoffset is %i\n", xoffset, j, yoffset);
				}
				if (xoffset > 0 || yoffset > 0)
				{
					str[j] = '.';
					str[j - xoffset - yoffset*5] = '#';
				}
			}
			j += 5;
		}
	}
}

int	check_shape(char *str)
{
	int i;
	int touch;

	i = 0;
	touch = 0;
	while (i < 22)
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
		normalize(str[i]);
		ft_putstr(str[i]);
		++i;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int 	fd;
	char 	**stored_array;

	if (!(stored_array = (char **)malloc(sizeof(char *) * 26)))
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
/*
	ft_normalize(stored_array)
*/
	return (0);
}
