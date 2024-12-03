#include "Headers/so_long.h"

void	ft_open_map(char *argv, t_mlx *mlx, t_map *map)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error invalid path\n");
		exit (1);
	}
	if (!ft_validation_map(argv[1], fd, map, mlx))
	{
		perror("Error invalid map\n");
		exit (1);
	}
	ft_init_mapping(fd, mlx, map);
}

int main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;

	ft_open_map(argv[1], &mlx, &map);
	return 0;
}
