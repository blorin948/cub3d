/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blorin <blorin@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:36:38 by blorin            #+#    #+#             */
/*   Updated: 2020/03/06 17:48:26 by blorin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strcut(char *str, char c)
{
	int		i;

	i = 0;
	if (is_map(str) < 1)
		return (str);
	while (str[i])
	{
		if (str[i] == c)
			str[i] = '1';
		i++;
	}
	return (str);
}

int		is_map(char *line)
{
	int i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == '1')
		return (1);
	return (0);
}

int		ft_count_nbr(char *line, int i)
{
	int a;
	int k;

	a = 0;
	k = 0;
	while (line[a])
	{
		if (line[a] != ' ')
			i++;
		a++;
	}
	return (i);
}

int		create_char_map(t_storage *ptr, char *line, int c)
{
	if (!(ptr->map[c] = malloc(sizeof(char) * ptr->nbrcount + 1)))
		return (0);
	line = line;
	return (1);
}

void	free_all(t_storage *ptr)
{
	int i;

	if (ptr->spritet)
		free(ptr->spritet);
	if (ptr->buffer)
		free(ptr->buffer);
	if (ptr->doorposx)
		free(ptr->doorposx);
	if (ptr->doorposy)
		free(ptr->doorposy);
	i = 0;
	if (ptr->tab)
	{
		while (i < ptr->linecount)
		{
			free(ptr->tab[i]);
			i++;
		}
		free(ptr->tab);
	}
}
