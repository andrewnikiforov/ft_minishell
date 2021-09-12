/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:50:08 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 18:50:11 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**cpyarr(char **arr)
{
	int		i;
	int		cnt;
	char	**narr;

	i = -1;
	cnt = ft_arrlen(arr);
	narr = ft_calloc(cnt + 1, sizeof(char *));
	while (arr[++i])
		narr[i] = ft_strdup(arr[i]);
	return (narr);
}

char	**cpyarr_add(char **arr, char **add)
{
	int		i;
	int		j;
	char	**tmp_arr;

	i = -1;
	j = -1;
	tmp_arr = ft_calloc(ft_arrlen(arr) + ft_arrlen(add) + 1, sizeof(char *));
	while (arr[++i])
		tmp_arr[i] = arr[i];
	while (add[++j])
		tmp_arr[i++] = add[j];
	free(arr);
	free(add);
	return (tmp_arr);
}

char	**ft_subarr(char **arr, int start, int len)
{
	int		i;
	int		j;
	char	**tmp_arr;

	i = start;
	j = -1;
	tmp_arr = ft_calloc(len + 1, sizeof(char *));
	while (++j < len)
	{
		tmp_arr[j] = ft_strdup(arr[i]);
		i++;
	}
	return (tmp_arr);
}
