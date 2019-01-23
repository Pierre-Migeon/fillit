/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_input_to_right_position.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:38:56 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/01/22 15:31:29 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
