/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_fillit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 10:00:27 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/31 10:00:50 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int			ft_solve_fillit(t_tetros *tetros)
{
	int	size;
	int	*arr;

	size = 2;
	arr = (int *)malloc(size * size * sizeof(int));
	ft_empty_arr(arr, size);
	while (!ft_try_place_tetros(tetros, arr, size, 1))
		size++;
	ft_print_arr(arr, size);
	return (1);
}
