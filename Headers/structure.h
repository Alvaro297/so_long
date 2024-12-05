#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
}	t_mlx;

typedef struct s_map
{
	char	**matriz;
	int		height;
	int		width;
	int		n_collects;
	int		n_players;
	int		n_exits;
}	t_map;


#endif 