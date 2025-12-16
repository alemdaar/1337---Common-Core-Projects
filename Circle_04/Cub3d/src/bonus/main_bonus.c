/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:51:37 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/16 13:16:41 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

bool	init(t_game *game)
{
	game->mlx = mlx_init(WINDOW_W, WINDOW_H, "CUB3D", false);
	if (!game->mlx)
	{
		free_textures(game);
		free2d(game->map.map);
		free(game);
		return (false);
	}
	return (true);
}

static bool	init_img(t_game *game)
{
	game->img = mlx_new_image(game->mlx, WINDOW_W, WINDOW_H);
	if (!game->img || mlx_image_to_window(game->mlx, game->img, 0, 0) < 0)
	{
		free_textures(game);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		free2d(game->map.map);
		free(game);
		return (false);
	}
	return (true);
}

void	free_all(t_game *game)
{
	free_textures(game);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	free2d(game->map.map);
	if (game)
		free(game);
	exit(1);
}

static int	last_set(t_game *game)
{
	game->player.mouse_last_x = WINDOW_W / 2.0;
	game->player.mouse_last_y = WINDOW_H / 2.0;
	game->hand_pos = R_HAND_UP;
	game->left_hand = L_HAND_UP;
	game->left_dir = 1;
	game->player.pitch = 0;
	game->player.pitch = 0;
	game->txt_r_hand = mlx_load_png("textures/backrooms/hand4.png");
	if (!game->txt_r_hand)
		return (free_all(game), 1);
	game->txt_l_hand = mlx_load_png("textures/backrooms/hand3.png");
	if (!game->txt_l_hand)
		return (free_all(game), 1);
	game->txt_bomb = mlx_load_png("textures/backrooms/bomb.png");
	if (!game->txt_bomb)
		return (free_all(game), 1);
	game->img_bomb = mlx_texture_to_image(game->mlx, game->txt_bomb);
	if (!game->img_bomb)
		return (free_all(game), 1);
	game->img_r_hand = mlx_texture_to_image(game->mlx, game->txt_r_hand);
	if (!game->img_r_hand)
		return (free_all(game), 1);
	game->img_l_hand = mlx_texture_to_image(game->mlx, game->txt_l_hand);
	if (!game->img_l_hand)
		return (free_all(game), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (puts("Usage: ./cub3d <path/to/map.cub>"), 1);
	game = setup(av[1]);
	if (!game)
		return (2);
	if (!init(game) || !init_img(game))
		return (3);
	last_set(game);
	cast_rays(game);
	draw_2dmap(game);
	mlx_image_to_window(game->mlx, game->img_l_hand, 820, L_HAND_UP);
	mlx_image_to_window(game->mlx, game->img_bomb, 860, L_HAND_UP + 20);
	mlx_image_to_window(game->mlx, game->img_r_hand, 1050, R_HAND_UP);
	mlx_set_cursor_mode(game->mlx, MLX_MOUSE_HIDDEN);
	mlx_cursor_hook(game->mlx, mouse_move, game);
	mlx_key_hook(game->mlx, handle_doors, game);
	mlx_loop_hook(game->mlx, handle_input, game);
	mlx_loop(game->mlx);
	free_textures(game);
	mlx_terminate(game->mlx);
	free2d(game->map.map);
	free(game);
}
