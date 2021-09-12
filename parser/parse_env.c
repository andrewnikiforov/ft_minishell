/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:00:33 by omillan           #+#    #+#             */
/*   Updated: 2021/09/12 15:21:47 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_str(char *s, int *p_i)
{
	int		i;
	int		start_pos;
	char	*str_env;

	i = 1;
	start_pos = 0;
	while (!(s[i] == ' ' || s[i] == '"' || s[i] == '$') && s[i])
		i++;
	str_env = ft_substr(s, start_pos, i - start_pos);
	*p_i += i;
	return (str_env);
}

static int	stopenv(char *s, int w)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '$' && s[i] != '"')
		i++;
	if (w)
		i = ft_skpnchr(s, ' ');
	return (i);
}

char	*join_env(t_mtest *mtest, char **p_s, int *p_i)
{
	int		i;
	int		w;
	char	*past_env;
	char	*before_chr;
	char	*tmp;

	w = 1;
	i = *p_i;
	tmp = ft_substr(*p_s, 0, i);
	if ((*p_s)[ft_skpnchr(&((*p_s)[i + 1]), '$')])
		w = 0;
	before_chr = tmp;
	tmp = *p_s;
	i++;
	tmp = ft_getenv(ft_substr(tmp, i, stopenv(&tmp[i], 1)));
	before_chr = ft_strjoin_fr(before_chr, tmp);
	past_env = *p_s;
	past_env = ft_substr(*p_s, *p_i + stopenv(&past_env[*p_i], 1), \
				ft_strlen(*p_s) - *p_i - stopenv(&past_env[*p_i], 1));
	*p_i = ft_strlen(before_chr);
	before_chr = ft_strjoin_fr(before_chr, past_env);
	*p_s = before_chr;
	free(before_chr);
	free(past_env);
	return (tmp);
}

int	loop_join_env(t_mtest *mtest, char **olds, int *p_i)
{
	int		i;
	char	*s;
	char	*result;

	i = *p_i;
	s = *olds;
	while (1)
	{
		if (s[i] == '$')
			result = join_env(mtest, &s, &i);
		if (s[i] && s[i] == '\"')
			break ;
		if (s[i] != '$')
			i++;
	}
	*olds = s;
	return (0);
}
