/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 06:08:37 by klever            #+#    #+#             */
/*   Updated: 2020/12/10 06:14:33 by klever           ###   ########.fr       */
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
