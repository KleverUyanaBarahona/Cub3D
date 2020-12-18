/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 13:58:08 by klever            #+#    #+#             */
/*   Updated: 2020/12/18 02:27:37 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		fc_filler(t_game *game, char *line, int *i)
{
	if (line[*i + 1] == '-')
		err_handler(game, "Invalid floor/ceiling values\n");
//	if (line[*i] == 'F' && (line[*i + 1] == ' ' || isnumber(line, *i + 1)))
//	{
//		(*i)++;
//		whitespaceskip(line, i);
//		if (isnumber(line, *i) || line[*i] == '-')
//			return (colour_setter(game, &game->config.floor, line, i));
//		return (tex_setter(game, &game->config.tex[F], line, i));
//	}
//	else if (line[*i] == 'C' && (line[*i + 1] == ' ' || isnumber(line, *i + 1)))
//	{
//		(*i)++;
//		whitespaceskip(line, i);
//		if (isnumber(line, *i) || line[*i] == '-')
//			return (colour_setter(game, &game->config.ceiling, line, i));
//		return (tex_setter(game, &game->config.tex[C], line, i));
//	}
	return (-1);
}

int		data_filler(t_game *game, char *line)
{
	int		i;

	i = 0;
	whitespaceskip(line, &i);
	if (line[i] == 'R' && (line[i + 1] == ' ' || isnumber(line, i + 1) ||
		line[i + 1] == '-'))
		return (res_setter(game, line, &i));
	else if (line[i] == 'N' && line[i + 1] == 'O')
		return (tex_setter(game, &game->config.tex[N], line, &i));
	else if (line[i] == 'S' && line[i + 1] == 'O')
		return (tex_setter(game, &game->config.tex[S], line, &i));
	else if (line[i] == 'W' && line[i + 1] == 'E')
		return (tex_setter(game, &game->config.tex[W], line, &i));
	else if (line[i] == 'E' && line[i + 1] == 'A')
		return (tex_setter(game, &game->config.tex[E], line, &i));
	else if (line[i] == 'S' && line[i + 1] != '0')
		return (tex_setter(game, &game->config.sprite, line, &i));
	else if (line[i] == 'F' || line[i] == 'C')
		return (fc_filler(game, line, &i));
//	else if (line[i] == '0' || line[i] == '1' || line[i] == '2')
//		return (map_maker(game, line, &i));
//	else if (line[i] == '\0' && game->config.map_found)
//		return (map_maker(game, line, &i));
	return (!line[i] ? 0 : -1);
}

int		parser(t_game *game, char *map)
{
	char	*line;
	int		fd;
	int		ret;

	ret = 1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		err_handler(game, "Failed to open map file\n");
	while (ret)
	{
		ret = get_next_line(fd, &line);
		//printf("%d",ret);
		//printf("%s\n",line);
		if (ret < 0)
			err_handler(game, "Failed to read from map file\n");
		if (data_filler(game, line) < 0)
			err_handler(game, "Invalid line in map file\n");
		free(line);
	}
	close(fd);
	//if (finish_parse(game) < 0)
	//	return (-1);
	return (0);
}