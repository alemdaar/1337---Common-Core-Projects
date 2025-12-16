/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 19:38:29 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/14 13:36:11 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <string.h>

typedef struct s_game	t_game;
typedef struct s_player	t_player;
typedef struct s_map	t_map;

// helpers
void					free2d(char **split);
int						len2d(char **arr);
bool					has_content(char *line);
bool					is_color(char *line);
bool					is_player(char c);
bool					is_texture(char *key);
char					*get_real_nl(int fd);
void					parseattr(int fd, t_game *game);
void					setmap(t_game *game, int fd);

// setters
void					seterr(char *msg, t_map *map);
void					settxtr(t_game *game, char *key, char *val);
void					setcolor(t_game *game, char *key, char *val);

// funcs
void					find_player(t_map *map, t_player *player);

// checks
void					check_textures(t_game *game);
void					mapcheck(char **map, t_player *player, t_game *game);
bool					check_clr(char *line, t_game *game);

// EXPORT
t_game					*setup(char *filename);

#endif
