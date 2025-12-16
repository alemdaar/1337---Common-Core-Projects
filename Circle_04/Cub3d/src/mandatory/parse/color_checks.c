/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:48:48 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/11 18:32:28 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static bool	is_digits(char *str)
{
	if (!str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

// checks: 	1. full len
// 			2. all digits
// 			3. 0 <= values <= 255
// 			4. we have 3 values R G B
// @param	val RRR,GGG,BBB
bool	check_clr(char *val, t_game *game)
{
	char	**clr;
	bool	r;
	int		i;

	clr = ft_split(val, ',');
	if (len2d(clr) != 3)
	{
		seterr("Bad color value", &game->map);
		free2d(clr);
		return (false);
	}
	r = true;
	i = 0;
	while (clr[i])
	{
		if (ft_strlen(clr[i]) < 1 || ft_strlen(clr[i]) > 3 || !is_digits(clr[i])
			|| ft_atoi(clr[i]) > 255 || ft_atoi(clr[i]) < 0)
			r = false;
		i++;
	}
	free2d(clr);
	if (r == false)
		seterr("Bad color value", &game->map);
	return (true);
}
