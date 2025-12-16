/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:21:27 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/14 13:28:21 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	go_forward(t_game *game, t_player *player, t_map *map)
{
	t_cord	cord;
	int		tmp1;
	int		tmp2;
	int		i;

	i = 0;
	while (i++ < MOVE_SPEED)
	{
		cord.x = 0;
		cord.y = 0;
		tmp1 = get_sqr(player->xy_pixel[Y] + player->pdy);
		tmp2 = get_sqr(player->xy_pixel[X] + player->pdx);
		if (map->map[tmp1][tmp2] != '1'
			&& (map->map[tmp1][tmp2] != 'D' || game->door != 0))
		{
			not_wall_x_f(game, map, &cord);
		}
		else
			there_wall_x_f(game, map, &cord);
		player->xy_pixel[X] += cord.x;
		player->xy_pixel[Y] += cord.y;
		player->xy_tile[X] = get_sqr(player->xy_pixel[X]);
		player->xy_tile[Y] = get_sqr(player->xy_pixel[Y]);
	}
	return (0);
}

int	go_back(t_game *game, t_player *player, t_map *map)
{
	t_cord	cord;
	int		tmp1;
	int		tmp2;
	int		i;

	i = 0;
	while (i++ < MOVE_SPEED)
	{
		cord.x = 0;
		cord.y = 0;
		tmp1 = get_sqr(player->xy_pixel[Y] - player->pdy);
		tmp2 = get_sqr(player->xy_pixel[X] - player->pdx);
		if (map->map[tmp1][tmp2] != '1'
			&& (map->map[tmp1][tmp2] != 'D' || game->door != 0))
		{
			not_wall_x_b(game, map, &cord);
		}
		else
			there_wall_x_b(game, map, &cord);
		player->xy_pixel[X] -= cord.x;
		player->xy_pixel[Y] -= cord.y;
		player->xy_tile[X] = get_sqr(player->xy_pixel[X]);
		player->xy_tile[Y] = get_sqr(player->xy_pixel[Y]);
	}
	return (0);
}

int	go_left(t_game *game, t_player *player, t_map *map)
{
	t_cord	cord;
	int		tmp1;
	int		tmp2;
	int		i;

	i = 0;
	while (i++ < MOVE_SPEED)
	{
		cord.x = 0;
		cord.y = 0;
		tmp1 = get_sqr(player->xy_pixel[Y] - player->pdx);
		tmp2 = get_sqr(player->xy_pixel[X] + player->pdy);
		if (map->map[tmp1][tmp2] != '1'
			&& (map->map[tmp1][tmp2] != 'D' || game->door != 0))
		{
			not_wall_x_l(game, map, &cord);
		}
		else
			there_wall_x_l(game, map, &cord);
		player->xy_pixel[X] += cord.x;
		player->xy_pixel[Y] += cord.y;
		player->xy_tile[X] = get_sqr(player->xy_pixel[X]);
		player->xy_tile[Y] = get_sqr(player->xy_pixel[Y]);
	}
	return (0);
}

int	go_right(t_game *game, t_player *player, t_map *map)
{
	t_cord	cord;
	int		tmp1;
	int		tmp2;
	int		i;

	i = 0;
	while (i++ < MOVE_SPEED)
	{
		cord.x = 0;
		cord.y = 0;
		tmp1 = get_sqr(player->xy_pixel[Y] + player->pdx);
		tmp2 = get_sqr(player->xy_pixel[X] - player->pdy);
		if (map->map[tmp1][tmp2] != '1'
			&& (map->map[tmp1][tmp2] != 'D' || game->door != 0))
		{
			not_wall_x_r(game, map, &cord);
		}
		else
			there_wall_x_r(game, map, &cord);
		player->xy_pixel[X] += cord.x;
		player->xy_pixel[Y] += cord.y;
		player->xy_tile[X] = get_sqr(player->xy_pixel[X]);
		player->xy_tile[Y] = get_sqr(player->xy_pixel[Y]);
	}
	return (0);
}
