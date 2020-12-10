/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:58:08 by klever            #+#    #+#             */
/*   Updated: 2020/12/10 14:04:41 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		parser(t_game *game, char *map)
{
	char	*line;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(map, O_RDONLY);
	//if (fd < 0)
	//	err_handler(game, "Failed to open map file\n");
	//while (ret)
	//{
	//	ret = get_next_line(fd, &line);
	//	if (ret < 0)
	//		err_handler(game, "Failed to read from map file\n");
		//if (data_filler(game, line) < 0)
		//	err_handler(game, "Invalid line in map file\n");
		//free(line);
	//}
	//close(fd);
	//if (finish_parse(game) < 0)
	//	return (-1);
	//return (0);
}