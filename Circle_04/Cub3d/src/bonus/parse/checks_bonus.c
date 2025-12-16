/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:45:00 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/15 10:21:06 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_bonus.h"

void	check_textures(t_game *game)
{
	mlx_texture_t	*arr[4];
	int				i;

	arr[0] = game->ntxt;
	arr[1] = game->etxt;
	arr[2] = game->stxt;
	arr[3] = game->wtxt;
	if (game->map.success == false)
		return ;
	i = 0;
	while (i < 4)
	{
		if (arr[i] == NULL)
			return (seterr("Wasn't able to load a texture\n", &game->map));
		i++;
	}
}

// WARN mutating map here
//@note	return	false->bad
// ft_strlcat(game->map.errmsg, ft_itoa(y), 1024);
// ft_strlcat(game->map.errmsg, ":", 1024);
// ft_strlcat(game->map.errmsg, ft_itoa(x), 1024);
bool	checkmapchars(t_game *game, char **map)
{
	char	c;
	int		x;
	int		y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			c = map[y][x];
			if (c != '0' && c != ' ' && c != 'N' && c != 'S' && c != 'E'
				&& c != 'W' && c != '1' && c != 'D')
			{
				seterr("Bad Map char\n", &game->map);
				return (false);
			}
			else if (c == ' ')
				map[y][x] = '0';
			x++;
		}
		y++;
	}
	return (true);
}

//	@return	true -> on error
// idea is we should never reach the map extremes unless it's a wall
int	dfs(char **map, int x, int y, int rows_count)
{
	int	row_len;
	int	flag;

	if (y < 0 || y >= rows_count)
		return (1);
	row_len = ft_strlen(map[y]);
	if (x < 0 || x >= row_len)
		return (1);
	if (map[y][x] == '1')
		return (0);
	map[y][x] = '1';
	flag = 0;
	flag += dfs(map, x + 1, y, rows_count);
	flag += dfs(map, x - 1, y, rows_count);
	flag += dfs(map, x, y + 1, rows_count);
	flag += dfs(map, x, y - 1, rows_count);
	return (flag);
}

// @note	return false = bad map
void	mapcheck(char **map, t_player *player, t_game *game)
{
	char	**newmap;
	int		y;
	int		result;

	if (game->map.success == false || !map)
		return (seterr("No map\n", &game->map));
	if (checkmapchars(game, map) == false)
		return ;
	newmap = malloc(sizeof(char *) * MAX_MAP_SZ);
	if (!newmap)
		return (seterr("Memory shortage\n", &game->map));
	y = 0;
	while (map[y] && y < MAX_MAP_SZ - 1)
	{
		newmap[y] = ft_strdup(map[y]);
		y++;
	}
	newmap[y] = NULL;
	map[player->xy_tile[Y]][player->xy_tile[X]] = '0';
	result = dfs(newmap, player->xy_tile[X], player->xy_tile[Y], y);
	if (result != 0)
		seterr("Bad Map\n", &game->map);
	free2d(newmap);
}
