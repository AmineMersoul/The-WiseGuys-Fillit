/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetros_ftl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 16:53:58 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/29 10:55:18 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void		ft_move_tetros_ftl(t_tetros **tetros)
{
	t_tetros *current;

	current = *tetros;
	while (current)
	{
		while (1)
		{
			if ((current->tetri_1->row - 1 < 0) || (current->tetri_2->row - 1 < 0) || (current->tetri_3->row - 1 < 0) || (current->tetri_4->row - 1 < 0))
				break ;
			current->tetri_1->row -= 1;
			current->tetri_2->row -= 1;
			current->tetri_3->row -= 1;
			current->tetri_4->row -= 1;
		}
		while (1)
		{
			if ((current->tetri_1->col - 1) || (current->tetri_2->col - 1)
			|| (current->tetri_3->col - 1) || (current->tetri_4->col - 1))
				break ;
			current->tetri_1->col -= 1;
			current->tetri_2->col -= 1;
			current->tetri_3->col -= 1;
			current->tetri_4->col -= 1;
		}
		current = current->next;
	}
}
