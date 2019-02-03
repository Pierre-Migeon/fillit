/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diverse_functions_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 16:16:58 by pmigeon           #+#    #+#             */
/*   Updated: 2019/02/02 16:27:18 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		error(int i, char **stored_array)
{
	(i == 0) ? free(stored_array) : freethem(stored_array);
	ft_putstr("error\n");
	return (-1);
}
