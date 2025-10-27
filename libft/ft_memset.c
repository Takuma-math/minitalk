/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:54:21 by takhayas          #+#    #+#             */
/*   Updated: 2025/05/03 18:11:30 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_char;
	size_t			i;

	s_char = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		s_char[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

// int main()
// {
// 	char s[20];
// 	ft_memset(s, 'a', 10);
// }
