/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_tetros_arr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 09:44:01 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/31 09:44:50 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

void		ft_remove_tetros_arr(t_tetros *tetros, int *arr, int size)
{
	arr[tetros->tetri_1->row * size + tetros->tetri_1->col] = 0;
	arr[tetros->tetri_2->row * size + tetros->tetri_2->col] = 0;
	arr[tetros->tetri_3->row * size + tetros->tetri_3->col] = 0;
	arr[tetros->tetri_4->row * size + tetros->tetri_4->col] = 0;
}
