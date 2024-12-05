#include "../Headers/so_long.h"

void init_map(t_map *map) {
	map->matriz = NULL;
	map->width = 0;
	map->height = 0;
	map->n_collects = 0;
	map->n_players = 0;
	map->n_exits = 0;
}
