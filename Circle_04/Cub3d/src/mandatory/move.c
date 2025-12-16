/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:21:27 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/13 21:17:28 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	go_forward(t_player *player, t_map *map)
{
	t_cord	cord;
	int		tmp1;
	int		tmp2;
	int		i;

	i = 0;
	while (i < MOVE_SPEED)
	{
		cord.x = 0;
		cord.y = 0;
		tmp1 = get_sqr(player->xy_pixel[Y] + player->pdy);
		tmp2 = get_sqr(player->xy_pixel[X] + player->pdx);
		if (map->map[tmp1][tmp2] != '1')
			not_wall_x_f(player, map, &cord);
		else
			there_wall_x_f(player, map, &cord);
		player->xy_pixel[X] += cord.x;
		player->xy_pixel[Y] += cord.y;
		player->xy_tile[X] = get_sqr(player->xy_pixel[X]);
		player->xy_tile[Y] = get_sqr(player->xy_pixel[Y]);
		i++;
	}
	return (0);
}

int	go_back(t_player *player, t_map *map)
{
	t_cord	cord;
	int		tmp1;
	int		tmp2;
	int		i;

	i = 0;
	while (i < MOVE_SPEED)
	{
		cord.x = 0;
		cord.y = 0;
		tmp1 = get_sqr(player->xy_pixel[Y] - player->pdy);
		tmp2 = get_sqr(player->xy_pixel[X] - player->pdx);
		if (map->map[tmp1][tmp2] != '1')
			not_wall_x_b(player, map, &cord);
		else
			there_wall_x_b(player, map, &cord);
		player->xy_pixel[X] -= cord.x;
		player->xy_pixel[Y] -= cord.y;
		player->xy_tile[X] = get_sqr(player->xy_pixel[X]);
		player->xy_tile[Y] = get_sqr(player->xy_pixel[Y]);
		i++;
	}
	return (0);
}

int	go_left(t_player *player, t_map *map)
{
	t_cord	cord;
	int		tmp1;
	int		tmp2;
	int		i;

	i = 0;
	while (i < MOVE_SPEED)
	{
		cord.x = 0;
		cord.y = 0;
		tmp1 = get_sqr(player->xy_pixel[Y] - player->pdx);
		tmp2 = get_sqr(player->xy_pixel[X] + player->pdy);
		if (map->map[tmp1][tmp2] != '1')
			not_wall_x_l(player, map, &cord);
		else
			there_wall_x_l(player, map, &cord);
		player->xy_pixel[X] += cord.x;
		player->xy_pixel[Y] += cord.y;
		player->xy_tile[X] = get_sqr(player->xy_pixel[X]);
		player->xy_tile[Y] = get_sqr(player->xy_pixel[Y]);
		i++;
	}
	return (0);
}

int	go_right(t_player *player, t_map *map)
{
	t_cord	cord;
	int		tmp1;
	int		tmp2;
	int		i;

	i = 0;
	while (i < MOVE_SPEED)
	{
		cord.x = 0;
		cord.y = 0;
		tmp1 = get_sqr(player->xy_pixel[Y] + player->pdx);
		tmp2 = get_sqr(player->xy_pixel[X] - player->pdy);
		if (map->map[tmp1][tmp2] != '1')
			not_wall_x_r(player, map, &cord);
		else
			there_wall_x_r(player, map, &cord);
		player->xy_pixel[X] += cord.x;
		player->xy_pixel[Y] += cord.y;
		player->xy_tile[X] = get_sqr(player->xy_pixel[X]);
		player->xy_tile[Y] = get_sqr(player->xy_pixel[Y]);
		i++;
	}
	return (0);
}
