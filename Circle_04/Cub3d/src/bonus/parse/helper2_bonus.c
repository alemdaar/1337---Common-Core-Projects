/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:44:03 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/11 18:37:05 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main_bonus.h"

bool	is_player(char c)
{
	return (c == 'N' || c == 'W' || c == 'S' || c == 'E');
}

bool	is_texture(char *key)
{
	if (!ft_strcmp(key, "NO") || !ft_strcmp(key, "SO") || !ft_strcmp(key, "EA")
		|| !ft_strcmp(key, "WE"))
		return (true);
	return (false);
}

bool	has_content(char *line)
{
	long unsigned	i;

	if (!line || ft_strlen(line) < 1)
		return (false);
	i = 0;
	while (i < ft_strlen(line))
	{
		if (ft_isalnum(line[i]))
			return (true);
		i++;
	}
	return (false);
}

char	*get_real_nl(int fd)
{
	char	*line;
	char	*nl;

	line = get_next_line(fd);
	while (1)
	{
		if (!line)
			return (NULL);
		if (has_content(line) == false)
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		nl = ft_strchr(line, '\n');
		if (nl)
			*nl = 0;
		return (line);
	}
}
