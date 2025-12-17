/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:59:34 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/30 21:13:13 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*ft_lstnew_bonus(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->number = content;
	node->next = NULL;
	return (node);
}

t_stack	*ft_lstlast_bonus(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_bonus(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast_bonus(*lst);
	last_node->next = new;
}

t_stack	*make_stack_a_bonus(t_extracter *result)
{
	t_indexes	index;
	t_stack		*node;
	t_stack		*head;

	head = NULL;
	index.i = 0;
	while (index.i < result->count)
	{
		node = ft_lstnew_bonus (result->nb[index.i]);
		if (!node)
		{
			while (head)
			{
				free_node_bonus(&head);
				head = head->next;
			}
			return (free_longlong_bonus (&result->nb), NULL);
		}
		ft_lstadd_back_bonus (&head, node);
		index.i++;
	}
	fill_index_bonus(head, result);
	return (free_longlong_bonus (&result->nb), head);
}

int	raqm_meawd_bonus(t_extracter *result)
{
	t_indexes	index;

	index.i = 0;
	while (index.i < result->count)
	{
		index.j = index.i + 1;
		while (index.j < result->count)
		{
			if (result->nb[index.i] == result->nb[index.j])
				return (free_longlong_bonus (&result->nb), -1);
			index.j++;
		}
		index.i++;
	}
	return (0);
}
