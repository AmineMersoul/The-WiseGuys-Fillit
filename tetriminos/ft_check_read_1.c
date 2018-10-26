/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_read_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:25:42 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/26 10:54:36 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int	ft_check_read_1(char *line, int count, t_tetros *current)
{
	if (ft_strlen(line) != 0)
	{
		printf("not a valid file should have empty line betwin tetros\n");
		return (0);
	}
	if (count != 4)
	{
		printf("not a valid tetros should have 4 tetri\n");
		return (0);
	}
	if (!ft_valid_tetros(current))
	{
		printf("not a valid tetrimino\n");
		return (0);
	}
	return (1);
}
