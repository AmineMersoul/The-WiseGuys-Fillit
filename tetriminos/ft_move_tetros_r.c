/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetros_r.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:50:42 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/30 17:10:10 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int			ft_move_tetros_r(t_tetros *tetros, int size)
{
	if ((tetros->tetri_1->col + 1 == size) || (tetros->tetri_2->col + 1 == size)
	|| (tetros->tetri_3->col + 1 == size) || (tetros->tetri_4->col + 1 == size))
		return (0);
	tetros->tetri_1->col += 1;
	tetros->tetri_2->col += 1;
	tetros->tetri_3->col += 1;
	tetros->tetri_4->col += 1;
	return (1);
}
