/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 09:35:34 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/31 09:36:45 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int			ft_place_tetros(t_tetros *tetros, int *arr, int size, int count)
{
	if (arr[tetros->tetri_1->row * size + tetros->tetri_1->col] != 0)
		return (0);
	if (arr[tetros->tetri_2->row * size + tetros->tetri_2->col] != 0)
		return (0);
	if (arr[tetros->tetri_3->row * size + tetros->tetri_3->col] != 0)
		return (0);
	if (arr[tetros->tetri_4->row * size + tetros->tetri_4->col] != 0)
		return (0);
	if ((tetros->tetri_1->row >= size) || (tetros->tetri_1->col >= size))
		return (0);
	if ((tetros->tetri_2->row >= size) || (tetros->tetri_2->col >= size))
		return (0);
	if ((tetros->tetri_3->row >= size) || (tetros->tetri_3->col >= size))
		return (0);
	if ((tetros->tetri_4->row >= size) || (tetros->tetri_4->col >= size))
		return (0);
	arr[tetros->tetri_1->row * size + tetros->tetri_1->col] = count;
	arr[tetros->tetri_2->row * size + tetros->tetri_2->col] = count;
	arr[tetros->tetri_3->row * size + tetros->tetri_3->col] = count;
	arr[tetros->tetri_4->row * size + tetros->tetri_4->col] = count;
	return (1);
}
