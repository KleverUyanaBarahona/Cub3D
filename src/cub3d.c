/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 13:36:30 by klever            #+#    #+#             */
/*   Updated: 2020/11/18 18:48:06 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		main(int argc, char **argv)
{
	t_game		game;
	int			save;

    save = 0;
    if (arg_checker(&game, argc, argv) > 0)
	save = 1;
    

	return (0);
}

