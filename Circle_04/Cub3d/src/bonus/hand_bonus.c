/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hand_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:01:28 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/15 10:21:17 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	draw_right_hand(t_game *game)
{
	if (game->door && game->hand_pos < R_HAND_DOWN)
		game->hand_pos += 30;
	else if (!game->door && game->hand_pos > R_HAND_UP)
		game->hand_pos -= 30;
	game->img_r_hand->instances[0].y = game->hand_pos;
	return ;
}

void	draw_left_hand(t_game *game)
{
	if (game->left_dir && game->left_hand < L_HAND_DOWN)
		game->left_hand += 1;
	else if (!game->left_dir && game->left_hand > L_HAND_UP)
		game->left_hand -= 1;
	else
		game->left_dir = 1 - game->left_dir;
	game->img_l_hand->instances[0].y = game->left_hand;
	game->img_bomb->instances[0].y = game->left_hand + 20;
	return ;
}

void	handle_doors(mlx_key_data_t key_data, void *param)
{
	t_game		*game;
	t_player	*player;
	int			x;
	int			y;

	game = (t_game *)param;
	player = &game->player;
	if (key_data.key == MLX_KEY_SPACE && key_data.action == MLX_PRESS)
	{
		x = player->xy_tile[X];
		y = player->xy_tile[Y];
		if (game->map.map[y][x] != 'D')
		{
			game->door = 1 - game->door;
		}
	}
	return ;
}
