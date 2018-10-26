/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_read_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:27:37 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/26 12:09:21 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int	ft_check_read_2(char c)
{
	if (c != '.' && c != '#')
	{
		printf("tetrimino should have only '#' or '.' characters\n");
		return (0);
	}
	return (1);
}
