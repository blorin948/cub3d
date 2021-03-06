/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blorin <blorin@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:59:03 by blorin            #+#    #+#             */
/*   Updated: 2020/03/06 17:38:03 by blorin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		malloc_sprite_door(t_storage *ptr)
{
	if (ptr->doorc > 0)
	{
		if (!(ptr->doorposx = malloc(sizeof(int) * ptr->doorc)))
			return (0);
		if (!(ptr->doorposy = malloc(sizeof(int) * ptr->doorc)))
			return (0);
	}
	if (ptr->spritec > 0)
	{
		if (!(ptr->spritet = malloc(sizeof(t_sprite_s) * ptr->spritec)))
			return (0);
	}
	return (1);
}

int		ecran(t_storage *ptr)
{
	mlx_hook(ptr->win_ptr, 2, 0, key, ptr);
	mlx_hook(ptr->win_ptr, 3, 0, key_release, ptr);
	mlx_hook(ptr->win_ptr, 17, 0, ft_exit, ptr);
	ray_cast(ptr);
	mlx_loop_hook(ptr->mlx_ptr, move_side, ptr);
	mlx_loop(ptr->mlx_ptr);
	return (1);
}

int		ft_start(int ac, char **av, t_storage *ptr, t_check *checkv)
{
	int a;

	a = 0;
	if (check_argue(ptr, ac, av) != 1)
		return (0);
	gnl(av[1], ptr, checkv);
	if ((checkv->ea != 1 || checkv->no != 1 || checkv->we != 1 || checkv->so
	!= 1 || checkv->f != 1 || (checkv->c != 1 && ptr->che.sky != 1) || checkv->f
	!= 1 || checkv->sprite != 1 || checkv->r != 1))
		return (error(ptr, "parametres"));
	parsing(ptr);
	position(ptr, a);
	check_map2(ptr);
	create_tab(ptr);
	set_val(ptr);
	if (ptr->checkdoor > 0 && checkv->p < 1)
		error(ptr, "door");
	open_win(ptr);
	return (1);
}

int		open_win(t_storage *ptr)
{
	if (!(ptr->buffer = malloc(sizeof(double) * ptr->resox)))
		return (0);
	if (!(ptr->mlx_ptr = mlx_init()))
		return (0);
	load(ptr);
	if (ptr->error > 0)
		return (0);
	if (!(ptr->win_ptr = mlx_new_window(ptr->mlx_ptr,
	ptr->resox, ptr->resoy, "cub3d")))
		return (0);
	if (ptr->che.sky > 0)
	{
		if (skybox(ptr) != 1)
			return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_storage	ptr;
	t_check		checkv;

	ptr = (t_storage){0};
	checkv = (t_check){0};
	ft_start(ac, av, &ptr, &checkv);
	if (ptr.error > 0)
		return (0);
	ecran(&ptr);
}
