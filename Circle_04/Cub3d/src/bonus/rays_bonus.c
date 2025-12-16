/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:19:34 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/15 12:03:15 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

// treats extremes as walls shouldn't be needed when
// parsin starts checkig for boundaries...
bool	is_wall(t_game *game, int mapY, int mapX)
{
	if (!game || !game->map.map)
		return (true);
	if (mapY < 0 || mapX < 0 || mapY >= MAX_MAP_SZ)
		return (true);
	if (!game->map.map[mapY])
		return (true);
	if ((size_t)mapX >= strlen(game->map.map[mapY]))
		return (true);
	if (game->map.map[mapY][mapX] == 'D' && !game->door)
		return (1);
	return (game->map.map[mapY][mapX] == '1');
}

static void	wall_logic(t_game *game, int ray_id, t_ray_state *s)
{
	if (s->side == hor)
		s->dist = (s->mapx - s->posx + (1 - s->stepx) / 2.0) / s->raydirx;
	else
		s->dist = (s->mapy - s->posy + (1 - s->stepy) / 2.0) / s->raydiry;
	if (s->dist == 0.0)
		s->dist = 0.1;
	display_wall(game, ray_id, *s);
}

static void	dda_loop(t_game *game, int ray_id, t_ray_state *s)
{
	int	max_steps;

	max_steps = MAX_MAP_SZ;
	while (max_steps-- > 0)
	{
		if (s->sidedistx < s->sidedisty)
		{
			s->sidedistx += s->deltadistx;
			s->mapx += s->stepx;
			s->side = hor;
		}
		else
		{
			s->sidedisty += s->deltadisty;
			s->mapy += s->stepy;
			s->side = ver;
		}
		if (is_wall(game, s->mapy, s->mapx))
		{
			wall_logic(game, ray_id, s);
			break ;
		}
	}
}

static void	cast_ray2(t_game *game, int ray_id)
{
	t_ray_state	s;

	init_ray_state(game, ray_id, &s);
	dda_loop(game, ray_id, &s);
}

int	cast_rays(t_game *game)
{
	int	ray_id;

	ray_id = 0;
	while (ray_id < WINDOW_W)
	{
		game->rays[ray_id][A] = game->player.angle_x + ((double)FOV / 2.0)
			- ((double)ray_id / (double)WINDOW_W) * (double)FOV;
		cast_ray2(game, ray_id);
		ray_id++;
	}
	return (0);
}
