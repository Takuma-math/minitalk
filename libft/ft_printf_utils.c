/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 16:49:18 by takhayas          #+#    #+#             */
/*   Updated: 2025/08/01 17:15:45 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;

	if (str == NULL)
		return (ft_putstr("(null)"));
	len = 0;
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}

int	ft_puthex(int n, const char	*hex_chars)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex(n / 16, hex_chars);
	len += ft_putchar(hex_chars[n % 16]);
	return (len);
}

int	ft_puthex_long(unsigned long long n, const char *hex_chars)
{
	int	len;

	len = 0;
	if (n >= 16)
		len += ft_puthex_long(n / 16, hex_chars);
	len += ft_putchar(hex_chars[n % 16]);
	return (len);
}

int	ft_putnbr(int n)
{
	int		len;
	char	c;

	len = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	c = n % 10 + '0';
	len += write(1, &c, 1);
	return (len);
}
