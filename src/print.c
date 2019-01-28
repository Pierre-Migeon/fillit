/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:37:44 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/01/28 14:27:54 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

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
