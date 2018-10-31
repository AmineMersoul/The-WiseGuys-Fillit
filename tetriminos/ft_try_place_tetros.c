/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_place_tetros.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 09:34:23 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/31 09:45:07 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int			ft_try_place_tetros(t_tetros *tetros, int *arr, int size, int count)
{
	if (!tetros)
		return (1);
	while (1)
	{
		if (ft_place_tetros(tetros, arr, size, count))
		{
			if (ft_try_place_tetros(tetros->next, arr, size, count + 1))
				return (1);
			else
				ft_remove_tetros_arr(tetros, arr, size);
		}
		if (ft_move_tetros_r(tetros, size))
			continue ;
		if (!ft_move_tetros_fl_d(tetros, size))
		{
			ft_move_tetros_ftl(&tetros);
			return (0);
		}
	}
	return (1);
}
