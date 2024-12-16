/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 18:08:01 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-10 18:08:01 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>

size_t	ft_strlen(const char *s);
int		ft_strlen_mod(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strstr(const char *s1, const char *s2);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char *s1, char *s2);
//GNL
char	*get_next_line(int fd);
#endif