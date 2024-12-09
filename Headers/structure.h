#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		width_win;
	int		height_win;
	int		moves;
	t_map	map;
	t_player player;
}	t_mlx;

typedef struct s_collectible
{
	int		x;
	int		y;
	int		is_catched;
	void	*img;
}	t_collectible;

typedef struct s_map
{
	char	**matriz;
	int		height;
	int		width;
	int		n_collects;
	int		n_players;
	int		n_exits;
	t_collectible	*collectibles;
}	t_map;

typedef struct s_player
{
	void	*img_up;
	void	*img_down;
	void	*img_left;
	void	*img_right;
	int		x;
	int		y;
}	t_player;


#endif 