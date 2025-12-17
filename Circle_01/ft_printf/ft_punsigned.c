/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punsigned.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:47:14 by oelhasso          #+#    #+#             */
/*   Updated: 2024/11/23 19:55:18 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_punsigned(unsigned int n)
{
	unsigned int	nb;
	int				print;

	print = 0;
	nb = n;
	if (nb > 9)
	{
		print += ft_punsigned(nb / 10);
		print += ft_punsigned(nb % 10);
	}
	else
		print += ft_pchar(nb + 48);
	return (print);
}
