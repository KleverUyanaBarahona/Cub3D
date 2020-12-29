/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 06:08:37 by klever            #+#    #+#             */
/*   Updated: 2020/12/29 04:43:23 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_map(t_map *map)
{
	map->data = NULL;
	map->cols = 0;
	map->rows = 0;
	map->spritenum = 0;
	map->star = 0;
    map->perpdist = NULL;
	map->sprites = NULL;
}

int		map_maker(t_game *game, char *line, int *i)
{
	char	**tmp;
	int		r;
	line = NULL;
	i=0;
	if (game->config.i < 8)
		config_checker(game);
	game->config.map_found = 1;
	r = 0;
	printf("tm%lu",sizeof(char *) * (game->map.rows + 2));
	printf("%s",game->map.data[r]);
	tmp = malloc(sizeof(char *) * (game->map.rows + 2));
	if (!tmp)
		err_handler(game, "Malloc fail\n");
	while (r < game->map.rows)
	{
//		tmp[r] = ft_strdup(game->map.data[r]);
//		if (!tmp[r])
//			err_handler(game, "Malloc fail\n");
//		free(game->map.data[r]);
//		r++;
	}
//	tmp[r] = map_writer(game, line, i);
//	tmp[r + 1] = NULL;
//	if (game->map.rows > 0)
//		free(game->map.data);
//	game->map.data = tmp;
//	game->map.rows++;
	return (0);
}