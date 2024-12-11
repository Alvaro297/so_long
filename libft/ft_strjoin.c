/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 13:08:34 by alvamart          #+#    #+#             */
/*   Updated: 2024/09/17 13:30:57 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*space_memory;
	size_t	len_s1;
	size_t	len_s2;

	space_memory = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!space_memory)
		return (NULL);
	ft_strlcpy(space_memory, s1, len_s1 + 1);
	ft_strlcat(space_memory, s2, len_s1 + len_s2 + 1);
	return (space_memory);
}
