/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:00:31 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 22:00:32 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*getstr_qouter(char **p_s, int *p_i, char *qut)
{
	int		i;
	int		start;
	char	*s;

	i = *p_i;
	s = *p_s;
	i++;
	if (*qut == '"')
		loop_join_env(&g_mtest, &s, &i);
	start = i;
	i += ft_skpnchr(&s[i], *qut);
	*qut = 0;
	*p_i = i;
	*p_s = s;
	return (ft_substr(s, start, i - start));
}

static char	*get_result(char **p_s, int *p_i, char *qut, char *result)
{
	char	*s;
	char	*res;
	int		start;

	s = *p_s;
	res = NULL;
	start = 0;
	if (*qut)
	{
		(*p_i)++;
		g_mtest.state = 1;
		if (*qut == '"')
			loop_join_env(&g_mtest, &s, p_i);
		start = *p_i;
		*p_i += ft_skpnchr(&s[*p_i], *qut);
		*qut = 0;
		res = ft_substr(s, start, *p_i - start);
	}
	else if (s[*p_i] == '$')
		res = join_env(&g_mtest, &s, p_i);
	else if (s[*p_i] != ' ')
		res = add_chr(result, s[*p_i]);
	*p_s = s;
	return (res);
}

char	*get_str_cmd(char **p_s, int *p_i)
{
	int		i;
	int		start;
	char	qut;
	char	*result;
	char	*s;

	i = *p_i;
	s = *p_s;
	result = NULL;
	start = 0;
	qut = 0;
	while (s[i] && s[i] != ' ')
	{
		if (s[i] == '\'')
			qut = '\'';
		else if (s[i] == '"')
			qut = '"';
		result = get_result(&s, &i, &qut, result);
		if (s[i] && s[i] != ' ')
			i++;
	}
	*p_s = s;
	*p_i = i;
	return (result);
}
