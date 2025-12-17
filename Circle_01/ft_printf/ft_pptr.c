/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:44:28 by oelhasso          #+#    #+#             */
/*   Updated: 2024/11/23 17:35:54 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pptr(unsigned long address, const char c)
{
	int	print;

	print = 0;
	print += write(1, "0x", 2);
	print += ft_phex(address, c);
	return (print);
}
