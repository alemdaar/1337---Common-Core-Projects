/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:01:32 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/15 12:02:19 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

t_d_2dp	init_draw_player2d_vars(int cx, int cy, double angle_deg)
{
	t_d_2dp	v;

	v.color = 0xFF0000FF;
	v.angle_x = angle_deg * (M_PI / 180.0f);
	v.tip.x = cx + cosf(v.angle_x) * CIRCLE_RADIUS;
	v.tip.y = cy - sinf(v.angle_x) * CIRCLE_RADIUS;
	v.left_angle = v.angle_x + M_PI * 0.7f;
	v.right_angle = v.angle_x - M_PI * 0.7f;
	v.left.x = cx + cosf(v.left_angle) * (CIRCLE_RADIUS * 0.5f);
	v.left.y = cy - sinf(v.left_angle) * (CIRCLE_RADIUS * 0.5f);
	v.right.x = cx + cosf(v.right_angle) * (CIRCLE_RADIUS * 0.5f);
	v.right.y = cy - sinf(v.right_angle) * (CIRCLE_RADIUS * 0.5f);
	v.y = -CIRCLE_RADIUS;
	return (v);
}

void	draw_player2d_pixel(mlx_image_t *img, t_d_2dp *v)
{
	v->b1 = signf(v->p, v->tip, v->left);
	v->b2 = signf(v->p, v->left, v->right);
	v->b3 = signf(v->p, v->right, v->tip);
	if ((v->b1 >= 0 && v->b2 >= 0 && v->b3 >= 0)
		|| (v->b1 <= 0 && v->b2 <= 0 && v->b3 <= 0))
	{
		mlx_put_pixel(img, v->p.x + BT, v->p.y + BT, v->color);
	}
	v->x++;
	return ;
}
