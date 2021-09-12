/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:00:38 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 22:00:39 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**getarr_split(char **otmp_split, char *s, int *p_start_cpy, int i)
{
	char	**tmp_split;
	int		start_cpy;

	start_cpy = *p_start_cpy;
	tmp_split = add_strarr(otmp_split, \
						ft_substr(s, start_cpy, i - start_cpy));
	start_cpy = i + 1;
	*p_start_cpy = start_cpy;
	return (tmp_split);
}

char	**split_pipe(char *s)
{
	int		i;
	int		start_cpy;
	char	**tmp_split;

	i = 0;
	tmp_split = NULL;
	start_cpy = 0;
	while (1)
	{
		if (s[i] && s[i] == '\'')
			i += ft_skpnchr(&s[i + 1], '\'') + 1;
		else if (s[i] && s[i] == '"')
			i += ft_skpnchr(&s[i + 1], '\"') + 1;
		if (s[i] == '|' || !s[i])
			tmp_split = getarr_split(tmp_split, s, &start_cpy, i);
		if (!s[i])
			break ;
		if (s && s[i])
			i++;
	}
	return (tmp_split);
}
