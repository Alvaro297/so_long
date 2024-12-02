#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Memory functions
void    *ft_memset(void *b, int c, size_t len);
void    *ft_memcpy(void *dst, const void *src, size_t n);
void    *ft_memccpy(void *dst, const void *src, int c, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t len);
void    *ft_memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);

// String functions
size_t  ft_strlen(const char *s);
char    *ft_strcpy(char *dst, const char *src);
char    *ft_strncpy(char *dst, const char *src, size_t len);
char    *ft_strcat(char *s1, const char *s2);
char    *ft_strncat(char *s1, const char *s2, size_t n);
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);
char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
char	*strstr(const char *s1, const char *s2);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
int     ft_strcmp(const char *s1, const char *s2);
int     ft_strncmp(const char *s1, const char *s2, size_t n);

// Conversion functions
int     ft_atoi(const char *str);

// Memory allocation functions
void    *ft_calloc(size_t count, size_t size);

// Additional functions
char    *ft_strjoin(char const *s1, char const *s2);

//GNL
int		ft_line_length(int fd);
char	*get_next_line(int fd);
#endif