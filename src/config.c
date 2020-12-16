/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 02:17:42 by klever            #+#    #+#             */
/*   Updated: 2020/12/16 14:31:07 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		res_setter(t_game *game, char *line, int *i)
{
	int maxwidth;
	int maxheight;

	if (game->config.screenwidth != 0 || game->config.screenheight != 0)
		err_handler(game, "Duplicate information (res) in map file\n");
	mlx_get_screen_size(game->mlx, &maxwidth, &maxheight);
//	printf("w%d",maxwidth);
//	printf("h%d",maxheight);
	maxwidth = (maxwidth <= 0) ? 2560 : maxwidth;
	maxheight = (maxheight <= 0) ? 1400 : maxheight;
//	printf("w%d",maxwidth);
//	printf("h%d",maxheight);
printf("%c",line[*i]);
printf("%s",line);
printf("%d",*i);
	if (value_finder(line, i, line[*i]) < 0)
		return (-1);
		printf("%d",*i);
	game->config.screenwidth = ft_atoi(line, i);
	if (game->config.screenwidth > maxwidth && !game->save)
		game->config.screenwidth = maxwidth;
		printf("n%lu",game->config.screenwidth);
	game->config.screenheight = ft_atoi(line, i);
	if (game->config.screenheight > maxheight && !game->save)
		game->config.screenheight = maxheight;
	if (game->config.screenwidth <= 0 || game->config.screenheight <= 0)
		err_handler(game, "Invalid resolution\n");
	if (game->config.screenwidth > 16384 || game->config.screenheight > 16384)
		err_handler(game,
				"Resolution exceeds maximum (16384) for bitmap rendering\n");
	game->config.i++;
	return (0);
}