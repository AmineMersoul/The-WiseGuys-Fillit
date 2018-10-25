/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:46:27 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/25 20:14:52 by amersoul         ###   ########.fr       */
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
	int				count;

	count = 0;
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
			if(ft_strlen(line) != 0)
			{
				printf("not a valid file should have empty line betwin tetros\n");
				return (NULL);
			}
			if(count != 4)
			{
				printf("not a valid tetros should have 4 tetri\n");
				return (NULL);
			}
			count = 0;
			if (!tetros)
				tetros = ft_create_tetros(current->tetri_1, current->tetri_2, current->tetri_3, current->tetri_4);
			else
				ft_add_tetros(&tetros, current);
			if (!ft_valid_tetros(tetros))
			{
				printf("not a valid tetrimino\n");
				return (NULL);
			}
			current = ft_create_tetros(NULL, NULL, NULL, NULL);
		}
		else
		{
			if(ft_strlen(line) != 4)
			{
				printf("not a valid file, line should have 4 characters\n");
				return (NULL);
			}
		}
		while (line[col] != '\0')
		{
			if (col > 3)
			{
				printf("tetrimino should have only 4 characters per line\n");
				return (NULL);
			}
			if (line[col] == '#')
			{
				count++;
				ft_add_tetri(&current, ft_create_tetri(row, col));
			}
			else if(line[col] != '.')
			{
				printf("tetrimino should have only '#' or '.' characters\n");
				return (NULL);
			}
			col++;
		}
		if (col != 0 && col != 4)
		{
			printf("tetrimino should have only 4 characters per line\n");
			return (NULL);
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
		if (ft_valid_tetros(tetros))
			printf("valid tetros ^-^\n");
		else
			printf("invalid tetros !\n");
		printf("row=%d, col=%d\n",tetros->tetri_1->row,tetros->tetri_1->col);
		printf("row=%d, col=%d\n",tetros->tetri_2->row,tetros->tetri_2->col);
		printf("row=%d, col=%d\n",tetros->tetri_3->row,tetros->tetri_3->col);
		printf("row=%d, col=%d\n\n",tetros->tetri_4->row,tetros->tetri_4->col);
		tetros = tetros->next;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int fd;
		char *file_name1 = argv[1];
		t_tetros *tetros;

		fd = open(file_name1, O_RDONLY);
		if (fd == -1)
		{
			printf("cant read %s\n", file_name1);
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
