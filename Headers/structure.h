/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvamart <alvamart@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-10 18:08:44 by alvamart          #+#    #+#             */
/*   Updated: 2024-12-10 18:08:44 by alvamart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

typedef struct s_collectible
{
	int		x;
	int		y;
	void	*img;
	struct s_collectible	*next;
}	t_collectible;

typedef struct s_wall
{
	int		x;
	int		y;
	void	*img;
}	t_wall;

typedef struct s_map_fill
{
	int		x;
	int		y;
} t_map_fill;


typedef struct s_map
{
	char					**matriz;
	int						height;
	int						width;
	int						n_collects;
	int						n_wall;
	int						n_players;
	int						n_exits;
	t_collectible			*collectibles;
	t_wall					*wall;
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

typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					width_win;
	int					height_win;
	int					moves;
	t_map				map;
	t_player			player;
}	t_mlx;

#endif