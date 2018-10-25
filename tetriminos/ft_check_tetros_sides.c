/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetros_sides.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:04:55 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/25 19:11:01 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int	ft_check_tetros_sides(t_tetros *tetros)
{
	int	count;

	count = 0;
	count += ft_check_tetri_right(tetros);
	count += ft_check_tetri_left(tetros);
	count += ft_check_tetri_down(tetros);
	count += ft_check_tetri_top(tetros);
	return (count);
}
