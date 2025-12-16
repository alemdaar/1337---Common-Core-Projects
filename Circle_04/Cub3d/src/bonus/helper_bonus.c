/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:51:37 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/14 12:37:56 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

int	get_sqr(double pixel_cord)
{
	return ((int)pixel_cord / SQUARE_LEN);
}

double	get_pixel(int square_cord)
{
	return ((double)square_cord * (double)SQUARE_LEN);
}

double	signf(t_cord xy1, t_cord xy2, t_cord xy3)
{
	double	r;

	r = (xy1.x - xy3.x) * (xy2.y - xy3.y)
		- (xy2.x - xy3.x) * (xy1.y - xy3.y);
	return (r);
}

void	init_color(uint32_t *bl, uint32_t *gr, uint32_t *g, uint32_t *b)
{
	*gr = 0x00FF00FF;
	*bl = 0x000000FF;
	*g = 0x808080FF;
	*b = 0x0000FFFF;
	return ;
}

int	prepare_color(t_map *map, double x, double y, uint32_t *color)
{
	uint32_t	green;
	uint32_t	black;
	uint32_t	grey;
	uint32_t	blue;
	char		flag;

	init_color (&black, &green, &grey, &blue);
	flag = 'Z';
	if (y >= 0 && x >= 0)
	{
		if (map->map[get_sqr(y)])
		{
			if (map->map[get_sqr(y)][get_sqr(x)])
				flag = map->map[get_sqr(y)][get_sqr(x)];
		}
	}
	if (flag == 'Z')
		*color = black;
	else if (flag == '1')
		*color = grey;
	else if (flag == 'D')
		*color = blue;
	else
		*color = green;
	return (0);
}
