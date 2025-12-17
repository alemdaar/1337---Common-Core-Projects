/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:05:20 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/24 22:40:58 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	shift_up_2(t_stack **a, t_stack **b, t_size_time sizt, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		shift_up('c', a, sizt.a_size, 1);
		shift_up('c', b, sizt.b_size, 1);
		write(1, "rr\n", 3);
		i++;
	}
}

void	shift_down_2(t_stack **a, t_stack **b, t_size_time sizt, int times)
{
	int	i;

	i = 0;
	while (i < times)
	{
		shift_down('c', a, sizt.a_size, 1);
		shift_down('c', b, sizt.b_size, 1);
		write(1, "rrr\n", 4);
		i++;
	}
}

void	ssd(t_stack **a, t_stack **b, t_stack *shortest, t_size_time sizt)
{
	t_indexes	index;

	index.c = smaller_top(shortest);
	index.i = bigger_total(shortest) - index.c;
	if (shortest->direction == 'u' || shortest->direction == 'm')
	{
		shift_up_2(a, b, sizt, index.c);
		if (index.i)
		{
			if (shortest->top != index.c)
				shift_up ('b', b, sizt.b_size, index.i);
			else
				shift_up ('a', a, sizt.a_size, index.i);
		}
		return ;
	}
	shift_down_2(a, b, sizt, index.c);
	if (index.i)
	{
		if (shortest->top != index.c)
			shift_down ('b', b, sizt.b_size, index.i);
		else
			shift_down ('a', a, sizt.a_size, index.i);
	}
}

void	swm(t_stack **a, t_stack **b, t_stack *shortest, t_size_time sizt)
{
	t_indexes	index;
	t_stack		*tmp;

	tmp = shortest->target;
	index.c = smaller_top (shortest);
	index.i = bigger_total(shortest) - index.c;
	if (shortest->direction == 'u' || tmp->direction == 'u')
	{
		shift_up_2(a, b, sizt, index.c);
		if (index.i)
		{
			if (shortest->top != index.c)
				shift_up ('b', b, sizt.b_size, index.i);
			else
				shift_up ('a', a, sizt.a_size, index.i);
		}
		return ;
	}
	shift_down_2(a, b, sizt, index.c);
	if (index.i && shortest->top != index.c)
		shift_down ('b', b, sizt.b_size, index.i);
	else
		shift_down ('a', a, sizt.a_size, index.i);
}

void	nssd(t_stack **a, t_stack **b, t_stack *shortest, t_size_time sizt)
{
	t_stack	*tmp;

	tmp = shortest->target;
	if (shortest->direction == 'u')
		shift_up ('b', b, sizt.b_size, shortest->top);
	else if (shortest->direction == 'd')
		shift_down ('b', b, sizt.b_size, shortest->top);
	if (tmp->direction == 'u')
		shift_up ('a', a, sizt.a_size, tmp->top);
	else if (tmp->direction == 'd')
		shift_down ('a', a, sizt.a_size, tmp->top);
	return ;
}
