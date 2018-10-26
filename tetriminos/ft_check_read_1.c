/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_read_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:25:42 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/26 12:46:27 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int	ft_check_read_1(char *line, t_tetros *current)
{
	if (ft_strlen(line) != 0)
		return (0);
	if (!ft_valid_tetros(current))
		return (0);
	return (1);
}
