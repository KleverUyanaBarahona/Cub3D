/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 02:17:42 by klever            #+#    #+#             */
/*   Updated: 2020/12/27 21:25:04 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		colour_setter(t_game *game, t_colour *element, char *line, int *i)
{
	int rgb[3];
	int	c;

	c = 0;
	if (element->colour != 2147483648)
		err_handler(game, "Duplicate information (f/c) in map file\n");
	if (value_finder(line, i, line[*i]) < 0)
		return (-1);
	while (line[*i] && c < 3)
	{
		rgb[c] = ft_atoi(line, i);
		printf("\n%d",rgb[c]);
		if (rgb[c] < 0 || rgb[c] > 255)
			err_handler(game, "Invalid floor/ceiling values\n");
		if (value_finder(line, i, ',') < 0)
			return (-1);
		c++;
	}
	if (c < 3)
		err_handler(game, "Missing floor/ceiling value\n");
	element->colour = (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
	printf("\n%d",rgb[0]<< 16);
	printf("\n%d",rgb[1]<< 8);
	printf("\n%d",rgb[2]);
	printf("\n%d",element->colour );
	game->config.i++;
	return (0);
}

void	tex_filer(t_game *game, char *path, t_img *tex)
{
	int		format;
	int		len;

	format = -1;
	format = file_checker(2, path);
	if (format == -1)
		err_handler(game, "Invalid texture file\n");
	if (file_checker(3, path) < 0)
		err_handler(game, "Failed to open texture file\n");
	if (format == xpm)
		tex->ptr = mlx_xpm_file_to_image(game->mlx, path,
					&tex->width, &tex->height);
	else if (format == png)
		tex->ptr = mlx_png_file_to_image(game->mlx, path,
					&tex->width, &tex->height);
	if (tex->ptr == NULL)
		err_handler(game, "Image reading fail\n");
	len = ft_strlen(path);
	if (!ft_strcmp(&path[len - 12], "sprite_3.xpm") ||
		!ft_strcmp(&path[len - 12], "sprite_3.png"))
		game->map.star = 1;
		printf("\n%s\n",path);
	tex->addr = mlx_get_data_addr(tex->ptr, &tex->bpp,
					&tex->linesize, &tex->endian);
	if (tex->addr == NULL)
		err_handler(game, "Image address retrieval fail\n");
}

char	*pathfinder(char *line, int *i, int len)
{
	char	*path;
	int		j;

	j = 0;
	path = malloc(sizeof(char) * (len + 1));
	if (!path)
		return (0);
	while (line[*i] && j < len)
	{
		path[j] = line[*i];
		j++;
		(*i)++;
	}
	path[j] = '\0';
	return (path);
}

int		tex_setter(t_game *game, t_img *tex, char *line, int *i)
{
	char	*path;
	int		len;

	len = 0;
	path = NULL;
	if (tex->ptr)
		err_handler(game, "Duplicate information (tex) in map file\n");
	if (inset(line, *i))
	{
		while (!whitespaceskip(line, i))
			(*i)++;
	}
	whitespaceskip(line, i);
	while (line[*i + len] && line[*i + len] != '\n')
		len++;
	path = pathfinder(line, i, len); 
	if (!path)
		err_handler(game, "Malloc fail\n");
	tex_filer(game, path, tex);
	free(path);
	game->config.i++;
	return (0);
}

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