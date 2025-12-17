/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions12.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:06:00 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/31 22:14:40 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	find_target_in_b(t_stack **current_b, t_stack *a)
{
	t_stack	*store;

	if (nothing_bigger((*current_b)->number, a) == -1)
	{
		the_smallest(current_b, a);
		return ;
	}
	while (a)
	{
		if (a->number > (*current_b)->number)
		{
			store = a;
			break ;
		}
		a = a->next;
	}
	a = a->next;
	while (a)
	{
		if (store->number > a->number && a->number > (*current_b)->number)
			store = a;
		a = a->next;
	}
	(*current_b)->target = store;
}

int	bigger_total(t_stack *head)
{
	t_stack	*tmp;

	tmp = head->target;
	if (tmp->top >= head->top)
		return (tmp->top);
	return (head->top);
}

t_indexes	small_atoi(t_extracter *result, t_indexes index)
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

int	overflow_check(long long nb)
{
	if (nb > 2147483647 || nb < -2147483648)
		return (1);
	return (0);
}

t_indexes	handle_strflow(t_indexes index, t_extracter *result, char **av)
{
	while (av[index.i][index.j] == '0' && av[index.i][index.j + 1] == '0')
		index.j++;
	result->str[index.k][index.c++] = av[index.i][index.j++];
	result->str[index.k][index.c] = '\0';
	return (index);
}
