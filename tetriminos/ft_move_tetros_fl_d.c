/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetros_fl_d.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:54:25 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/31 09:30:58 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int			ft_move_tetros_fl_d(t_tetros *tetros, int size)
{
	while (1)
	{
		if ((tetros->tetri_1->col - 1 < 0) || (tetros->tetri_2->col - 1 < 0)
		|| (tetros->tetri_3->col - 1 < 0) || (tetros->tetri_4->col - 1 < 0))
			break ;
		tetros->tetri_1->col -= 1;
		tetros->tetri_2->col -= 1;
		tetros->tetri_3->col -= 1;
		tetros->tetri_4->col -= 1;
	}
	if ((tetros->tetri_1->row + 1 == size) || (tetros->tetri_2->row + 1 == size)
	|| (tetros->tetri_3->row + 1 == size) || (tetros->tetri_4->row + 1 == size))
		return (0);
	tetros->tetri_1->row += 1;
	tetros->tetri_2->row += 1;
	tetros->tetri_3->row += 1;
	tetros->tetri_4->row += 1;
	return (1);
}
