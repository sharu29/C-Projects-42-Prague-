/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snataraj <snataraj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:54:28 by snataraj          #+#    #+#             */
/*   Updated: 2025/01/10 16:11:38 by snataraj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_words(char *s, char c)
{
	int	flag;
	int	count;

	count = 0;
	while (*s)
	{
		flag = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (!flag)
			{
				count++;
				flag = 1;
			}
			s++;
		}
	}
	return (count);
}

static char	*ft_create_word(char *s, char sep)
{
	char		*dt;
	int			i;
	int			len;
	static int	cursor = 0;

	i = 0;
	len = 0;
	while (s[cursor] == sep)
		cursor++;
	while ((s[cursor + len] != sep) && s[cursor + len])
		len++;
	dt = malloc((size_t)len * (sizeof(char) + 1));
	if (!dt)
		return (NULL);
	while ((s[cursor] != sep) && s[cursor])
	{
		dt[i++] = s[cursor++];
	}
	dt[i] = '\0';
	return (dt);
}

char	**ft_split(char *s, char c)
{
	char	**fstr;
	int		i;
	int		word_count;

	i = 0;
	word_count = ft_words(s, c);
	if (!word_count)
		exit(1);
	fstr = malloc(sizeof(char *) * (size_t)(word_count + 2));
	if (!fstr)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (i == 0)
		{
			fstr[i] = malloc(sizeof(char));
			if (fstr[i] == NULL)
				return (NULL);
			fstr[i++][0] = '\0';
			continue ;
		}
		fstr[i++] = ft_create_word(s, c);
	}
	fstr[i] = NULL;
	return (fstr);
}
