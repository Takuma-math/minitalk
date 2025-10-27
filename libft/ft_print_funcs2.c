/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_funcs2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:54:24 by takhayas          #+#    #+#             */
/*   Updated: 2025/08/01 17:15:35 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_integer(int *len, va_list args)
{
	int	num;

	num = va_arg(args, int);
	*len += ft_putnbr(num);
}

void	print_unsigned_decimal(int *len, va_list args)
{
	unsigned int	num;

	num = va_arg(args, unsigned int);
	*len += ft_putnbr_unsigned(num);
}

void	print_16_lower(int *len, va_list args)
{
	unsigned int	hex;

	hex = va_arg(args, unsigned int);
	if (hex == 0)
	{
		*len += ft_putstr("0");
		return ;
	}
	*len += ft_puthex_long(hex, "0123456789abcdef");
}

void	print_16_upper(int *len, va_list args)
{
	unsigned int	hex;

	hex = va_arg(args, unsigned int);
	if (hex == 0)
	{
		*len += ft_putstr("0");
		return ;
	}
	*len += ft_puthex_long(hex, "0123456789ABCDEF");
}

void	print_percent(int *len)
{
	*len += ft_putchar('%');
}
