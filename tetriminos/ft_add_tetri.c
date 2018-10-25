/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_tetri.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:37:56 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/25 12:34:10 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int	ft_add_tetri(t_tetros **tetros, t_tetri *tetri)
{
	if (!(*tetros)->tetri_1)
	{
		(*tetros)->tetri_1 = tetri;
		return (1);
	}
	if (!(*tetros)->tetri_2)
	{
		(*tetros)->tetri_2 = tetri;
		return (1);
	}
	if (!(*tetros)->tetri_3)
	{
		(*tetros)->tetri_3 = tetri;
		return (1);
	}
	if (!(*tetros)->tetri_4)
	{
		(*tetros)->tetri_4 = tetri;
		return (1);
	}
	return (0);
}
