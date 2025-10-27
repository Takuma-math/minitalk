/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_funcs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:50:33 by takhayas          #+#    #+#             */
/*   Updated: 2025/08/01 17:15:17 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(int *len, va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	*len += ft_putchar(c);
}

void	print_str(int *len, va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	*len += ft_putstr(str);
}

void	print_pointer(int *len, va_list args)
{
	unsigned long long	p;

	p = va_arg(args, unsigned long long);
	if (p == 0)
	{
		*len += ft_putstr("(nil)");
		return ;
	}
	*len += ft_putstr("0x");
	*len += ft_puthex_long(p, "0123456789abcdef");
}

void	print_decimal(int *len, va_list args)
{
	int	num;

	num = va_arg(args, int);
	*len += ft_putnbr(num);
}
