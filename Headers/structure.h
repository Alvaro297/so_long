#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
}	t_mlx;

typedef struct structure
{
	char	**matriz;
	int		height;
	int		width;
	int		n_collects;
	int		n_players;
	int		n_exits;
	bool	is_map_correct;
}	t_map;


#endif 