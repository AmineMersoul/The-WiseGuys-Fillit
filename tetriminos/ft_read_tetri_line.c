/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_tetri_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:43:44 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/26 12:43:53 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int			ft_read_tetri_line(char *line, int row, t_tetros **tetros)
{
	while (*line && *line != '\0')
	{
		if (!ft_check_read_2(*line))
			return (0);
		if (*line == '#')
			if (!ft_add_tetri(tetros,
			ft_create_tetri(row, 4 - ft_strlen(line))))
				return (0);
		line++;
	}
	return (1);
}
