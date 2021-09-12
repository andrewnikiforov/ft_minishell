/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:50:00 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 18:50:03 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*add_chr(char *s, char c)
{
	int		i;
	char	*tmp;

	i = -1;
	if (!s)
		s = ft_calloc(1, sizeof(char));
	tmp = malloc(sizeof(char) * (ft_strlen(s) + 2));
	while (s[++i])
		tmp[i] = s[i];
	tmp[i++] = c;
	tmp[i] = '\0';
	free(s);
	return (tmp);
}

char	**add_strarr(char **arr, char *s)
{
	int		i;
	int		len;
	char	**result;

	i = -1;
	if (ft_strlen(s) == 0)
		return (arr);
	if (!arr)
		arr = ft_calloc(1, sizeof(char *));
	len = ft_arrlen(arr);
	result = ft_calloc(len + 2, sizeof(char *));
	while (++i < len)
		result[i] = arr[i];
	result[i] = s;
	free(arr);
	return (result);
}
