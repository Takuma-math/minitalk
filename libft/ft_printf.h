/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/01 13:53:08 by takhayas          #+#    #+#             */
/*   Updated: 2025/08/01 16:32:14 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		ft_puthex(int n, const char *hex_chars);
int		ft_puthex_long(unsigned long long n, const char *hex_chars);
void	print_char(int *len, va_list args);
void	print_str(int *len, va_list args);
void	print_pointer(int *len, va_list args);
void	print_decimal(int *len, va_list args);
void	print_integer(int *len, va_list args);
void	print_unsigned_decimal(int *len, va_list args);
void	print_16_lower(int *len, va_list args);
void	print_16_upper(int *len, va_list args);
void	print_percent(int *len);
void	parse_format(int *len, const char *format, va_list args);

#endif
