/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <elhassounioussama2@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:47:53 by oelhasso          #+#    #+#             */
/*   Updated: 2024/11/23 20:37:27 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_pchar(char c);
int	ft_phex(unsigned long nb, const char c);
int	ft_pnbr(int nb);
int	ft_pptr(unsigned long address, const char c);
int	ft_pstr(char *str);
int	ft_punsigned(unsigned int nb);

#endif     