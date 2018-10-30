/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:46:27 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/30 12:06:28 by amersoul         ###   ########.fr       */
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
	return (tetros->next);
}

int			move_tetros_right(t_tetros *tetros, int size)
{
	if ((tetros->tetri_1->col + 1 == size) || (tetros->tetri_2->col + 1 == size) || (tetros->tetri_3->col + 1 == size) || (tetros->tetri_4->col + 1 == size))
				return (0);
	tetros->tetri_1->col += 1;
	tetros->tetri_2->col += 1;
	tetros->tetri_3->col += 1;
	tetros->tetri_4->col += 1;
	return (1);
}

int			move_tetros_fl_d(t_tetros *tetros, int size)
{
	while (1)
	{
		if ((tetros->tetri_1->col - 1 < 0) || (tetros->tetri_2->col - 1 < 0)  || (tetros->tetri_2->col - 1 < 0) || (tetros->tetri_2->col - 1 < 0))
			break ;
		tetros->tetri_1->col -= 1;
		tetros->tetri_2->col -= 1;
		tetros->tetri_3->col -= 1;
		tetros->tetri_4->col -= 1;
	}
	if ((tetros->tetri_1->row + 1 == size) || (tetros->tetri_2->row + 1 == size) || (tetros->tetri_3->row + 1 == size) || (tetros->tetri_4->row + 1 == size))
				return (0);
	tetros->tetri_1->row += 1;
	tetros->tetri_2->row += 1;
	tetros->tetri_3->row += 1;
	tetros->tetri_4->row += 1;
	return (1);
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

void		print_arr(int *arr, int size)
{
	char *print = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0;
	while (i < size * size)
	{
		if (i % size == 0)
			printf("\n");
		printf("%c, ", print[arr[i]]);
		i++;
	}
	printf("\n");
}

int			place_tetros(t_tetros *tetros, int *arr, int size, int count)
{
	if (arr[tetros->tetri_1->row * size + tetros->tetri_1->col] != 0)
		return (0);
	if (arr[tetros->tetri_2->row * size + tetros->tetri_2->col] != 0)
		return (0);
	if (arr[tetros->tetri_3->row * size + tetros->tetri_3->col] != 0)
		return (0);
	if (arr[tetros->tetri_4->row * size + tetros->tetri_4->col] != 0)
		return (0);
	arr[tetros->tetri_1->row * size + tetros->tetri_1->col] = count;
	arr[tetros->tetri_2->row * size + tetros->tetri_2->col] = count;
	arr[tetros->tetri_3->row * size + tetros->tetri_3->col] = count;
	arr[tetros->tetri_4->row * size + tetros->tetri_4->col] = count;
	return (1);
}

void		remove_tetros_arr(t_tetros *tetros, int *arr, int size)
{
	arr[tetros->tetri_1->row * size + tetros->tetri_1->col] = 0;
	arr[tetros->tetri_2->row * size + tetros->tetri_2->col] = 0;
	arr[tetros->tetri_3->row * size + tetros->tetri_3->col] = 0;
	arr[tetros->tetri_4->row * size + tetros->tetri_4->col] = 0;
}

int			try_place_tetros(t_tetros *tetros, int *arr, int size, int count)
{
	//print_arr(arr, size);
	if (!tetros)
		return (1);
	while (1)
	{
		//printf("count %d\n", count);
		if (place_tetros(tetros, arr, size, count))
		{
			if (try_place_tetros(tetros->next, arr, size, count + 1))
				return (1);
			else
				remove_tetros_arr(tetros, arr, size);
		}
		if (move_tetros_right(tetros, size))
			continue ;
		if (!move_tetros_fl_d(tetros, size))
		{
			ft_move_tetros_ftl(&tetros);
			return (0);
		}
	}
	return (1);
}

void		empty_arr(int *arr, int size)
{
	int i = 0;
	while (i < size * size)
	{
		arr[i] = 0;
		i++;
	}
}

int			solve_fillit(t_tetros *tetros)
{
	int size = 4;
    int *arr = (int *)malloc(size * size * sizeof(int));
	empty_arr(arr, size);

	while (!try_place_tetros(tetros, arr, size, 1))
		size++;
	print_arr(arr, size);
	return (1);
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
		ft_reverse_tetros(&tetros);
		ft_move_tetros_ftl(&tetros);
		//ft_print_tetriminos(tetros);
		solve_fillit(tetros);
		//ft_print_tetriminos(tetros);
		return (0);
	}
	printf("Usage : ./tetriminos.out <filename>\n");
	return (-1);
}
