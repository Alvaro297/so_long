#include "../Headers/libft.h"

void	*ft_calloc(size_t size, size_t c)
{
	char			*result;
	unsigned char	*str;
	size_t			i;

	result = malloc(size * c);
	if (!result)
		return (NULL);
	i = 0;
	str = (unsigned char *) result;
	while (i < size * c)
	{
		str[i] = 0;
		i++;
	}
	return (result);
}
