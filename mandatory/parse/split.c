/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:37:16 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/03 16:03:58 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	size_t			l;

	if (!s)
		return (NULL);
	l = (size_t)ft_strlen((char *)s + start);
	if (l < len)
	len = l;
	i = 0;
	if (start >= (size_t)ft_strlen((char *)s) || len == 0)
		return (ft_strdup(""));
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	if (len > (size_t)ft_strlen((char *)s))
		len = (size_t)ft_strlen((char *)s);
	while (i < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

static size_t	word_cnt(const char *s, char del)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != del)
		{
			count++;
			while (s[i] != '\0' && s[i] != del)
			i++;
		}
		else
		i++;
	}
	return (count);
}

static void	*free_split(char **split, int i)
{
	while (split[i])
	{
		free(split[i]);
		i--;
	}
	free(split);
	split = NULL;
	return (split);
}

static char	**ft_chck(char **split, const char *s, char c)
{
	size_t		len;
	size_t		i;
	const char	*start;

	i = 0;
	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		start = s;
		len = 0;
		s--;
		while (*(++s) && *s != c)
			len++;
		if (len)
		{
			if (*(s - 1) != c)
				split[i] = ft_substr(start, 0, len);
			if (!split[i])
				return (free_split(split, i));
			i++;
		}
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char		**split;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (word_cnt(s, c) + 1));
	if (!split)
		return (0);
	split = ft_chck(split, s, c);
	return (split);
}
