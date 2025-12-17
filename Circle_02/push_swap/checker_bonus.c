/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:01:52 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/30 16:12:12 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_extracter	*result;
	int			r;

	if (ac == 1)
		return (0);
	result = correct_nb_bonus(av, ac);
	if (result == NULL)
		return (write (2, "Error\n", 6), 1);
	if (raqm_meawd_bonus (result) == -1)
		return (write (2, "Error\n", 6), free_result_b (&result), 1);
	a = make_stack_a_bonus(result);
	if (!a)
		return (write (2, "Error\n", 6), free_result_b (&result), 1);
	b = NULL;
	r = operation(&a, &b);
	free(result);
	if (r == -1)
		return (free_stack(&a, &b), write (1, "Error\n", 6), 1);
	if (r == 0)
		return (free_stack(&a, &b), write (1, "KO\n", 3), 1);
	return (free_stack(&a, &b), write (1, "OK\n", 3), 0);
}
