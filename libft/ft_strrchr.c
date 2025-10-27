/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:49:53 by takhayas          #+#    #+#             */
/*   Updated: 2025/05/03 18:05:01 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	*us;
	unsigned char	*us_out;

	c = (unsigned char)c;
	us = (unsigned char *) s;
	i = 0;
	us_out = NULL;
	while (us[i])
	{
		if (us[i] == c)
			us_out = &us[i];
		i++;
	}
	if (c == '\0')
		us_out = &us[i];
	return ((char *) us_out);
}
// #include <stdio.h>

// int main() {
//     const char *str = "Hello, world!";
//     char c = 'o';

//     char *result = strrchr(str, c);
//     if (result)
//         printf("Found character '%c' at position: %ld\n", c, result - str);
//     else
//         printf("Character '%c' not found\n", c);

//     result = strrchr(str, '\0');
//     if (result)
//         printf("Found character '\\0' at position: %ld\n", result - str);

//     return 0;
// }
