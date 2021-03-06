/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_empty_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 09:59:08 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/31 09:59:42 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void		ft_empty_arr(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size * size)
	{
		arr[i] = 0;
		i++;
	}
}
