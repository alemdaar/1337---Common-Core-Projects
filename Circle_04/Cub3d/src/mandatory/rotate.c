/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:43:18 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/01 15:43:32 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	right_rotate(t_player *player)
{
	player->angle -= ROTATION_SPEED;
	if (player->angle < 0)
		player->angle += 360;
	player->pdx = cos(player->angle * M_PI / 180.0);
	player->pdy = -sin(player->angle * M_PI / 180.0);
	return (0);
}

int	left_rotate(t_player *player)
{
	player->angle += ROTATION_SPEED;
	if (player->angle >= 360)
		player->angle -= 360;
	player->pdx = cos(player->angle * M_PI / 180.0);
	player->pdy = -sin(player->angle * M_PI / 180.0);
	return (0);
}
