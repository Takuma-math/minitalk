/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 14:05:46 by takhayas          #+#    #+#             */
/*   Updated: 2025/04/27 14:25:37 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_chr;

	s_chr = (unsigned char *) s;
	while (n--)
	{
		if (*s_chr == (unsigned char)c)
			return (s_chr);
		s_chr++;
	}
	return (NULL);
}

// int main() {
//     const char *str = "Hello, world!";
//     char c = 'o';

//     void *result = ft_memchr(str, c, 13);
//     if (result)
//         printf("Found'%c'at:%ld\n",c,(char *)result-(char *)str);
//     else
//         printf("Character '%c' not found\n", c);

//     return 0;
// }
