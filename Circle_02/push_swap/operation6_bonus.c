/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation6_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:02:46 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/30 21:13:31 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	fill_str_bonus(t_extracter *result, int ac, char **av)
{
	t_indexes	index;

	result->overflow = 0;
	index.i = 1;
	index.r = 0;
	index.k = 0;
	index.f = 0;
	while (index.i < ac)
	{
		index.j = 0;
		while (av[index.i][index.j])
		{
			index.c = 0;
			index = fill_str_loop_bonus(index, av);
			index = fill_str2_bonus (index, result, av);
			if (index.i == -1)
				return (-1);
			index.k++;
			index.r = 0;
			if (!av[index.i][index.j])
				break ;
		}
		index.i += 1;
	}
	return (1);
}

int	spc_bonus(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	dgt_bonus(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	zaidnaqs_b(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

t_indexes	calculate_nbs2_bonus(t_indexes index, char **av)
{
	while (spc_bonus(av[index.i][index.j]))
	{
		index.r = 0;
		index.j += 1;
	}
	if (zaidnaqs_b(av[index.i][index.j]))
	{
		index.j++;
		if (dgt_bonus(av[index.i][index.j]) == 0)
			return (index.c = -1, index);
	}
	while (dgt_bonus(av[index.i][index.j]))
	{
		if (index.r == 0)
		{
			index.c ++;
			index.r = 1;
		}
		index.j += 1;
	}
	if (index.c > 0)
		index.r = 0;
	return (index);
}
