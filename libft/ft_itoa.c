/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 11:45:07 by takhayas          #+#    #+#             */
/*   Updated: 2025/05/04 12:20:18 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int n)
{
	long	num;
	int		digit;

	num = (long) n;
	digit = 1;
	if (num < 0)
	{
		num *= -1;
		digit++;
	}
	while (num > 9)
	{
		num = num / 10;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char	*n_str;
	long	num;
	size_t	i;
	int		digit;

	digit = ft_count_digit(n);
	num = (long) n;
	n_str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!n_str)
		return (NULL);
	n_str[digit] = '\0';
	if (num < 0)
	{
		num *= -1;
		n_str[0] = '-';
	}
	i = digit - 1;
	while (num > 9)
	{
		n_str[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	n_str[i] = num % 10 + '0';
	return (n_str);
}
