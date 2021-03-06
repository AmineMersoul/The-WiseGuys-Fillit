/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_read_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 11:02:04 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/26 12:46:45 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		ft_check_read_3(char *line, int row)
{
	if ((row != 4 && ft_strlen(line) != 4))
		return (0);
	if (ft_strlen(line) != 0 && ft_strlen(line) != 4)
		return (0);
	return (1);
}
