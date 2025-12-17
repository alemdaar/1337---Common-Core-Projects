/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation5_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:01:59 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/30 21:13:26 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	freestr_bonus(char **adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}

void	free_str2_b(char ***adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}

void	free_longlong_bonus(long long **adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}

void	free_result_b(t_extracter **adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}

void	free_node_bonus(t_stack **adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}
