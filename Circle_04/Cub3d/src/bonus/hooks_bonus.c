/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:06:49 by oelhasso          #+#    #+#             */
/*   Updated: 2025/12/16 13:17:35 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

void	handle_input(void *param1)
{
	t_game	*game;

	game = (t_game *)param1;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		right_rotate(&game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
		left_rotate(&game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
		up_rotate(&game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
		down_rotate(&game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
		go_forward(game, &game->player, &game->map);
	if (mlx_is_key_down(game->mlx, MLX_KEY_S))
		go_back(game, &game->player, &game->map);
	if (mlx_is_key_down(game->mlx, MLX_KEY_A))
		go_left(game, &game->player, &game->map);
	if (mlx_is_key_down(game->mlx, MLX_KEY_D))
		go_right(game, &game->player, &game->map);
	cast_rays(game);
	draw_2dmap(game);
	draw_right_hand(game);
	draw_left_hand(game);
	return ;
}
