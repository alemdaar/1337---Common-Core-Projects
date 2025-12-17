/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:44:51 by oelhasso          #+#    #+#             */
/*   Updated: 2024/11/25 13:35:43 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, const char c)
{
	int	print;

	print = 0;
	if (c == 'c')
		print += ft_pchar(va_arg(args, int));
	else if (c == 's')
		print += ft_pstr(va_arg(args, char *));
	else if (c == 'p')
		print += ft_pptr(va_arg(args, unsigned long), c);
	else if (c == 'd' || c == 'i')
		print += ft_pnbr(va_arg(args, int));
	else if (c == 'u')
		print += ft_punsigned(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		print += ft_phex(va_arg(args, unsigned int), c);
	else
		print += ft_pchar(c);
	return (print);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print;

	i = 0;
	print = 0;
	va_start(args, str);
	while (str[i]) 
	{
		if (str[i] == '%')
		{
			if (str[i + 1])
				print += ft_format(args, str[++i]);
		}
		else
			print += ft_pchar(str[i]);
		i++;
	}
	va_end(args);
	return (print);
}
