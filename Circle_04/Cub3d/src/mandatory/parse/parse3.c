/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:29:29 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/12 11:27:55 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	init_game_textures(t_game *game)
{
	game->ntxt = NULL;
	game->stxt = NULL;
	game->wtxt = NULL;
	game->etxt = NULL;
}

void	free_textures(t_game *game)
{
	if (game->ntxt)
		mlx_delete_texture(game->ntxt);
	if (game->stxt)
		mlx_delete_texture(game->stxt);
	if (game->wtxt)
		mlx_delete_texture(game->wtxt);
	if (game->etxt)
		mlx_delete_texture(game->etxt);
}

static t_game	*setup_error(t_game *game, int fd)
{
	ft_putstr_fd(game->map.errmsg, 2);
	free_textures(game);
	free2d(game->map.map);
	close(fd);
	free(game);
	return (NULL);
}

t_game	*setup(char *filename)
{
	int		fd;
	t_game	*game;

	if (ft_strlen(filename) < 4 || strcmp(filename + ft_strlen(filename) - 4,
			".cub") != 0)
		return (ft_putstr_fd("Map name doesn't end with .cub\n", 2), NULL);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Can't open map file\n", 2), NULL);
	game = malloc(sizeof(t_game));
	if (!game)
		return (close(fd), ft_putstr_fd("Can't open map file\n", 2), NULL);
	game->map.success = true;
	init_game_textures(game);
	parseattr(fd, game);
	setmap(game, fd);
	find_player(&game->map, &game->player);
	check_textures(game);
	mapcheck(game->map.map, &game->player, game);
	if (game->map.success == false)
		return (setup_error(game, fd));
	close(fd);
	return (game);
}
