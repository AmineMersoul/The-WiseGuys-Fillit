/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:46:27 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/25 13:02:03 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetros	*ft_read_tetriminos(int const fd)
{
	t_tetros 		*tetros;
	t_tetros 		*current;
	char 			*line;
	int 			row;
	int 			col;

	row = 0;
	tetros = NULL;
	current = ft_create_tetros(NULL, NULL, NULL, NULL);
	while(get_next_line(fd, &line))
	{
		col = 0;
		if (row == 5)
			row = 0;
		if (row == 4)
		{
			if (!tetros)
				tetros = ft_create_tetros(current->tetri_1, current->tetri_2, current->tetri_3, current->tetri_4);
			else
				ft_add_tetros(&tetros, current);
			current = ft_create_tetros(NULL, NULL, NULL, NULL);
		}
		while (line[col] != '\0')
		{
			if (line[col] == '#')
				ft_add_tetri(&current, ft_create_tetri(row, col));
			col++;
		}
		row++;
	}
	return (tetros);
}

void	ft_print_tetriminos(t_tetros *tetros)
{
	printf("*** printing tetriminos *** \n\n");
	while(tetros)
	{
		printf("row=%d, col=%d\n",tetros->tetri_1->row,tetros->tetri_1->col);
		printf("row=%d, col=%d\n",tetros->tetri_2->row,tetros->tetri_2->col);
		printf("row=%d, col=%d\n",tetros->tetri_3->row,tetros->tetri_3->col);
		printf("row=%d, col=%d\n\n",tetros->tetri_4->row,tetros->tetri_4->col);
		tetros = tetros->next;
	}
}

int main(void)
{
	int fd;
	char *file_name1 = "examples/example1.txt";
	t_tetros *tetros;

	fd = open(file_name1, O_RDONLY);
	if (fd == -1)
	{
		printf("cant read %s\n", file_name1);
		return (-1);
	}
	tetros = ft_read_tetriminos(fd);
	ft_print_tetriminos(tetros);
	return (0);
}
