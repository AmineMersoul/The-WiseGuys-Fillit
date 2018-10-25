/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_tetros.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 18:59:17 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/25 19:11:21 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		ft_valid_tetros(t_tetros *tetros)
{
	int count;

	count = 0;
	count += ft_check_tetros_sides(tetros);
	tetros = ft_create_tetros(tetros->tetri_2,
	tetros->tetri_1, tetros->tetri_3, tetros->tetri_4);
	count += ft_check_tetros_sides(tetros);
	tetros = ft_create_tetros(tetros->tetri_3,
	tetros->tetri_1, tetros->tetri_2, tetros->tetri_4);
	count += ft_check_tetros_sides(tetros);
	tetros = ft_create_tetros(tetros->tetri_4,
	tetros->tetri_1, tetros->tetri_2, tetros->tetri_3);
	count += ft_check_tetros_sides(tetros);
	if (count > 5)
		return (1);
	else
		return (0);
}
