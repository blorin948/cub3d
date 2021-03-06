/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blorin <blorin@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:28:46 by blorin            #+#    #+#             */
/*   Updated: 2020/03/04 21:35:15 by blorin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		*white_edge(t_storage *ptr, int winx, int winy, int *img)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (x < winx)
		img[0 * ptr->resox + x++] = 0xfffffff;
	while (y < winy)
	{
		img[y * ptr->resox + (x - 1)] = 0xfffffff;
		y++;
	}
	x = 0;
	while (x < winx)
	{
		img[(winy - 1) * ptr->resox + x] = 0xfffffff;
		x++;
	}
	y = 0;
	while (y < winy)
	{
		img[y * ptr->resox + 0] = 0xfffffff;
		y++;
	}
	return (img);
}

void	set_map(t_storage *ptr, int winx, int winy)
{
	ptr->minimap.tmpminx = ptr->posx - 5;
	ptr->minimap.maxy = ptr->posy + 5;
	ptr->minimap.miny = ptr->posy - 5;
	ptr->minimap.maxx = ptr->posx + 5;
	ptr->minimap.minx = ptr->posx - 5;
	ptr->minimap.incrx = 10.0 / winx;
	ptr->minimap.incry = 10.0 / winy;
}

int		*create_minimap2(t_storage *ptr, int x, int y, int *img)
{
	if (ptr->minimap.miny > 0.0 && ptr->minimap.miny <
	(double)ptr->linecount && ptr->minimap.minx > 0.
	&& ptr->minimap.minx < (int)ft_strlen(ptr->map[(int)ptr->minimap.miny]) &&
	ptr->tab[(int)ptr->minimap.miny][(int)ptr->minimap.minx] == 1)
		img[y * ptr->resox + x] = 0xfffffff;
	else if (ptr->minimap.miny > 0.0 && ptr->minimap.miny <
	(double)ptr->linecount && ptr->minimap.minx > 0.
	&& ptr->minimap.minx < (int)ft_strlen(ptr->map[(int)ptr->minimap.miny]) &&
	ptr->tab[(int)ptr->minimap.miny][(int)ptr->minimap.minx] == 2)
		img[y * ptr->resox + x] = 0xfA8072;
	else
		img[y * ptr->resox + x] = 0x000000;
	ptr->minimap.minx = ptr->minimap.minx + ptr->minimap.incrx;
	return (img);
}

int		*create_minimap(t_storage *ptr, int winx, int winy, int *img)
{
	int y;
	int x;

	x = 0;
	y = 0;
	set_map(ptr, winx, winy);
	while (++y < winy - 1)
	{
		while (++x < winx - 1)
			img = create_minimap2(ptr, x, y, img);
		ptr->minimap.miny = ptr->minimap.miny + ptr->minimap.incry;
		ptr->minimap.minx = ptr->minimap.tmpminx;
		x = 1;
	}
	return (img);
}

int		*image(t_storage *ptr, int *img)
{
	int winx;
	int winy;

	winy = ptr->resoy / 6;
	winx = ptr->resox / 6;
	ptr->t_img.cubsizey = winy / 6;
	ptr->t_img.cubsizex = winx / 6;
	img = white_edge(ptr, winx, winy, img);
	img = create_minimap(ptr, winx, winy, img);
	img[(winy / 2) * ptr->resox + (winx / 2)] = 0xFF0000;
	img[((winy / 2) + 1) * ptr->resox + ((winx / 2) + 1)] = 0xFF0000;
	img[(winy / 2) * ptr->resox + ((winx / 2) + 1)] = 0xFF0000;
	img[((winy / 2) + 1) * ptr->resox + (winx / 2)] = 0xFF0000;
	img[((winy / 2) - 1) * ptr->resox + ((winx / 2) - 1)] = 0xFF0000;
	img[(winy / 2) * ptr->resox + ((winx / 2) - 1)] = 0xFF0000;
	img[((winy / 2) - 1) * ptr->resox + (winx / 2)] = 0xFF0000;
	img[((winy / 2) + 1) * ptr->resox + ((winx / 2) - 1)] = 0xFF0000;
	img[((winy / 2) - 1) * ptr->resox + (winx / 2) + 1] = 0xFF0000;
	return (img);
}
