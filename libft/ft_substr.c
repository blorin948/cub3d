/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_substr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: blorin <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 14:17:42 by blorin       #+#   ##    ##    #+#       */
/*   Updated: 2019/10/26 00:43:45 by blorin      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	a;
	char			*str;

	i = 0;
	a = 0;
	if ((ft_strlen(s) - start) < len)
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
	{
		if (!(str = malloc(sizeof(char) * 1)))
			return (0);
		str[i] = '\0';
		return (str);
	}
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i != start)
		i++;
	while (len-- > 0)
		str[a++] = s[i++];
	str[a] = '\0';
	return (str);
}
