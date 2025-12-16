/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:51:37 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/12 15:41:00 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
	cast_rays(game);
	mlx_loop_hook(game->mlx, handle_input, game);
	mlx_loop(game->mlx);
	free_textures(game);
	mlx_terminate(game->mlx);
	free2d(game->map.map);
	free(game);
}
