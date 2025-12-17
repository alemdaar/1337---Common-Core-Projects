/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation4_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:00:51 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/31 15:56:04 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_indexes	small_atoi_bonus(t_extracter *result, t_indexes index)
{
	int	i;
	int	j;
	int	k;

	i = index.i;
	j = index.j;
	k = index.k;
	result->nb[k] = (result->nb[k] * 10) + (result->str[i][j] - 48);
	index.j++;
	return (index);
}

int	overflow_check_bonus(long long nb)
{
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	return (0);
}

int	extract_nbs_bonus(t_extracter *result)
{
	t_indexes	index;

	result->nb = (long long *) malloc (sizeof(long long) * result->count);
	if (!result->nb)
		return (-1);
	index.i = 0;
	index.r = 1;
	index.k = 0;
	while (index.i < result->count)
	{
		result->nb[index.k] = 0;
		index.j = 0;
		if (zaidnaqs_b(result->str[index.i][index.j]))
			if (result->str[index.i][index.j++] == '-')
				index.r *= -1;
		while (result->str[index.i][index.j])
			index = small_atoi_bonus (result, index);
		result->nb[index.k] *= index.r;
		if (overflow_check_bonus(result->nb[index.k]))
			return (free(result->nb), -1);
		index.i++;
		index.k++;
		index.r = 1;
	}
	return (1);
}

t_indexes	fill_str2_bonus(t_indexes index, t_extracter *result, char **av)
{
	while (dgt_bonus(av[index.i][index.j]) || zaidnaqs_b(av[index.i][index.j]))
	{
		if (index.r == 0)
		{
			if (prepare_str_bonus (&result->str[index.k], 12) == -1)
			{
				while (index.f < index.k)
					freestr_bonus (&result->str[index.f++]);
				return (index.i = -1, index);
			}
			index.r = 1;
		}
		if (av[index.i][index.j] == '-' || av[index.i][index.j] == '+')
			result->str[index.k][index.c++] = av[index.i][index.j++];
		if (index.c >= 11)
		{
			while (index.f <= index.k)
				freestr_bonus (&result->str[index.f++]);
			return (index.i = -1, index);
		}
		index = handle_strflow_b (index, result, av);
	}
	return (index);
}

t_indexes	fill_str_loop_bonus(t_indexes index, char **av)
{
	while (spc_bonus(av[index.i][index.j]))
	{
		index.r = 0;
		index.j += 1;
	}
	return (index);
}
