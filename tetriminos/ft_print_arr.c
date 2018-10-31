/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 09:57:43 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/31 09:58:21 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void		ft_print_arr(int *arr, int size)
{
	char	*print;
	int		i;

	print = ".ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	i = 0;
	while (i < size * size)
	{
		if (i % size == 0 && i != 0)
			ft_putstr("\n");
		ft_putchar(print[arr[i]]);
		i++;
	}
	ft_putstr("\n");
}
