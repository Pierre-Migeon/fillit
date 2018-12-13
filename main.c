/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:10:42 by pmigeon           #+#    #+#             */
/*   Updated: 2018/12/04 13:03:55 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void	valid_input()
{
	read(fd, ,)
	


}

int		main(int argc, char **argv)
{
	int fd;
		

	if (argc != 2)
	{
		ft_putchar("usage: ./fillit input_file");
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
			return (1)
	if (!(stored_array = valid_input(fd)))
	{
		ft_putchar("error");
		return (1);
	}
	ft_normalize(stored_array)


	return (0);
}
