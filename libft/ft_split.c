/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:26:42 by rbliss            #+#    #+#             */
/*   Updated: 2021/09/04 15:34:24 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**clean(char **ar)
{
	size_t	i;

	i = 0;
	while (ar[i])
	{
		free(ar[i]);
		i++;
	}
	free(ar);
	return (NULL);
}

static size_t	count_word(char const *s, char c)
{
	size_t	count;
	char	*str;

	str = (char *)s;
	count = 0;
	while (*str)
	{
		if (*str == c)
		{
			str++;
			continue ;
		}
		if (*str != c)
		{
			while (*str != c && *str)
				str++;
			count++;
		}
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	count;
	char	*str;

	str = (char *)s;
	count = 0;
	while (*str != c && *str)
	{
		count++;
		str++;
	}
	return (count);
}

static char	*trim_str(char *s, char c)
{
	char	*str;

	str = s;
	while (*str == c && *str)
		str++;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	size_t	words;
	char	**arr;
	size_t	i;
	size_t	j;

	i = -1;
	str = (char *)s;
	words = count_word(str, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	while (++i < words)
	{
		str = trim_str(str, c);
		arr[i] = malloc(sizeof(char) * (word_len(str, c) + 1));
		if (!arr[i])
			clean(arr);
		j = 0;
		while (*str != c && *str != '\0')
			arr[i][j++] = *str++;
		arr[i][j] = '\0';
	}
	arr[i] = NULL;
	return (arr);
}
