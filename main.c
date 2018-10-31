/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:46:27 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/31 10:02:31 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos/tetriminos.h"

int			main(int argc, char **argv)
{
	int			fd;
	t_tetros	*tetros;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putstr("error\n");
			return (-1);
		}
		tetros = ft_read_tetros(fd);
		if (!tetros)
		{
			ft_putstr("error\n");
			return (-1);
		}
		ft_reverse_tetros(&tetros);
		ft_move_tetros_ftl(&tetros);
		ft_solve_fillit(tetros);
		return (0);
	}
	ft_putstr("Usage : ./fillit <filename>\n");
	return (-1);
}
