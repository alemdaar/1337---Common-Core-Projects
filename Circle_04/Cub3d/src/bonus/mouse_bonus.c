/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:03:11 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/16 13:14:04 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

// void	mouse_move(double xpos, double ypos, void *param)
// {
// 	t_game		*g;
// 	t_player	*player;
// 	double		delta;

// 	(void)ypos;
// 	g = param;
// 	player = &g->player;
// 	delta = xpos - player->mouse_last_x;
// 	player->angle_x -= delta * MOUSE_SENSITIVITY;
// 	player->mouse_last_x = xpos;
// 	player->pdx = cos(player->angle_x * M_PI / 180.0);
// 	player->pdy = -sin(player->angle_x * M_PI / 180.0);
// }

void mouse_move(double xpos, double ypos, void *param)
{
    t_game     *g;
    t_player   *player;
    double      dx;
    double      dy;

    g = param;
    player = &g->player;

    // Horizontal rotation (yaw)
    dx = xpos - player->mouse_last_x;
    player->angle_x -= dx * MOUSE_SENSITIVITY;

    // Vertical look (pitch)
    dy = ypos - player->mouse_last_y;
    player->pitch -= dy * 3; // sensitivity

    // Clamp pitch
    if (player->pitch > WINDOW_H / 2)
        player->pitch = WINDOW_H / 2;
    if (player->pitch < -WINDOW_H / 2)
        player->pitch = -WINDOW_H / 2;

    player->mouse_last_x = xpos;
    player->mouse_last_y = ypos;

    player->pdx = cos(player->angle_x * M_PI / 180.0);
    player->pdy = -sin(player->angle_x * M_PI / 180.0);
	return ;
}
