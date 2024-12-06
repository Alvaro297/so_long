#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// String functions
size_t	ft_strlen(const char *s);
int		ft_strlen_mod(char *s);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

// Conversion functions
int		ft_atoi(const char *str);

// Memory allocation functions
void	*ft_calloc(size_t count, size_t size);

// Additional functions
char	*ft_strjoin(char const *s1, char const *s2);

//GNL
char	*get_next_line(int fd);
#endif