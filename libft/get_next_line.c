/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:14:25 by alvamart          #+#    #+#             */
/*   Updated: 2024/10/11 16:50:46 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Headers/libft.h"

static char	*ft_next_line(char *line)
{
	size_t	i;
	size_t	n;
	char	*tline;

	i = 0;
	n = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	tline = ft_calloc(sizeof(char), (ft_strlen(line) - i + 1));
	if (!tline)
		return (NULL);
	i++;
	while (line[i] != '\0')
		tline[n++] = line[i++];
	tline[n] = '\0';
	free(line);
	return (tline);
}

static char	*full_line(char *tline)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!tline[j])
		return (NULL);
	while (tline[j] != '\n' && tline[j] != '\0')
		j++;
	line = ft_calloc(sizeof(char), j + 2);
	if (!line)
		return (NULL);
	while (tline[i] != '\n' && tline[i] != '\0')
	{
		line[i] = tline[i];
		i++;
	}
	if (tline[i] && tline[i] == '\n')
		line[i] = '\n';
	line[++i] = '\0';
	return (line);
}

static char	*ft_get_line(int fd, char *tline)
{
	char	*line;
	ssize_t	bytesread;

	bytesread = 1;
	line = ft_calloc(sizeof(char), 10 + 1);
	if (!line)
		return (NULL);
	while (bytesread > 0 && !ft_strchr(tline, '\n'))
	{
		bytesread = read(fd, line, 10);
		if (bytesread < 0)
		{
			free(tline);
			free(line);
			return (NULL);
		}
		line[bytesread] = '\0';
		tline = ft_strjoin(tline, line);
	}
	free(line);
	return (tline);
}

char	*get_next_line(int fd)
{
	static char	*tline = NULL;
	char		*line;

	if (fd < 0)
		return (NULL);
	tline = ft_get_line(fd, tline);
	if (!tline)
		return (NULL);
	line = full_line(tline);
	tline = ft_next_line(tline);
	if (line && *line == '\0')
	{
		free(line);
		free(tline);
		line = NULL;
		tline = NULL;
	}
	return (line);
}
