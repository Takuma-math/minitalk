/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:27:51 by takhayas          #+#    #+#             */
/*   Updated: 2025/08/03 16:54:35 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_format(int *len, const char *format, va_list args)
{
	if (*format == 'c')
		print_char(len, args);
	if (*format == 's')
		print_str(len, args);
	if (*format == 'p')
		print_pointer(len, args);
	if (*format == 'd')
		print_decimal(len, args);
	if (*format == 'i')
		print_integer(len, args);
	if (*format == 'u')
		print_unsigned_decimal(len, args);
	if (*format == 'x')
		print_16_lower(len, args);
	if (*format == 'X')
		print_16_upper(len, args);
	if (*format == '%')
		print_percent(len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			parse_format(&len, format, args);
		}
		else
			len += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}
