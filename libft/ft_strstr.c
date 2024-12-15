/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 18:32:42 by alvamart          #+#    #+#             */
/*   Updated: 2024/09/16 18:32:42 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

static char	*find_out(char *str, char *to_find, size_t i)
{
	size_t	x;

	x = 0;
	while (to_find[x] != '\0')
	{
		if (to_find[x] != str[i + x])
			return (NULL);
		x++;
	}
	return ((char *)(str + i));
}

char	*strstr(const char *s1, const char *s2)
{
	size_t	i;
	char	*result;

	i = 0;
	if (s2[i] == '\0')
		return ((char *) s1);
	while (s1[i] != '\0')
	{
		if (s1[i] == s2[0])
		{
			result = find_out((char *) s1, (char *) s2, i);
			if (result != NULL)
				return (result);
		}
		i++;
	}
	return (NULL);
}
