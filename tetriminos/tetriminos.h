/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 13:36:19 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/26 12:09:28 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TETRIMINOS_H
# define __TETRIMINOS_H

# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# define TETROS_SIZE 16

typedef struct
{
	int				row;
	int				col;
}					t_tetri;

typedef struct		s_tetros
{
	t_tetri			*tetri_1;
	t_tetri			*tetri_2;
	t_tetri			*tetri_3;
	t_tetri			*tetri_4;
	struct s_tetros	*next;
}					t_tetros;

t_tetri				*ft_create_tetri(const int row, const int col);
int					ft_add_tetri(t_tetros **tetros, t_tetri *tetri);
t_tetros			*ft_create_tetros(const t_tetri *tetri_1,
	const t_tetri *tetri_2, const t_tetri *tetri_3, const t_tetri *tetri_4);
void				ft_add_tetros(t_tetros **tetro, t_tetros *new);
int					ft_check_tetri_right(t_tetros *tetros);
int					ft_check_tetri_left(t_tetros *tetros);
int					ft_check_tetri_down(t_tetros *tetros);
int					ft_check_tetri_top(t_tetros *tetros);
int					ft_check_tetros_sides(t_tetros *tetros);
int					ft_valid_tetros(t_tetros *tetros);
int					ft_check_read_1(char *line, t_tetros *current);
int					ft_check_read_2(char c);
int					ft_check_read_3(char *line, int row);

#endif
