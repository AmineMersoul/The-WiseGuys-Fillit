/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetros.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 09:37:17 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/31 09:56:09 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int			read_tetros_fun(int *row, char **line, t_tetros **tetros)
{
	if (*row == 5)
		*row = 0;
	if (*row == 4 && ft_strlen(*line) != 0)
		return (0);
	if (!ft_check_read_3(*line, *row)
	|| !ft_read_tetri_line(*line, *row, tetros))
		return (0);
	if (*row == 3)
	{
		if (!ft_check_read_1(*tetros))
			return (0);
		ft_add_tetros(tetros, ft_create_tetros(0, 0, 0, 0));
	}
	*row = *row + 1;
	return (1);
}

t_tetros	*ft_read_tetros(int const fd)
{
	t_tetros		*tetros;
	char			*line;
	int				row;

	row = 0;
	tetros = NULL;
	ft_add_tetros(&tetros, ft_create_tetros(NULL, NULL, NULL, NULL));
	while (get_next_line(fd, &line))
	{
		if (!read_tetros_fun(&row, &line, &tetros))
			return (NULL);
	}
	if (row != 4)
		return (NULL);
	return (tetros->next);
}
