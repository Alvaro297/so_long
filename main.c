#include "Headers/so_long.h"

void	ft_init(char *argv, t_mlx *mlx, t_map *map)
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
	ft_init_mapping(fd, map);
	ft_collec_start(map);
	ft_wall_start(map);
	mlx -> map = *map;
	mlx -> height_win = map ->height * TILE_SIZE;
	mlx -> width_win = map ->width * TILE_SIZE;
	mlx -> moves = 0;
	close(fd);
}

int main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;

	ft_init(argv[1], &mlx, &map);
	ft_player_start(&mlx);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.width_win, mlx.height_win, "so_long");
	ft_draw_images(&mlx);
	return (0);
}
