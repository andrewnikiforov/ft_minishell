/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:50:35 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 18:50:40 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	swap_str(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s1[i] == 0)
			return (0 - (int)s2[i]);
		if (s2[i] == 0)
			return ((int)s1[i] - 0);
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

char	**sort_arrstr(char **arr)
{
	int		i;
	int		j;
	int		cnt;

	i = -1;
	cnt = ft_arrlen(arr);
	while (++i < cnt)
	{
		j = -1;
		while (++j < cnt - 1)
			if (ft_strcmp(arr[j], arr[j + 1]) > 0)
				swap_str(&arr[j], &arr[j + 1]);
	}
	return (arr);
}
