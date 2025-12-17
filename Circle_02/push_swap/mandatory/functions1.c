/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:04:38 by oelhasso          #+#    #+#             */
/*   Updated: 2025/01/26 21:04:13 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	freestr(char **adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}

void	free_str2(char ***adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}

void	free_longlong(long long **adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}

void	free_result(t_extracter **adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}

void	free_node(t_stack **adata)
{
	if (adata && *adata)
	{
		free(*adata);
		*adata = NULL;
	}
	return ;
}
