/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:55:51 by kbarahon          #+#    #+#             */
/*   Updated: 2020/12/15 20:18:55 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		value_finder(char *line, int *i, char exc)
{
	while (line[*i] && !isnumber(line, *i) && line[*i] != '-')
	{
		if (line[*i] != exc && line[*i] != 32 &&
			(line[*i] < 9 || line[*i] > 13))
			return (-1);
		(*i)++;
	}
	return (0);
}

int		isnumber(char *line, int i)
{
	if (line[i] && line[i] >= '0' && line[i] <= '9')
		return (1);
	return (0);
}

void	pos_setter(t_pos *pos, double x, double y)
{
	pos->x = x;
	pos->y = y;
}

int		whitespaceskip(char *line, int *i)
{
	if (line[*i] != 32 && (line[*i] < 9 || line[*i] > 13))
		return (0);
	while (line[*i] == 32 || (line[*i] >= 9 && line[*i] <= 13))
		(*i)++;
	return (1);
}
