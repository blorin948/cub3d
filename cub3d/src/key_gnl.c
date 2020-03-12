/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blorin <blorin@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:28:34 by blorin            #+#    #+#             */
/*   Updated: 2020/03/06 17:56:43 by blorin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		gnl2(t_storage *ptr, char *av)
{
	int		fd;
	char	*ok;
	int		i;
	char	*tmp;
	int		c;

	c = 0;
	i = 0;
	fd = open(av, O_RDONLY);
	if (!(ptr->map = malloc(sizeof(char *) * ptr->linecount)))
		return (0);
	while (get_next_line(fd, &ok))
	{
		if (is_map(ok) > 0)
		{
			create_char_map(ptr, ok, c);
			i = ft_strcpy_p(ptr, i, ok, c);
			c++;
		}
		ft_free(ok);
	}
	ft_close(ptr, fd, ok);
	if (ptr->error == 1)
		error(ptr, "map");
	return (0);
}

int		gnl(char *av, t_storage *ptr, t_check *checkv)
{
	int		fd;
	char	*line;
	int		t;

	fd = open(av, O_RDONLY);
	if (fd <= 0)
		return (error(ptr, ".cub file"));
	while (get_next_line(fd, &line))
	{
		t = check(&line, ptr, checkv);
		if (t == 1)
		{
			if ((int)ft_strlen(line) > ptr->nbrcount)
				ptr->nbrcount = ft_strlen(line);
			ptr->count = ft_count_nbr(line, ptr->count);
			ptr->linecount++;
		}
		ft_free(line);
	}
	ft_close(ptr, fd, line);
	gnl2(ptr, av);
	return (0);
}

int		key2(int key, t_storage *ptr)
{
	if (key == 13)
		ptr->move.moveup = 1;
	if (key == 0)
		ptr->move.movecamleft = 1;
	if (key == 2)
		ptr->move.movecamright = 1;
	if (key == 1)
		ptr->move.movedown = 1;
	if (key == 123)
		ptr->move.moveleft = 1;
	if (key == 124)
		ptr->move.moveright = 1;
	if (key == 53)
		ft_exit(ptr);
	return (0);
}

int		key(int key, t_storage *ptr)
{
	double	tmpy;
	double	tmpx;
	double	posx;
	double	posy;

	tmpy = 0;
	tmpx = 0;
	sort_door(ptr, tmpx, tmpy);
	if (ptr->doorc)
	{
		posx = fabs(ptr->doorposx[0] - ptr->posx);
		posy = fabs(ptr->doorposy[0] - ptr->posy);
		if (key == 49 && (posy < 2 && posy > -2) && (posx < 2 && posx > -2) &&
		ptr->tab[ptr->doorposy[0]][ptr->doorposx[0]] == 3)
			ptr->tab[ptr->doorposy[0]][ptr->doorposx[0]] = 0;
		else if (key == 49 && ptr->tab[ptr->doorposy[0]][ptr->doorposx[0]] == 0
		&& (abs(ptr->doorposy[0] + ptr->doorposx[0]) != abs(((int)ptr->posx +
		(int)ptr->posy))) && (posy < 2 && posy > -2) && (posx < 2 && posx > -2))
			ptr->tab[ptr->doorposy[0]][ptr->doorposx[0]] = 3;
	}
	key2(key, ptr);
	return (0);
}

int		key_release(int key, t_storage *ptr)
{
	if (key == 13)
		ptr->move.moveup = 0;
	if (key == 0)
		ptr->move.movecamleft = 0;
	if (key == 2)
		ptr->move.movecamright = 0;
	if (key == 1)
		ptr->move.movedown = 0;
	if (key == 123)
		ptr->move.moveleft = 0;
	if (key == 124)
		ptr->move.moveright = 0;
	return (0);
}
