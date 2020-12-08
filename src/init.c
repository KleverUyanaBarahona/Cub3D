/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 19:37:13 by kbarahon          #+#    #+#             */
/*   Updated: 2020/12/08 05:53:38 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_key(t_key *keys)
{
	keys->key_up = 0;
	keys->key_dw = 0;
	keys->key_lf = 0;
	keys->key_rt = 0;
	keys->key_rotl = 0;
	keys->key_rotr = 0;
}

void	init_img(t_img *img)
{
	img->ptr = NULL;
	img->addr = NULL;
	img->bpp = 0;
	img->linesize = 0;
	img->endian = 0;
	img->width = 0;
	img->height = 0;
	pos_setter(&img->t_step, 0, 0);
	pos_setter(&img->pos, 0, 0);
}

int		init_game(t_game *game, int save)
{
	game->mlx_win = NULL;
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		return (-1);
	if (save)
		game->save = open("screenshot.bmp",
						O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	else
		game->save = 0;
	if (game->save < 0)
		err_handler(game, "Failed to open screenshot file\n");
	game->frame = 1;
	game->player.startdir = NONE;
	game->player.quest = 0;
	pos_setter(&game->player.pos, 0, 0);
	init_img(&game->img);
	init_img(&game->fr1);
	init_img(&game->fr2);
	init_key(&game->keys);
	//init_config(&game->config);
	//init_map(&game->map);
	//init_view(&game->view);
	return (0);
}