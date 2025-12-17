/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 21:12:47 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/31 22:14:22 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_indexes	handle_strflow_b(t_indexes index, t_extracter *result, char **av)
{
	while (av[index.i][index.j] == '0' && dgt(av[index.i][index.j + 1]))
		index.j++;
	result->str[index.k][index.c++] = av[index.i][index.j++];
	result->str[index.k][index.c] = '\0';
	return (index);
}

void	free_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (a || b)
	{
		while (*a)
		{
			tmp = *a;
			(*a) = (*a)->next;
			free(tmp);
		}
		while (*b)
		{
			tmp = *b;
			(*b) = (*b)->next;
			free(tmp);
		}
	}
}

void	action(t_stack **a, t_stack **b, char *inst)
{
	if (inst[0] == 'p')
		push_f(a, b, inst);
	else if (inst[0] == 's')
		swap_f(a, b, inst);
	else
		shift_f(a, b, inst);
}

int	valid_instruction(char *str)
{
	if (str[0] == 'p')
	{
		if (str[1] == 'a' || str[1] == 'b')
			if (str[2] == '\n')
				return (1);
	}
	else if (str[0] == 's')
	{
		if (str[1] == 'a' || str[1] == 'b' || str[1] == 's')
			if (str[2] == '\n')
				return (1);
	}
	else if (str[0] == 'r')
	{
		if (str[1] == 'a' || str[1] == 'b' || str[1] == 'r')
			if (str[2] == '\n')
				return (1);
		if (str[1] == 'r')
			if (str[2] == 'a' || str[2] == 'b' || str[2] == 'r')
				if (str[3] == '\n')
					return (1);
	}
	return (0);
}

int	operation(t_stack **a, t_stack **b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (str[0] == '\n' || !str[0])
			break ;
		if (!valid_instruction(str))
			return (free_stack(a, b), write (1, "Error\n", 7), -1);
		action (a, b, str);
	}
	if (is_sorted(a) || b == NULL)
		return (1);
	return (0);
}
