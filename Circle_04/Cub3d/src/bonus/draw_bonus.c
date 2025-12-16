/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 20:48:56 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/15 12:01:45 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	draw_player2d(mlx_image_t *img, int cx, int cy, double angle_deg)
{
	t_d_2dp	v;

	v = init_draw_player2d_vars(cx, cy, angle_deg);
	while (v.y <= CIRCLE_RADIUS)
	{
		v.x = -CIRCLE_RADIUS;
		while (v.x <= CIRCLE_RADIUS) 
		{
			v.p.x = cx + v.x;
			v.p.y = cy + v.y;
			if (v.p.x < 0 || v.p.x >= (int)img->width
				|| v.p.y < 0 || v.p.y >= (int)img->height)
			{
				v.x++;
				continue ;
			}
			if (v.x * v.x + v.y * v.y > CIRCLE_RADIUS * CIRCLE_RADIUS)
			{
				v.x++;
				continue ;
			}
			draw_player2d_pixel(img, &v);
		}
		v.y++;
	}
}

int	draw_2dpixel(t_game *game, t_cord map2d_cord, double x, double y)
{
	uint32_t	color;

	prepare_color(&game->map, map2d_cord.x, map2d_cord.y, &color);
	mlx_put_pixel(game->img, x + BT, y + BT, color);
	return (0);
}

static void	draw_border(t_game *game, int color)
{
	t_draw_border	v;

	v.start_x = 0;
	v.start_y = 0;
	v.end_x = 174 + (BT * 2);
	v.end_y = 174 + (BT * 2);
	v.t = 0;
	while (v.t < BT)
	{
		v.x = v.start_x;
		while (v.x <= v.end_x)
			mlx_put_pixel(game->img, v.x++, v.start_y + v.t, color);
		v.x = v.start_x;
		while (v.x <= v.end_x)
			mlx_put_pixel(game->img, v.x++, v.end_y - v.t, color);
		v.y = v.start_y; 
		while (v.y <= v.end_y)
			mlx_put_pixel(game->img, v.start_x + v.t, v.y++, color);
		v.y = v.start_y;
		while (v.y <= v.end_y)
			mlx_put_pixel(game->img, v.end_x - v.t, v.y++, color);
		v.t++;
	}
}

int	draw_2dmap(t_game *game)
{
	t_cord	map2d_cord;
	int		tmp_x;
	int		tmp_y;

	draw_border(game, 0x5C3317FF);
	map2d_cord.y = game->player.xy_pixel[Y] - CEN_2_SIDE;
	tmp_y = 0;
	while (tmp_y < (SQUARE_LEN * MAP2D_LEN))
	{
		map2d_cord.x = game->player.xy_pixel[X] - CEN_2_SIDE;
		tmp_x = 0;
		while (tmp_x < (SQUARE_LEN * MAP2D_LEN))
		{
			draw_2dpixel(game, map2d_cord, tmp_x, tmp_y);
			map2d_cord.x += 1;
			tmp_x += 1;
		}
		tmp_y += 1;
		map2d_cord.y += 1;
	}
	draw_player2d(game->img, CEN_2_SIDE, CEN_2_SIDE, game->player.angle_x);
	return (0);
}
