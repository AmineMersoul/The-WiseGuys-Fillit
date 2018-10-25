/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tetri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:37:20 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/25 11:22:03 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

t_tetri	*ft_create_tetri(const int row, const int col)
{
	t_tetri	*tetri;

	if (!(tetri = malloc(sizeof(t_tetri))))
		return (NULL);
	tetri->row = row;
	tetri->col = col;
	return (tetri);
}
