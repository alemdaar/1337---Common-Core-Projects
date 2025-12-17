/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:05:37 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/30 20:42:55 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	comeback_to_a(t_stack **a, t_stack **b, t_size_time sizt)
{
	t_stack	*shortest;
	t_stack	*tmp;

	sizt.a_size = 3;
	while (sizt.b_size)
	{
		create_tops (*a, sizt.a_size);
		create_tops (*b, sizt.b_size);
		make_target(*a, b);
		shortest = shortest_move (*b);
		tmp = shortest->target;
		if (shortest->direction == 't' && tmp->direction == 't')
		{
			push ('a', a, b);
			sizt.b_size--;
			sizt.a_size++;
			continue ;
		}
		move (a, b, shortest, sizt);
		sizt.a_size++;
		sizt.b_size--;
	}
}

t_stack	*a_location(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->index == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void	topping_a(t_stack **a, int elements_size)
{
	t_stack	*aa;

	create_tops (*a, elements_size);
	aa = a_location(*a);
	if (aa->direction == 'u' || aa->direction == 'm')
		shift_up ('a', a, elements_size, aa->top);
	else
		shift_down ('a', a, elements_size, aa->top);
	return ;
}

int	algorithm(t_stack **a, t_stack **b, int elements_size)
{
	t_size_time	sizt;

	push_to_b (a, b, elements_size);
	if (!is_sorted(a))
		sort_3_elements (a);
	sizt.b_size = elements_size - 3;
	comeback_to_a (a, b, sizt);
	if ((*a)->index != 1)
		topping_a(a, elements_size);
	return (0);
}

void	push_swap(t_stack **a, int elements_size)
{
	t_stack	*b;

	b = NULL;
	if (!is_sorted(a))
		algorithm(a, &b, elements_size);
	while ((*a))
	{
		free (*a);
		(*a) = (*a)->next;
	}
	return ;
}
