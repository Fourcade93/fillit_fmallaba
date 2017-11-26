/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmallaba <fmallaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:34:49 by fmallaba          #+#    #+#             */
/*   Updated: 2017/11/26 17:02:26 by fmallaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		check_tetrimo(char *buf, int sharp)
{
	int	check;
	int	i;

	check = 0;
	i = 0;
	while (sharp)
	{
		if (buf[i] == '#')
		{
			sharp--;
			if (buf[i + 1] == '#')
				check++;
			if (i > 0 && buf[i - 1] == '#')
				check++;
			if (i < 16 && buf[i + 5] == '#')
				check++;
			if (i > 4 && buf[i - 5] == '#')
				check++;
		}
		i++;
	}
	if (check == 6 || check == 8)
		return (1);
	return (0);
}

static int		check_block(char *buf)
{
	int	row;
	int	sharp;
	int	i;

	i = 0;
	sharp = 0;
	while (i < 19 && buf[i])
	{
		row = 0;
		while (row++ != 4 && buf[i])
		{
			if (!(buf[i] == '#' || buf[i] == '.'))
				return (0);
			if (buf[i] == '#')
				sharp++;
			i++;
		}
		if (buf[i] != '\n')
			return (0);
		i++;
	}
	if ((sharp != 4 || buf[19] != '\n') ||
		(buf[20] != 127 && buf[19] != '\n'))
		return (0);
	return (check_tetrimo(buf, sharp));
}

static void		move_to_left(t_sq sub[4])
{
	int	min;
	int	i;

	i = 0;
	min = sub[i].x;
	while (i < 4)
	{
		if (sub[i].x < min)
			min = sub[i].x;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		sub[i].x = sub[i].x - min;
		i++;
	}
}

static void		create_subarr(char *buf, t_sq sub[4])
{
	int		col;
	int		row;
	int		i;

	col = 0;
	row = 0;
	i = 0;
	while (*buf)
	{
		if (col == 5)
		{
			col = 0;
			(i > 0) ? row++ : row;
		}
		if (*buf == '#')
		{
			sub[i].x = col;
			sub[i].y = row;
			i++;
		}
		buf++;
		col++;
	}
	move_to_left(sub);
}

int				read_file(int fd, t_sq arr[26][4])
{
	char	buf[21];
	int		len;
	int		check;

	len = 0;
	if (fd < 0)
		return (-1);
	check = 0;
	ft_memset(buf, 127, 21);
	while (read(fd, &buf, 21) && len < 26)
	{
		if (buf[20] == 127)
			check = 1;
		if (check_block(buf) == 0)
			return (0);
		create_subarr(buf, arr[len]);
		ft_memset(buf, 127, 21);
		len++;
	}
	if (!check)
		return (0);
	return (len);
}
