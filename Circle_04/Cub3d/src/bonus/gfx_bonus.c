/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:32:37 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/15 13:02:12 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

u_int32_t	getrgba(uint8_t *arr, int bar_idx)
{
	u_int32_t	f;

	f = arr[bar_idx] << 24 | arr[bar_idx + 1] << 16;
	return (f | arr[bar_idx + 2] << 8 | arr[bar_idx + 3]);
}

void	actualwall(int arr[], t_ptcl pt, mlx_texture_t *txt, t_game *game)
{
	int	y;

	if ((u_int32_t)arr[0] >= txt->width)
		return ;
	y = pt.start_y;
	while (y < pt.end_y)
	{
		pt.ty = pt.tex_pos;
		if (pt.ty >= 0 && pt.ty < (int)txt->height)
		{
			pt.pixel_idx = (pt.ty * (int)txt->width + (int)arr[0]) * 4;
			pt.color = getrgba(txt->pixels, pt.pixel_idx);
			mlx_put_pixel(game->img, arr[1], y, pt.color);
		}
		pt.tex_pos += pt.step;
		y++;
	}
}

// col -> index of column (all Ys that have same X in image)
// screen_x -> x in the screen
// distance -> perpondicular distance to the wall
void	putcol(int arr[], double distance, t_game *game, mlx_texture_t *txt)
{
	t_ptcl	pt;
	int		y;

	if (!txt)
		return ;
	pt.col_h = WINDOW_H / distance;
	pt.step = txt->height / (double)pt.col_h;
	pt.start_y = (WINDOW_H / 2.0 + 0 - pt.col_h / 2.0) + game->player.pitch; // rule of where is the highest point of the wall
	pt.tex_pos = 0.0;
	if (pt.start_y < 0)
	{
		pt.tex_pos = -pt.start_y * pt.step; // 5 * 4
		pt.end_y = pt.start_y + pt.col_h;
		if (pt.end_y < 0)
			pt.end_y = 0;
		pt.start_y = 0;
	} else 
		pt.end_y = pt.start_y + pt.col_h;
	if (pt.end_y >= WINDOW_H) 
		pt.end_y = WINDOW_H;
	y = 0;
	while (y < pt.start_y) // mn 0 ta n hight d wall
		mlx_put_pixel(game->img, arr[1], y++, game->map.ccolor);
	y = pt.end_y;
	while (y < WINDOW_H) // mn lakhar d wall n qa3
		mlx_put_pixel(game->img, arr[1], y++, game->map.fcolor);
	actualwall(arr, pt, txt, game);
}

mlx_texture_t	*which_texture(t_game *game, t_wall_side side, double rayDirX,
		double rayDirY)
{
	if (side == hor)
	{
		if (rayDirX > 0)
			return (game->etxt);
		return (game->wtxt);
	}
	else
	{
		if (rayDirY > 0)
			return (game->stxt);
		return (game->ntxt);
	}
}

// flipping line solevs a problem in N dir of unkown cause
// void	display_wall(t_game *game, int ray_id, double dist, t_wall_side side,
// 		double rayDirX, double rayDirY, double tileX, double tileY)
void	display_wall(t_game *game, int ray_id, t_ray_state s)
{
	double			z;
	mlx_texture_t	*txt;
	int				arr[2];

	txt = which_texture(game, s.side, s.raydirx, s.raydiry);
	if (!txt)
		return ;
	if (s.side == hor)
		z = s.posy + fabs(s.dist) * s.raydiry;
	else
		z = s.posx + fabs(s.dist) * s.raydirx;
	z -= (int)z;
	z = (int)(z * (double)txt->width);
	if (z < 0)
		z = 0;
	if (z >= (int)txt->width)
		z = (int)txt->width - 1;
	if (s.side == ver && s.raydiry > 0)
		z = (int)txt->width - z - 1;
	arr[0] = z;
	arr[1] = ray_id;
	putcol(arr, fabs(s.dist), game, txt);
}
