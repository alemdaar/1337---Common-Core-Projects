/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 16:16:08 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/16 13:16:53 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H
# include "../../lib/gnl/get_next_line.h"
# include "../../lib/libft/libft.h"
# include "../../lib/mlx42/include/MLX42/MLX42.h"
# include "parse/parse_bonus.h"
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

// Err msgs
# define SUCCESSFUL 0
# define FAILED 1
# define X 0
# define Y 1
# define D 2
# define A 3
# define PDX 4
# define PDY 5
// Screen dimensions
# define WINDOW_W 2560
# define WINDOW_H 1356
// Colors
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLACK 0x000000FF

# define SQUARE_LEN 35
# define PLAYER_LEN 15
# define CENTER_RULE 17
# define MAP2D_LEN 5
# define FOV 60
# define MOVE_SPEED 2
# define ROTATION_SPEED 3
# define MOUSE_SENSITIVITY 0.2
# define COVER_SQ 10
# define BT 10

// Parsing stuff
# define MAX_MAP_SZ 500
# define CEN_2_SIDE 87
# define CIRCLE_RADIUS 10
# define MAX_SQUARES_2D 7
# define MAX_SQUARES_2D 7

# define WALL 49
# define EMPTY 48
# define FORWARD 1
# define BACKWARD 2
# define LEFT 3
# define RIGHT 4

// hands
# define R_HAND_UP 800
# define R_HAND_DOWN 850
# define L_HAND_UP 1100
# define L_HAND_DOWN 1120

# define FTLI "Failed to load PNG: "
# define F3TI "Failed to transfer to PNG: "

typedef struct s_cord
{
	double			x;
	double			y;
}					t_cord;

typedef struct s_player
{
	int				xy_tile[2];
	double			xy_pixel[2];
	double			angle_x;
	double			pdx;
	double			pdy;
	double			mouse_last_x;
	double			mouse_last_y;
	double			pitch;
}					t_player;

typedef struct s_ptcl
{
	double		col_h;
	double		step;
	int			start_y;
	double		tex_pos;
	int			end_y;
	int			ty;
	int			pixel_idx;
	uint32_t	color;

}				t_ptcl;

typedef struct s_map
{
	bool			success;
	char			errmsg[1024];
	unsigned int	fcolor;
	unsigned int	ccolor;
	char			**map;
}					t_map;

typedef struct s_game
{
	double			rays[WINDOW_W][6];
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_map			map;
	t_player		player;
	mlx_texture_t	*ntxt;
	mlx_texture_t	*stxt;
	mlx_texture_t	*wtxt;
	mlx_texture_t	*etxt;
	mlx_texture_t	*txt_r_hand;
	mlx_texture_t	*txt_l_hand;
	mlx_image_t		*img_r_hand;
	mlx_image_t		*img_l_hand;
	mlx_texture_t	*txt_bomb;
	mlx_image_t		*img_bomb;
	int				door;
	int				left_hand;
	int				left_dir;
	int				hand_pos;
}					t_game;

typedef enum side
{
	hor,
	ver,
}					t_wall_side;

typedef struct s_ray_state
{
	double			raydirx;
	double			raydiry;
	double			posx;
	double			posy;
	double			deltadistx;
	double			deltadisty;
	double			sidedistx;
	double			sidedisty;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	t_wall_side		side;
	double			dist;
	double			ray_angle;
	int				max_steps;
}					t_ray_state;

typedef struct s_draw_2dplayer
{
	uint32_t		color;
	double			angle_x;
	t_cord			tip;
	double			left_angle;
	double			right_angle;
	t_cord			left;
	t_cord			right;
	t_cord			p;
	double			b1;
	double			b2;
	double			b3;
	int				x;
	int				y;
}					t_d_2dp;

typedef struct s_draw_border
{
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	int				t;
	int				x;
	int				y;
}					t_draw_border;

typedef struct s_indexes
{
	int				x;
	int				y;
	int				i;
}					t_indexes;

// hooks
void			handle_input(void *param1);

// RAYS
int				cast_rays(t_game *game);
void			init_ray_state(t_game *game, int ray_id, t_ray_state *s);
int				draw_2dmap(t_game *game);
void			mouse_move(double xpos, double ypos, void *param);

// ROTATION
int				right_rotate(t_player *player);
int				left_rotate(t_player *player);
int				up_rotate(t_player *player);
int				down_rotate(t_player *player);

// MOVEMENT
int				go_forward(t_game *game, t_player *player, t_map *map);
int				go_back(t_game *game, t_player *player, t_map *map);
int				go_left(t_game *game, t_player *player, t_map *map);
int				go_right(t_game *game, t_player *player, t_map *map);

// GFX
u_int32_t		getrgba(uint8_t *arr, int i);
mlx_texture_t	*which_texture(t_game *game, t_wall_side side,
					double rayDirX, double rayDirY);
void			display_wall(t_game *game, int ray_id, t_ray_state s);
void			putcol(int arr[], double distance, t_game *game,
					mlx_texture_t *txt);

// utils
int				get_sqr(double pixel_cord);
double			get_pixel(int square_cord);
bool			is_wall(t_game *game, int mapY, int mapX);
double			signf(t_cord xy1, t_cord xy2, t_cord xy3);
int				prepare_color(t_map *map, double x, double y,
					uint32_t *color);
void			not_wall_x_f(t_game *game, t_map *map, t_cord *cord);
void			there_wall_x_f(t_game *game, t_map *map, t_cord *cord);
void			not_wall_x_b(t_game *game, t_map *map, t_cord *cord);
void			there_wall_x_b(t_game *game, t_map *map, t_cord *cord);
void			not_wall_x_l(t_game *game, t_map *map, t_cord *cord);
void			there_wall_x_l(t_game *game, t_map *map, t_cord *cord);
void			not_wall_x_r(t_game *game, t_map *map, t_cord *cord);
void			there_wall_x_r(t_game *game, t_map *map, t_cord *cord);
t_d_2dp			init_draw_player2d_vars(int cx, int cy, double angle_deg);
void			draw_player2d_pixel(mlx_image_t *img, t_d_2dp *v);
void			free_textures(t_game *game);
void			draw_right_hand(t_game *game);
void			draw_left_hand(t_game *game);
void			draw_right_hand(t_game *game);
void			draw_left_hand(t_game *game);
void			handle_doors(mlx_key_data_t key_data, void *param);
#endif
