/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:57:26 by alvamart          #+#    #+#             */
/*   Updated: 2024/09/27 16:01:34 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

char	*ft_strdup(const char *s)
{
	char	*c;
	size_t	len;

	len = ft_strlen(s);
	c = malloc(len + 1);
	if (!c)
		return (NULL);
	ft_memcpy(c, s, len);
	c[len] = '\0';
	return (c);
}
