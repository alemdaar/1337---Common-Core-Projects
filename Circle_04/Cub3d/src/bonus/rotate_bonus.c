/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:43:18 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/16 13:21:18 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	right_rotate(t_player *player)
{
	player->angle_x -= ROTATION_SPEED;
	if (player->angle_x < 0)
		player->angle_x += 360;
	player->pdx = cos(player->angle_x * M_PI / 180.0);
	player->pdy = -sin(player->angle_x * M_PI / 180.0);
	return (0);
}

int	left_rotate(t_player *player)
{
	player->angle_x += ROTATION_SPEED;
	if (player->angle_x >= 360)
		player->angle_x -= 360;
	player->pdx = cos(player->angle_x * M_PI / 180.0);
	player->pdy = -sin(player->angle_x * M_PI / 180.0);
	return (0);
}

int up_rotate(t_player *player)
{
    player->pitch += ROTATION_SPEED * 5;
    if (player->pitch > WINDOW_H / 2)
        player->pitch = WINDOW_H / 2;
    if (player->pitch < -WINDOW_H / 2)
        player->pitch = -WINDOW_H / 2;
	return (0);
}
int down_rotate(t_player *player)
{
    player->pitch -= ROTATION_SPEED * 5;
    if (player->pitch > WINDOW_H / 2)
        player->pitch = WINDOW_H / 2;
    if (player->pitch < -WINDOW_H / 2)
        player->pitch = -WINDOW_H / 2;
	return (0);
}
