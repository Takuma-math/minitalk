/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:33:44 by takhayas          #+#    #+#             */
/*   Updated: 2025/05/03 18:03:03 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	*us;

	c = (unsigned char)c;
	us = (unsigned char *) s;
	i = 0;
	while (us[i])
	{
		if (us[i] == c)
			return ((char *)&us[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&us[i]);
	return (NULL);
}
