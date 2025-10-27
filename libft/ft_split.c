/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takhayas <hayatakucat@icloud.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 12:23:55 by takhayas          #+#    #+#             */
/*   Updated: 2025/05/10 12:53:27 by takhayas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_num(char const *s, char c)
{
	int	i;
	int	num;
	int	in_word;

	i = 0;
	num = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			num++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (num);
}

static void	ft_free_all(char **words, int i)
{
	while (--i >= 0)
		free(words[i]);
	free(words);
}

static int	ft_next_word_store(char const *s, char c, char **words, int *i)
{
	while (s[i[0]] == c)
		i[0]++;
	i[1] = i[0];
	while (s[i[1]] && s[i[1]] != c)
		i[1]++;
	if (i[1] > i[0])
	{
		words[i[2]] = ft_substr(s, i[0], i[1] - i[0]);
		if (!words[i[2]])
		{
			ft_free_all(words, i[2]);
			return (0);
		}
		i[2]++;
	}
	i[0] = i[1];
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		i[3];

	if (!s)
		return (NULL);
	words = (char **)malloc(sizeof(char *) * (ft_word_num(s, c) + 1));
	if (!words)
		return (NULL);
	i[0] = 0;
	i[2] = 0;
	while (s[i[0]])
		if (!ft_next_word_store(s, c, words, i))
			return (NULL);
	words[i[2]] = NULL;
	return (words);
}
