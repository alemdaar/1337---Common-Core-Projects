/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:05:41 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/30 20:53:28 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	move(t_stack **a, t_stack **b, t_stack *shortest, t_size_time sizt)
{
	t_stack	*aa;

	aa = shortest->target;
	if (shortest->direction == 't')
	{
		if (aa->direction == 'u' || aa->direction == 'm')
			shift_up('a', a, sizt.a_size, aa->top);
		else
			shift_down('a', a, sizt.a_size, aa->top);
	}
	else if (aa->direction == 't')
	{
		if (shortest->direction == 'u' || shortest->direction == 'm')
			shift_up('b', b, sizt.b_size, shortest->top);
		else
			shift_down('b', b, sizt.b_size, shortest->top);
	}
	else if (shortest->direction == aa->direction)
		ssd (a, b, shortest, sizt);
	else if (shortest->direction == 'm' || aa->direction == 'm')
		swm (a, b, shortest, sizt);
	else
		nssd (a, b, shortest, sizt);
	push ('a', a, b);
}

t_stack	*aqrab_treq(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*store;

	tmp = head;
	store = tmp;
	tmp = tmp->next;
	if (store->total != 0)
	{
		while (tmp)
		{
			if (store->total > tmp->total)
				store = tmp;
			tmp = tmp->next;
		}
	}
	return (store);
}

t_stack	*magic_trick(t_stack *head)
{
	t_stack	*aqrab_wahda;

	update_totals(head);
	aqrab_wahda = aqrab_treq(head);
	return (aqrab_wahda);
}

t_stack	*shortest_move(t_stack *head)
{
	t_stack	*tmp_b;
	t_stack	*tmp_target;
	t_stack	*aqrab_wahda;

	tmp_b = head;
	while (tmp_b)
	{
		tmp_target = tmp_b->target;
		tmp_b->total = tmp_target->top + tmp_b->top ;
		tmp_b = tmp_b->next;
	}
	aqrab_wahda = magic_trick (head);
	return (aqrab_wahda);
}

void	sort_sghera(t_stack **a, int elements_size)
{
	if (is_sorted(a) == 0)
	{
		if (elements_size == 2)
			swap('a', a, NULL);
		else
			sort_3_elements(a);
	}
	while ((*a))
	{
		free (*a);
		(*a) = (*a)->next;
	}
}
