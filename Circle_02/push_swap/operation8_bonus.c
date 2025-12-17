/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation8_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:03:52 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/30 21:13:44 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	shift_upp(t_stack **a, int times)
{
	t_indexes	index;
	t_stack		*tmp;
	t_stack		*first;

	index.i = 0;
	if (stack_size(*a) > 1)
	{
		while (index.i < times)
		{
			first = *a;
			*a = (*a)->next;
			tmp = *a;
			first->next = NULL;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = first;
			index.i++;
		}
	}
	return ;
}

void	shift_downn(t_stack **head, int times)
{
	t_indexes	index;
	t_stack		*tmp;
	t_stack		*previous;

	index.i = 0;
	if (stack_size(*head) > 1)
	{
		while (index.i < times)
		{
			tmp = *head;
			while (tmp->next)
			{
				previous = tmp;
				tmp = tmp->next;
			}
			previous->next = NULL;
			tmp->next = *head;
			*head = tmp;
			index.i++;
		}
	}
	return ;
}

void	push_f(t_stack **a, t_stack **b, char *inst)
{
	if (inst[1] == 'a')
		pushh('a', a, b);
	else
		pushh('b', a, b);
	return ;
}

void	swap_f(t_stack **a, t_stack **b, char *inst)
{
	if (inst[1] == 'a')
		swapp('a', a, b);
	else if (inst[1] == 'b')
		swapp('b', a, b);
	else
		swapp('c', a, b);
	return ;
}

void	shift_f(t_stack **a, t_stack **b, char *inst)
{
	if (inst[1] == 'r')
	{
		if (inst[2] == 'a')
			shift_downn(a, 1);
		else if (inst[2] == 'b')
			shift_downn(b, 1);
		else
		{
			shift_downn(a, 1);
			shift_downn(b, 1);
		}
	}
	else if (inst[1] == 'a')
		shift_upp(a, 1);
	else if (inst[1] == 'b')
		shift_upp(b, 1);
	else
	{
		shift_upp(a, 1);
		shift_upp(b, 1);
	}
	return ;
}
