/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:51:37 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/15 10:20:59 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_bonus.h"

void	seterr(char *msg, t_map *map)
{
	if (map->success == true)
	{
		map->success = false;
		ft_strlcpy(map->errmsg, msg, 1024);
	}
}

// by god's will splits won't fail

// @param	key	texture id
// @param	val	texture path
// @note	only use after checking the identfier
void	settxtr(t_game *game, char *key, char *val)
{
	if (!key || !val)
		return (seterr("Bad texture entry", &game->map));
	if (!strcmp(key, "NO") && game->ntxt == NULL)
		game->ntxt = mlx_load_png(val);
	else if (!strcmp(key, "SO") && game->stxt == NULL)
		game->stxt = mlx_load_png(val);
	else if (!strcmp(key, "WE") && game->wtxt == NULL)
		game->wtxt = mlx_load_png(val);
	else if (!strcmp(key, "EA") && game->etxt == NULL)
		game->etxt = mlx_load_png(val);
	else if (!strcmp(key, "EA") && game->etxt == NULL)
		game->etxt = mlx_load_png(val);
}

// @param	key	color idthe full line (X RRR,GGG,BBB)
// @param	val	RRR,GGG,BBB
void	setcolor(t_game *game, char *key, char *val)
{
	char			**clrs;
	unsigned int	c;

	if (!key || !val || !check_clr(val, game))
		return (seterr("Bad color entry", &game->map));
	clrs = ft_split(val, ',');
	c = (ft_atoi(clrs[0]) << 24) | (ft_atoi(clrs[1]) << 16);
	c = c | (ft_atoi(clrs[2]) << 8) | 0xFF;
	if (*key == 'F')
		game->map.fcolor = c;
	else
		game->map.ccolor = c;
	free2d(clrs);
	return ;
}
