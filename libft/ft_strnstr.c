/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:39:24 by takhayas          #+#    #+#             */
/*   Updated: 2025/04/27 15:20:48 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

// #include <string.h>

// int main() {
//     const char *big = "Hello, world!";
//     const char *little = "world";
//     size_t len = 12;  // 検索範囲を 12 バイトに制限

//     char *result = ft_strnstr(big, little, len);
//     if (result)
//         printf("Found '%s' at position: %ld\n", little, result - big);
//     else
//         printf("'%s' not found\n", little);

//     return 0;
// }
