/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:46:27 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/26 11:33:24 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetros	*ft_read_tetriminos(int const fd)
{
	t_tetros		*tetros;
	t_tetros		*current;
	char			*line;
	int				row;
	int				col;
	int				count;

	count = 0;
	row = 0;
	tetros = NULL;
	current = ft_create_tetros(NULL, NULL, NULL, NULL);
	while (get_next_line(fd, &line))
	{
		if (row == 5)
			row = 0;
		if (row == 4)
		{
			if (!ft_check_read_1(line, count, current))
				return (NULL);
			count = 0;
			if (!tetros)
				tetros = ft_create_tetros(current->tetri_1, current->tetri_2, current->tetri_3, current->tetri_4);
			else
				ft_add_tetros(&tetros, current);
			current = ft_create_tetros(NULL, NULL, NULL, NULL);
		}
		if (!ft_check_read_3(line, row))
			return (NULL);
		col = 0;
		while (line[col] != '\0')
		{
			if (!ft_check_read_2(col, line[col]))
				return (NULL);
			if (line[col] == '#')
			{
				count++;
				ft_add_tetri(&current, ft_create_tetri(row, col));
			}
			col++;
		}
		row++;
	}
	if (row != 5)
	{
		printf("invalid file should have 2 empty line at the end of the file\n");
		return (NULL);
	}
	return (tetros);
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
			return (-1);
		ft_print_tetriminos(tetros);
		return (0);
	}
	printf("Usage : ./tetriminos.out <filename>\n");
	return (-1);
}
