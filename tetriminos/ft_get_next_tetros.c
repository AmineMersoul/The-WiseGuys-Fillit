/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_tetros.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amersoul <amersoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 11:49:09 by amersoul          #+#    #+#             */
/*   Updated: 2018/10/25 12:14:55 by amersoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "tetriminos.h"
/*
int		read_one_line(char **saved, char **line, int fd)
{
	int i;

	i = 0;
	while (tetros_line[i] != '\n' && saved[fd][i] != '\0')
		i++;
	if (saved[fd][i] == '\n')
	{
		*line = ft_strsub(saved[fd], 0, i);
		saved[fd] = ft_strdup(saved[fd] + i + 1);
	}
	else if (saved[fd][i] == '\0')
	{
		*line = ft_strdup(saved[fd]);
		ft_strdel(&saved[fd]);
	}
	return (1);
}

int		ft_get_next_tetros(const int fd, char **tetros_line)
{
	char		buff[TETROS_SIZE + 1];
	int			r;

	if (fd < 0 || tetros_line == NULL)
		return (-1);
	if ((r = read(fd, buff, TETROS_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (tetros_line == NULL)
			tetros_line = ft_strnew(TETROS_SIZE + 1);
		tetros_line = ft_strjoin(tetros_line, buff);
		if (ft_strrchr(buff, '\n'))
			break ;
	}
	if (r < 0)
		return (-1);
	else if (r == 0 && (tetros_line == NULL || tetros_line[0] == '\0'))
		return (0);
	return (read_one_line(saved, tetros_line, fd));
}
*/