/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:51:37 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/11 18:33:15 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static void	ray_state_2(t_ray_state *s)
{
	if (s->raydirx == 0.0)
		s->deltadistx = INFINITY;
	else
		s->deltadistx = fabs(1.0 / s->raydirx);
	if (s->raydiry == 0.0)
		s->deltadisty = INFINITY;
	else
		s->deltadisty = fabs(1.0 / s->raydiry);
	if (s->raydirx < 0)
	{
		s->stepx = -1;
		s->sidedistx = (s->posx - (double)s->mapx) * s->deltadistx;
	}
	else
	{
		s->stepx = 1;
		s->sidedistx = ((double)s->mapx + 1.0 - s->posx) * s->deltadistx;
	}
}

static void	ray_state_1(t_game *game, int ray_id, t_ray_state *s)
{
	t_player	*player;

	player = &game->player;
	game->rays[ray_id][PDX] = s->raydirx;
	game->rays[ray_id][PDY] = s->raydiry;
	s->posx = player->xy_pixel[X] / (double)SQUARE_LEN;
	s->posy = player->xy_pixel[Y] / (double)SQUARE_LEN;
	s->mapx = (int)s->posx;
	s->mapy = (int)s->posy;
}

void	init_ray_state(t_game *game, int ray_id, t_ray_state *s)
{
	double	ray_angle;

	ray_angle = game->rays[ray_id][A] * M_PI / 180.0;
	s->raydirx = cos(ray_angle);
	s->raydiry = -sin(ray_angle);
	ray_state_1(game, ray_id, s);
	ray_state_2(s);
	if (s->raydiry < 0)
	{
		s->stepy = -1;
		s->sidedisty = (s->posy - (double)s->mapy) * s->deltadisty;
	}
	else
	{
		s->stepy = 1;
		s->sidedisty = ((double)s->mapy + 1.0 - s->posy) * s->deltadisty;
	}
	s->side = hor;
	s->dist = 0.0;
}
