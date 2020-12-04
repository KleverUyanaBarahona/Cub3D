/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:37:13 by kbarahon          #+#    #+#             */
/*   Updated: 2020/12/04 20:42:50 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		init_game(t_game *game, int save)
{
	game->mlx_win = NULL;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (-1);
	if (save)
    //printf("screenshot");
		game->save = open("screenshot.bmp",
						O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	else
		game->save = 0;
	if (game->save < 0)
		err_handler(game, "Failed to open screenshot file\n");
	game->frame = 1;
	game->player.startdir = NONE;
	game->player.quest = 0;
	//pos_setter(&game->player.pos, 0, 0);
	//init_img(&game->img);
	//init_img(&game->fr1);
	//init_img(&game->fr2);
	//init_key(&game->keys);
	//init_config(&game->config);
	//init_map(&game->map);
	//init_view(&game->view);
	return (0);
}