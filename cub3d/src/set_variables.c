/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blorin <blorin@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:29:02 by blorin            #+#    #+#             */
/*   Updated: 2020/03/06 21:54:57 by blorin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		position(t_storage *ptr, int a)
{
	int i;
	int k;

	k = 0;
	while (a < ptr->linecount)
	{
		i = 0;
		while (ptr->map[a][i] != '\0')
		{
			if (ptr->map[a][i] == 'N' || ptr->map[a][i] == 'W' || ptr->map[a][i]
			== 'S' || ptr->map[a][i] == 'E')
			{
				k++;
				ptr->dir = ptr->map[a][i];
				ptr->posy = a + 0.5;
				ptr->posx = i + 0.5;
				ptr->map[a][i] = '0';
			}
			i++;
		}
		a++;
	}
	if (k != 1)
		return (error(ptr, "position"));
	return (0);
}

void	set_val2(t_storage *ptr)
{
	if (ptr->dir == 'N')
	{
		ptr->dirx = 0;
		ptr->diry = -1;
		ptr->planey = 0;
		ptr->planex = -0.66;
	}
	if (ptr->dir == 'S')
	{
		ptr->dirx = 0;
		ptr->diry = 1;
		ptr->planey = 0;
		ptr->planex = 0.66;
	}
}

void	set_val(t_storage *ptr)
{
	if (ptr->dir == 'E')
	{
		ptr->dirx = 1;
		ptr->diry = 0;
		ptr->planey = -0.66;
		ptr->planex = 0;
	}
	if (ptr->dir == 'W')
	{
		ptr->dirx = -1;
		ptr->diry = 0;
		ptr->planey = 0.66;
		ptr->planex = 0;
	}
	ptr->move.mspeed = 0.099;
	ptr->move.rspeed = 0.099;
	set_val2(ptr);
}

int		error(t_storage *ptr, char *error)
{
	ft_putstr("error \n");
	ft_putstr("error with : ");
	ft_putstr(error);
	ft_putstr("\n");
	ft_exit(ptr);
	return (0);
}

int		ft_exit(t_storage *ptr)
{
	int i;

	i = 0;
	if (ptr->win_ptr)
		mlx_destroy_window(ptr->mlx_ptr, ptr->win_ptr);
	if (ptr->map)
	{
		while (i < ptr->linecount)
		{
			ft_free(ptr->map[i]);
			i++;
		}
		free(ptr->map);
	}
	free_all(ptr);
	while (1);
	exit(0);
	return (0);
}
