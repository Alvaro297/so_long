/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:28:47 by alvamart          #+#    #+#             */
/*   Updated: 2024/09/16 18:28:47 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

char	*ft_strchr(const char *s, char *c)
{
	int	i;
	int	j;

	j = 0;
	while (*s)
	{
		i = 0;
		if (s[j] == c[i])
		{
			i++;
			j++;
			while (s[j + i] == c[i])
			{
				i++;
				if (!c[i])
					return ((char *)&s[j]);
			}
		}
		j++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}
