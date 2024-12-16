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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*space_memory;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!s1)
	{
		s1 = ft_calloc(1, 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	space_memory = ft_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!space_memory)
		return (NULL);
	if (s1)
		while (s1[++i] != '\0')
			space_memory[i] = s1[i];
	while (s2[++j] != '\0')
		space_memory[i + j] = s2[j];
	space_memory[i + j] = '\0';
	free(s1);
	return (space_memory);
}
