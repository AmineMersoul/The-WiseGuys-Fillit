/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_read_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 10:25:42 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/30 16:43:49 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int	ft_check_read_1(t_tetros *current)
{
	if (!ft_valid_tetros(current))
		return (0);
	return (1);
}
