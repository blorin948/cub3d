/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blorin <blorin@student.le-101.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:28:22 by blorin            #+#    #+#             */
/*   Updated: 2020/03/06 17:21:33 by blorin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		parsing(t_storage *ptr)
{
	int i;
	int a;

	a = 0;
	i = 0;
	while (a < ptr->linecount)
	{
		while (i < (int)ft_strlen(ptr->map[a]))
		{
			if (ptr->map[a][i] != '1' && ptr->map[a][i] != '3' && ptr->map[a][i]
			!= '0' && ptr->map[a][i] != 'E' && ptr->map[a][i] != 'S' && ptr->map
			[a][i] != 'W' && ptr->map[a][i] != 'N' && ptr->map[a][i] != '2')
				return (error(ptr, "map"));
			if (ptr->map[a][i] == '3')
				ptr->checkdoor++;
			i++;
		}
		i = 0;
		a++;
	}
	return (1);
}

int		ft_atoi(char *line, int *i)
{
	int count;

	count = 0;
	while (line[*i] >= '0' && line[*i] <= '9' && line[*i] != '\0')
	{
		count = count * 10 + line[*i] - 48;
		*i = *i + 1;
	}
	return (count);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int		check_argue(t_storage *ptr, int ac, char **av)
{
	if (ac != 2)
	{
		if (ac == 3)
		{
			if (ft_strcmp(av[2], "--save") != 0)
				return (error(ptr, "arguements"));
			else
			{
				ptr->save++;
				return (1);
			}
		}
		return (error(ptr, "arguements"));
	}
	if (ft_strcmp(av[1] + ft_strlen(av[1] - 4), ".cub") != 0)
		error(ptr, ".cub");
	return (1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
