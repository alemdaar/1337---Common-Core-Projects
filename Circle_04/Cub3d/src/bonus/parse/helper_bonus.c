/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:42:33 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/11 18:37:04 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_bonus.h"

void	err_msg(char *str)
{
	write(2, str, ft_strlen(str));
	exit(SUCCESSFUL);
}

void	free2d(char **arr2)
{
	int	i;

	i = 0;
	if (!arr2)
		return ;
	while (arr2[i])
		free(arr2[i++]);
	free(arr2);
}

int	len2d(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

bool	is_color(char *key)
{
	if (!ft_strcmp(key, "C") || !ft_strcmp(key, "F"))
		return (true);
	return (false);
}
