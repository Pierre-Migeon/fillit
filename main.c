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


void	ft_print_piece(char *str)
{
	while(str)
		write(1, str++, 1);
}

void	valid_input(int fd, char **str)
{
	char 	buf[22];
	int 	bits_read;
	int 	i;

	i = 0;
	while ((bits_read = read(fd, buf, 21)) > 19 && i < 1) 
	{
		buf[21] = '\0';
		ft_putstr(buf);
		i++;
	}

}

int		main(int argc, char **argv)
{
	int 	fd;
	char 	**stored_array;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit input_file");
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
			return (1);
	valid_input(fd, stored_array);

/*	if (!(valid_input(fd, stored_array)))
	{
		ft_putchar("error");
		return (1);
	}
	ft_normalize(stored_array)
*/
	return (0);
}
