/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 18:29:29 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/11 18:32:40 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

static void	setmap2(t_map *map, int fd)
{
	int		i;
	char	*line;

	line = get_real_nl(fd);
	if (!line)
		return (seterr("No map found", map));
	i = 0;
	while (line && has_content(line))
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		if (ft_strlen(line) > MAX_MAP_SZ || i >= MAX_MAP_SZ)
		{
			seterr("Map too big", map);
			free(line);
			return ;
		}
		map->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	map->map[i] = NULL;
}

void	setmap(t_game *game, int fd)
{
	t_map	*map;

	if (!game || !game->map.success)
		return ;
	map = &game->map;
	map->map = ft_calloc(MAX_MAP_SZ + 1, sizeof(char *));
	if (!map->map)
		return (seterr("Not enough memory", map));
	map->map[0] = NULL;
	setmap2(map, fd);
}

bool	parseattr2(char *line, int *done, t_game *game)
{
	char	**keyval;

	keyval = ft_split(line, ' ');
	free(line);
	if (len2d(keyval) != 2 || ft_strlen(keyval[0]) > 2)
	{
		free2d(keyval);
		seterr("Can't open map file\n", &game->map);
		return (1);
	}
	*done += 1;
	if (is_texture(keyval[0]))
		settxtr(game, keyval[0], keyval[1]);
	else if (is_color(keyval[0]))
		setcolor(game, keyval[0], keyval[1]);
	else
		done--;
	free2d(keyval);
	if (*done == 6 || game->map.success == false)
		return (1);
	return (0);
}

void	parseattr(int fd, t_game *game)
{
	int		done;
	char	*line;

	done = 0;
	line = get_real_nl(fd);
	while (line)
	{
		if (parseattr2(line, &done, game))
			break ;
		line = get_real_nl(fd);
	}
	if (done != 6)
		return (seterr("Bad cub file attributes", &game->map));
}
