/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_tetros.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:37:22 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/25 12:31:20 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

t_tetros			*ft_create_tetros(const t_tetri *tetri_1,
	const t_tetri *tetri_2, const t_tetri *tetri_3, const t_tetri *tetri_4)
{
	t_tetros	*tetros;

	if (!(tetros = malloc(sizeof(t_tetros))))
		return (NULL);
	if (!tetri_1 || !tetri_2 || !tetri_3 || !tetri_4)
	{
		tetros->tetri_1 = NULL;
		tetros->tetri_2 = NULL;
		tetros->tetri_3 = NULL;
		tetros->tetri_4 = NULL;
		return (tetros);
	}
	tetros->tetri_1 = (t_tetri*)tetri_1;
	tetros->tetri_2 = (t_tetri*)tetri_2;
	tetros->tetri_3 = (t_tetri*)tetri_3;
	tetros->tetri_4 = (t_tetri*)tetri_4;
	tetros->next = NULL;
	return (tetros);
}
