/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:57:57 by klever            #+#    #+#             */
/*   Updated: 2020/11/25 21:13:22 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



//free data game->map->data (char **data)

void	map_cleaner(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	if (map)
		free(map);
}

/*
** exits on 0 if called normally, -1 if called in error processing
*/

int		exiter(t_game *game, int c)
{
	if (c != -1 && game->map.data)
		map_cleaner(game->map.data);
	if (game->map.perpdist)
		free(game->map.perpdist);
	if (game->config.tex[0].ptr)
		//tex_cleaner(game, game->config.tex);
	if (game->mlx && game->config.sprite.ptr)
		mlx_destroy_image(game->mlx, game->config.sprite.ptr);
	if (game->mlx && game->map.sprites)
		//sprite_evicter(&game->map.sprites);
	if (game->mlx && game->mlx_win)
	{
		if (game->fr1.ptr)
			mlx_destroy_image(game->mlx, game->fr1.ptr);
		if (game->fr2.ptr)
			mlx_destroy_image(game->mlx, game->fr2.ptr);
		mlx_destroy_window(game->mlx, game->mlx_win);
	}
	free(game->mlx);
	exit(c);
}

void	err_handler(t_game *game, char *str)
{
	if (write(2, "Error\n", 6) < 0)
		err_handler(game, "Write failed\n");
	if (str)
	{
		if (write(2, str, ft_strlen(str)) < 0)
			err_handler(game, "Write failed\n");
	}
	//exiter(game, -1);
}
