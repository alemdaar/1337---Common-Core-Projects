/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:51:37 by ahaddadi          #+#    #+#             */
/*   Updated: 2025/12/11 18:41:23 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
