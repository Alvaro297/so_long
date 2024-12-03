#include "../Headers/libft.h"

int	ft_strlen_mod(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\n' || s[i] != '\0')
		i++;
	return (i);
}
