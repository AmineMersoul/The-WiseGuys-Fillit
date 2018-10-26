/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_read_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:27:37 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/26 10:54:40 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int	ft_check_read_2(int col, char c)
{
	if (col > 3)
	{
		printf("tetrimino should have only 4 characters per line\n");
		return (0);
	}
	if (c != '.' && c != '#')
	{
		printf("tetrimino should have only '#' or '.' characters\n");
		return (0);
	}
	return (1);
}
