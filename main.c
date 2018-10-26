/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:46:27 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/26 12:44:08 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetros	*ft_read_tetriminos(int const fd)
{
	t_tetros		*tetros;
	char			*line;
	int				row;

	row = 0;
	tetros = NULL;
	ft_add_tetros(&tetros, ft_create_tetros(NULL, NULL, NULL, NULL));
	while (get_next_line(fd, &line))
	{
		if (row == 5)
			row = 0;
		if (row == 4)
		{
			if (!ft_check_read_1(line, tetros))
				return (NULL);
			ft_add_tetros(&tetros, ft_create_tetros(NULL, NULL, NULL, NULL));
		}
		if (!ft_check_read_3(line, row)
		|| !ft_read_tetri_line(line, row, &tetros))
			return (NULL);
		row++;
	}
	if (row != 5)
		return (NULL);
	return (tetros->next);
}

void		ft_print_tetriminos(t_tetros *tetros)
{
	printf("*** printing tetriminos *** \n");
	while (tetros)
	{
		if (ft_valid_tetros(tetros))
			printf("\nvalid tetros ^-^\n");
		else
			printf("invalid tetros !\n");
		printf("row=%d, col=%d\n", tetros->tetri_1->row, tetros->tetri_1->col);
		printf("row=%d, col=%d\n", tetros->tetri_2->row, tetros->tetri_2->col);
		printf("row=%d, col=%d\n", tetros->tetri_3->row, tetros->tetri_3->col);
		printf("row=%d, col=%d\n", tetros->tetri_4->row, tetros->tetri_4->col);
		tetros = tetros->next;
	}
}

int			main(int argc, char **argv)
{
	int			fd;
	t_tetros	*tetros;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("cant read %s\n", argv[1]);
			return (-1);
		}
		tetros = ft_read_tetriminos(fd);
		if (!tetros)
		{
			printf("error\n");
			return (-1);
		}
		ft_print_tetriminos(tetros);
		return (0);
	}
	printf("Usage : ./tetriminos.out <filename>\n");
	return (-1);
}
