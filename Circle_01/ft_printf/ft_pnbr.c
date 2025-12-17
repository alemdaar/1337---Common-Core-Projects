/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:44:16 by oelhasso          #+#    #+#             */
/*   Updated: 2024/11/26 16:04:50 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	len_count(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len += 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_pnbr(int n)
{
	int	nb;

	nb = n;
	if (nb == -2147483648)
		return (ft_pstr("-2147483648"));
	else if (nb < 0)
	{
		ft_pchar('-');
		nb *= -1;
		ft_pnbr(nb);
	}
	else if (nb > 9)
	{
		ft_pnbr(nb / 10);
		ft_pchar((nb % 10) + 48);
	}
	else
		ft_pchar(nb + 48);
	return (len_count(n));
}
