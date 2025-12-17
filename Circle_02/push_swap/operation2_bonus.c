/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:13:03 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/30 21:13:04 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	stack_size(t_stack *head)
{
	t_indexes	index;
	t_stack		*tmp;

	tmp = head;
	index.i = 0;
	while (tmp)
	{
		index.i++;
		tmp = tmp->next;
	}
	return (index.i);
}

int	prepare_str_bonus(char **str, int count)
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

void	swap_nbs_b(long long *a, long long *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	store_index_bonus(t_extracter *result, t_stack *head)
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

void	fill_index_bonus(t_stack *head, t_extracter *result)
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
				swap_nbs_b (result->nb + index.i, result->nb + index.j);
				index.j = index.i + 1;
				continue ;
			}
			index.j ++;
		}
		index.i ++;
	}
	store_index_bonus(result, head);
	return ;
}
