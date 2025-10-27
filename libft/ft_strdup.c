/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 15:54:36 by takhayas          #+#    #+#             */
/*   Updated: 2025/05/03 18:32:47 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	len_s;

	len_s = 0;
	while (s[len_s])
		len_s++;
	ret = (char *) malloc(sizeof(char) * (len_s + 1));
	if (!ret)
		return (NULL);
	len_s = 0;
	while (s[len_s] != '\0')
	{
		ret[len_s] = s[len_s];
		len_s++;
	}
	ret[len_s] = '\0';
	return (ret);
}
