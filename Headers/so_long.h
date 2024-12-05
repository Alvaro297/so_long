#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "structure.h"
# include "libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>


void	ft_init_mapping(int fd, t_mlx *mlx, t_map *map);
bool	ft_validation_map(char	*map_src, int fd, t_map *map, t_mlx *mlx);
#endif