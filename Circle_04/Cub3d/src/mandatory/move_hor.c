/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_hor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:54:03 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/01 15:28:03 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	not_wall_x_l(t_player *player, t_map *map, t_cord *cord)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;
	int	tmp4;

	tmp1 = get_sqr(player->xy_pixel[Y] - player->pdx);
	tmp2 = get_sqr(player->xy_pixel[X]);
	tmp3 = get_sqr(player->xy_pixel[Y]);
	tmp4 = get_sqr(player->xy_pixel[X] + player->pdy);
	if (map->map[tmp1][tmp2] != '1')
		cord->y = -player->pdx;
	if (map->map[tmp3][tmp4] != '1')
		cord->x = player->pdy;
	return ;
}

void	there_wall_x_l(t_player *player, t_map *map, t_cord *cord)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;
	int	tmp4;

	tmp1 = get_sqr(player->xy_pixel[Y] - player->pdx);
	tmp2 = get_sqr(player->xy_pixel[X]);
	tmp3 = get_sqr(player->xy_pixel[Y]);
	tmp4 = get_sqr(player->xy_pixel[X] + player->pdy);
	if (map->map[tmp1][tmp2] != '1')
		cord->y = -player->pdx;
	else if (map->map[tmp3][tmp4] != '1')
		cord->x = player->pdy;
	return ;
}

void	not_wall_x_r(t_player *player, t_map *map, t_cord *cord)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;
	int	tmp4;

	tmp1 = get_sqr(player->xy_pixel[Y] + player->pdx);
	tmp2 = get_sqr(player->xy_pixel[X]);
	tmp3 = get_sqr(player->xy_pixel[Y]);
	tmp4 = get_sqr(player->xy_pixel[X] - player->pdy);
	if (map->map[tmp1][tmp2] != '1')
		cord->y = player->pdx;
	if (map->map[tmp3][tmp4] != '1')
		cord->x = -player->pdy;
	return ;
}

void	there_wall_x_r(t_player *player, t_map *map, t_cord *cord)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;
	int	tmp4;

	tmp1 = get_sqr(player->xy_pixel[Y] + player->pdx);
	tmp2 = get_sqr(player->xy_pixel[X]);
	tmp3 = get_sqr(player->xy_pixel[Y]);
	tmp4 = get_sqr(player->xy_pixel[X] - player->pdy);
	if (map->map[tmp1][tmp2] != '1')
		cord->y = player->pdx;
	else if (map->map[tmp3][tmp4] != '1')
		cord->x = -player->pdy;
	return ;
}
