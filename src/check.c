/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:46:17 by mjiam             #+#    #+#             */
/*   Updated: 2020/12/27 21:16:05 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	config_checker(t_game *game)
{
	if (!game->config.screenheight || !game->config.screenwidth)
		err_handler(game,
			"Missing resolution. Has to be specified before map\n");
	else if (!game->config.tex[N].ptr || !game->config.tex[S].ptr ||
			!game->config.tex[E].ptr || !game->config.tex[W].ptr)
		err_handler(game,
			"Missing wall texture. Has to be specified before map\n");
	else if (!game->config.sprite.ptr)
		err_handler(game,
			"Missing sprite texture. Has to be specified before map\n");
	else if ((game->config.floor.colour == 2147483648 &&
			!game->config.tex[F].ptr) || (game->config.ceiling.colour ==
			2147483648 && !game->config.tex[C].ptr))
		err_handler(game,
			"Missing floor/ceiling colour. Has to be specified before map\n");
}

/*
** case 1 for .cub file check, case 2 for .xpm/.png check,
** case 3 for open file check
*/

int		file_checker(int case_n, void *param)
{
	int len;
	int fd;

	len = case_n < 3 ? ft_strlen((char *)param) : 0;
	if (case_n == 1)
	{
		if (!ft_strcmp(&((char *)param)[len - 4], ".cub"))
			return (0);
	}
	else if (case_n == 2)
	{
		if (!ft_strcmp(&((char *)param)[len - 4], ".xpm"))
			return (0);
		if (!ft_strcmp(&((char *)param)[len - 4], ".png"))
			return (1);
	}
	else if (case_n == 3)
	{
		fd = open((char *)param, O_RDONLY);
		close(fd);
		if (fd >= 0)
			return (0);
	}
	return (-1);
}

/*
** function returns 1 if --save is found, 0 if no second arg,
** else exits on error
*/

int		arg_checker(t_game *game, int argc, char **argv)
{
	if (argc < 2)
		err_handler(game, "No map given\n");
	if (argc >= 2)
	{
		if (file_checker(1, argv[1]) < 0)
		err_handler(game, "Invalid map file\n");
		if (argc == 3)
		{
			if (ft_strcmp(argv[2], "--save") == 0)
			return (1);
			err_handler(game, "Invalid second argument\n");
		}
	}
	return (0);
}