/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 10:38:38 by alvamart          #+#    #+#             */
/*   Updated: 2024/09/19 12:08:53 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

void	*calloc(size_t num, size_t size)
{
	char	*ptr;

	ptr = malloc(size * num);
	if (!ptr)
		return (0);
	ft_bzero(ptr, (num * size));
	return (ptr);
}
