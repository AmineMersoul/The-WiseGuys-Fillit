/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetri_left.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:43:46 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/25 18:44:13 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		ft_check_tetri_left(t_tetros *tetros)
{
	if (tetros->tetri_1->col > 0)
	{
		if ((tetros->tetri_1->col - 1 == tetros->tetri_2->col)
		&& (tetros->tetri_1->row == tetros->tetri_2->row))
			return (1);
		if ((tetros->tetri_1->col - 1 == tetros->tetri_3->col)
		&& (tetros->tetri_1->row == tetros->tetri_3->row))
			return (1);
		if ((tetros->tetri_1->col - 1 == tetros->tetri_4->col)
		&& (tetros->tetri_1->row == tetros->tetri_4->row))
			return (1);
	}
	return (0);
}
