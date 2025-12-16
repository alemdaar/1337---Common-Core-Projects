/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:42:03 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/01 15:27:47 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	not_wall_x_f(t_player *player, t_map *map, t_cord *cord)
{
	int	tmp1;
	int	tmp2;

	tmp1 = get_sqr(player->xy_pixel[Y] + player->pdy);
	tmp2 = get_sqr(player->xy_pixel[X]);
	if (map->map[tmp1][tmp2] != '1')
		cord->y = player->pdy;
	tmp1 = get_sqr(player->xy_pixel[Y]);
	tmp2 = get_sqr(player->xy_pixel[X] + player->pdx);
	if (map->map[tmp1][tmp2] != '1')
		cord->x = player->pdx;
	return ;
}

void	there_wall_x_f(t_player *player, t_map *map, t_cord *cord)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;
	int	tmp4;

	tmp1 = get_sqr(player->xy_pixel[Y] + player->pdy);
	tmp2 = get_sqr(player->xy_pixel[X]);
	tmp3 = get_sqr(player->xy_pixel[Y]);
	tmp4 = get_sqr(player->xy_pixel[X] + player->pdx);
	if (map->map[tmp1][tmp2] != '1')
		cord->y = player->pdy;
	else if (map->map[tmp3][tmp4] != '1')
		cord->x = player->pdx;
	return ;
}

void	not_wall_x_b(t_player *player, t_map *map, t_cord *cord)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;
	int	tmp4;

	tmp1 = get_sqr(player->xy_pixel[Y] - player->pdy);
	tmp2 = get_sqr(player->xy_pixel[X]);
	tmp3 = get_sqr(player->xy_pixel[Y]);
	tmp4 = get_sqr(player->xy_pixel[X] - player->pdx);
	if (map->map[tmp1][tmp2] != '1')
		cord->y = player->pdy;
	if (map->map[tmp3][tmp4] != '1')
		cord->x = player->pdx;
	return ;
}

void	there_wall_x_b(t_player *player, t_map *map, t_cord *cord)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;
	int	tmp4;

	tmp1 = get_sqr(player->xy_pixel[Y] - player->pdy);
	tmp2 = get_sqr(player->xy_pixel[X]);
	tmp3 = get_sqr(player->xy_pixel[Y]);
	tmp4 = get_sqr(player->xy_pixel[X] - player->pdx);
	if (map->map[tmp1][tmp2] != '1')
		cord->y = player->pdy;
	else if (map->map[tmp3][tmp4] != '1')
		cord->x = player->pdx;
	return ;
}
