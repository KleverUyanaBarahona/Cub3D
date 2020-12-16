/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:36:30 by klever            #+#    #+#             */
/*   Updated: 2020/12/15 18:10:36 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//void	init_mlx(t_game *game)
//{
//	if (!game->save)
//		game->mlx_win = mlx_new_window(game->mlx, game->config.screenwidth,
//						game->config.screenheight, "cub3D");
//	game->fr1.ptr = mlx_new_image(game->mlx, game->config.screenwidth,
//						game->config.screenheight);
//	game->fr2.ptr = mlx_new_image(game->mlx, game->config.screenwidth,
//						game->config.screenheight);
//	game->fr1.addr = mlx_get_data_addr(game->fr1.ptr, &game->fr1.bpp,
//						&game->fr1.linesize, &game->fr1.endian);
//	game->fr2.addr = mlx_get_data_addr(game->fr2.ptr, &game->fr2.bpp,
//						&game->fr2.linesize, &game->fr2.endian);
//	if ((!game->save && !game->mlx_win) || !game->fr1.ptr || !game->fr2.ptr)
//		err_handler(game, "Initialisation failed\n");
//}

int		main(int argc, char **argv)
{
	t_game		game;
	int			save;

    save = 0;
    if (arg_checker(&game, argc, argv) > 0)
	save = 1;
	if (init_game(&game, save) < 0)
		err_handler(&game, "Initialisation failed\n");
  if (parser(&game, argv[1]) < 0)
		err_handler(&game, "File parsing failed\n");


/*
    void    *mlx;
    void    *mlx_win;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
    mlx_loop(mlx);
*/
	
	return (0);
}

