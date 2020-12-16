/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 06:07:15 by klever            #+#    #+#             */
/*   Updated: 2020/12/16 01:49:21 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

intmax_t	ft_atoi(char *line, int *i)
{
	int			sign;
	intmax_t	n;

	sign = 1;
	n = 0;
	whitespaceskip(line, i);
	if (line[*i] == '-' || line[*i] == '+')
	{
		if (line[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (isnumber(line, *i))
	{
		if (n >= 922337203685477580)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		n = n * 10 + (line[*i] - '0');
		(*i)++;
	}
	return (sign * n);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (str1[i] - str2[i]);
		else
			i++;
	}
	return (str1[i] - str2[i]);
}