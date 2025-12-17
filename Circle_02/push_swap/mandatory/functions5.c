/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:05:28 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/25 11:35:10 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	store_index(t_extracter *result, t_stack *head)
{
	t_indexes	index;
	t_stack		*tmp;

	index.j = 0;
	tmp = head;
	while (tmp)
	{
		index.i = 0;
		while (index.i < result->count)
		{
			if (tmp->number == result->nb[index.i])
			{
				tmp->index = index.i + 1;
				break ;
			}
			index.i++;
		}
		tmp = tmp->next;
	}
	return ;
}

void	fill_index(t_stack *head, t_extracter *result)
{
	t_indexes	index;

	index.i = 0;
	while (index.i < result->count - 1)
	{
		index.j = index.i + 1;
		while (index.j < result->count)
		{
			if (result->nb[index.i] > result->nb[index.j])
			{
				swap_nbs_with_tmp (result->nb + index.i, result->nb + index.j);
				index.j = index.i + 1;
				continue ;
			}
			index.j ++;
		}
		index.i ++;
	}
	store_index(result, head);
	return ;
}

int	extract_nbs(t_extracter *result)
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
		if (its_zaidnaqs(result->str[index.i][index.j]))
			if (result->str[index.i][index.j++] == '-')
				index.r *= -1;
		while (result->str[index.i][index.j])
			index = small_atoi (result, index);
		result->nb[index.k] *= index.r;
		if (overflow_check(result->nb[index.k]))
			return (free(result->nb), -1);
		index.i++;
		index.k++;
		index.r = 1;
	}
	return (1);
}

int	prepare_str(char **str, int count)
{
	int	i;

	i = 0;
	*str = (char *) malloc (sizeof(char) * (count + 1));
	if (!*str)
		return (-1);
	while (i < count)
	{
		(*str)[i] = 0;
		i++;
	}
	(*str)[count] = '\0';
	return (1);
}

int	raqm_meawd(t_extracter *result)
{
	t_indexes	index;

	index.i = 0;
	while (index.i < result->count)
	{
		index.j = index.i + 1;
		while (index.j < result->count)
		{
			if (result->nb[index.i] == result->nb[index.j])
				return (free_longlong (&result->nb), -1);
			index.j++;
		}
		index.i++;
	}
	return (0);
}
