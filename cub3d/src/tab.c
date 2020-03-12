/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blorin <blorin@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:59:20 by blorin            #+#    #+#             */
/*   Updated: 2020/03/06 17:37:01 by blorin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		sprite_door(t_storage *ptr)
{
	int i;
	int a;

	a = 0;
	i = 0;
	while (a < ptr->linecount)
	{
		while (ptr->map[a][i++] != '\0')
		{
			if (ptr->map[a][i] == '3')
				ptr->doorc++;
			if (ptr->map[a][i] == '2')
				ptr->spritec++;
		}
		a++;
		i = 0;
	}
	malloc_sprite_door(ptr);
	return (1);
}

int		malloc_tab(t_storage *ptr)
{
	int i;

	i = 0;
	if (!(ptr->tab = malloc(sizeof(int *) * ptr->linecount)))
		return (0);
	while (i < ptr->linecount)
	{
		if (!(ptr->tab[i] = malloc(sizeof(int) * ft_strlen(ptr->map[i]))))
			return (0);
		i++;
	}
	return (1);
}

void	create_tab2(t_storage *ptr, int i, int c)
{
	int a;

	a = 0;
	c = 0;
	while (a < (int)ft_strlen(ptr->map[i]))
	{
		ptr->tab[i][a] = ptr->map[i][c] - 48;
		if (ptr->tab[i][a] == 3)
		{
			ptr->doorposx[ptr->door] = a;
			ptr->doorposy[ptr->door] = i;
			ptr->door++;
		}
		if (ptr->tab[i][a] == 2)
		{
			ptr->spritet[ptr->spritek].x = (double)a + 0.5;
			ptr->spritet[ptr->spritek].y = (double)i + 0.5;
			ptr->spritek++;
		}
		a++;
		c++;
	}
}

int		create_tab(t_storage *ptr)
{
	int i;
	int a;
	int sprite;
	int c;

	sprite_door(ptr);
	malloc_tab(ptr);
	a = 0;
	c = 0;
	i = 0;
	while (i < ptr->linecount)
	{
		create_tab2(ptr, i, c);
		i++;
	}
	return (0);
}

int		check_map2(t_storage *ptr)
{
	int i;
	int a;

	a = 0;
	i = 0;
	while (a < ptr->linecount)
	{
		if (ptr->map[a][ft_strlen(ptr->map[a]) - 1] != '1')
			return (error(ptr, "map"));
		a++;
	}
	while (i < (int)ft_strlen(ptr->map[0]))
	{
		if (ptr->map[0][i] != '1')
			return (error(ptr, "map"));
		i++;
	}
	i = 0;
	while (i < (int)ft_strlen(ptr->map[ptr->linecount - 1]))
	{
		if (ptr->map[ptr->linecount - 1][i] != '1')
			return (error(ptr, "map"));
		i++;
	}
	return (1);
}
