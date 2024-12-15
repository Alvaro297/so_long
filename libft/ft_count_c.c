/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 18:04:35 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-10 18:04:35 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

int	ft_count_c(char *s, char c)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	if (!s)
		return (-1);
	while (s && s[i])
	{
		if (s[i++] == c)
			x++;
	}
	return (x);
}
