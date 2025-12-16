/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_stuff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:35:17 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/11 18:32:44 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	setup_player(t_player *player, char c, int x, int y)
{
	if (c == 'N')
		player->angle = 90;
	else if (c == 'S')
		player->angle = 180;
	else if (c == 'E')
		player->angle = 0;
	else if (c == 'W')
		player->angle = 270;
	player->xy_tile[X] = x;
	player->xy_tile[Y] = y;
	player->xy_pixel[X] = ((x * SQUARE_LEN) + SQUARE_LEN / 2);
	player->xy_pixel[Y] = ((y * SQUARE_LEN) + SQUARE_LEN / 2);
	player->pdx = cos(player->angle * M_PI / 180.0);
	player->pdy = -sin(player->angle * M_PI / 180.0);
}

void	find_player(t_map *map, t_player *player)
{
	int	y;
	int	x;
	int	n;

	n = 0;
	if (map->success == false || !map->map)
		return ;
	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (is_player(map->map[y][x]))
			{
				setup_player(player, map->map[y][x], x, y);
				n++;
			}
			x++;
		}
		y++;
	}
	if (n == 0 || n > 1)
		seterr("bad amount of players", map);
}
