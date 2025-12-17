/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:41:52 by oelhasso          #+#    #+#             */
/*   Updated: 2024/11/23 20:37:23 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_phex(unsigned long nb, const char c)
{
	int		print;
	char	*lower_hex;
	char	*upper_hex;

	print = 0;
	lower_hex = "0123456789abcdef";
	upper_hex = "0123456789ABCDEF";
	if (nb >= 16)
	{
		print += ft_phex((nb / 16), c);
		print += ft_phex((nb % 16), c);
	}
	else
	{
		if (c == 'x' || c == 'p')
			print += ft_pchar(lower_hex[nb]);
		else if (c == 'X')
			print += ft_pchar(upper_hex[nb]);
	}
	return (print);
}
