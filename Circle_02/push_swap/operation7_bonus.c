/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation7_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:03:19 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/30 21:13:38 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	calculate_nbs_bonus(int ac, char **av)
{
	t_indexes	index;

	index.i = 1;
	index.c = 0;
	index.r = 0;
	while (index.i < ac)
	{
		index.j = 0;
		if (!av[index.i][index.j])
			return (-3);
		while (av[index.i][index.j])
		{
			index = calculate_nbs2_bonus(index, av);
			if (index.c == -1)
				return (-1);
			if (!av[index.i][index.j])
				break ;
			if (dgt_bonus(av[index.i][index.j]) == 0)
				if (spc_bonus(av[index.i][index.j]) == 0)
					return (-1);
		}
		index.i += 1;
	}
	return (index.c);
}

t_extracter	*correct_nb_bonus(char **av, int ac)
{
	t_extracter	*result;
	t_indexes	index;

	result = (t_extracter *) malloc (sizeof(t_extracter));
	if (!result)
		return (NULL);
	result->count = calculate_nbs_bonus(ac, av);
	if (result->count < 1)
		return (free_result_b(&result), NULL);
	result->str = (char **) malloc (result->count * (sizeof(char *)));
	if (!result->str)
		return (free_result_b (&result), NULL);
	index.r = fill_str_bonus(result, ac, av);
	if (index.r == -1)
		return (free_str2_b (&result->str), free_result_b (&result), NULL);
	index.r = extract_nbs_bonus (result);
	index.i = 0;
	while (index.i < result->count)
		freestr_bonus (&result->str[index.i++]);
	free_str2_b (&result->str);
	if (index.r == -1)
		return (free_result_b (&result), NULL);
	return (result);
}

int	is_sorted(t_stack **a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = *a;
	while (tmp1->next)
	{
		tmp2 = tmp1->next;
		if (tmp1->number > tmp2->number)
			return (0);
		tmp1 = tmp1->next;
	}
	return (1);
}

void	pushh(char type, t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (type == 'a')
	{
		if (*b)
		{
			tmp = *b;
			(*b) = (*b)->next;
			tmp->next = (*a);
			(*a) = tmp;
		}
		return ;
	}
	if (*a)
	{
		tmp = (*a);
		(*a) = (*a)->next;
		tmp->next = *b;
		(*b) = tmp;
	}
	return ;
}

void	swapp(char type, t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	if ((type == 'a' || type == 'c') && stack_size(*a) > 1)
	{
		tmp_a = *a;
		tmp = (*a)->next;
		tmp_a->next = tmp->next;
		tmp->next = tmp_a;
		*a = tmp;
	}
	if ((type == 'b' || type == 'c') && stack_size(*b) > 1)
	{
		tmp_b = *b;
		tmp = (*b)->next;
		tmp_b->next = tmp->next;
		tmp->next = tmp_b;
		*b = tmp_b;
	}
	return ;
}
