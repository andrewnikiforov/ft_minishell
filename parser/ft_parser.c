/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:00:08 by omillan           #+#    #+#             */
/*   Updated: 2021/09/12 14:40:10 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_str_redir(t_cmd *cmd, char **p_s, int *p_i, char *tmp)
{
	char	*s;
	int		i;

	s = *p_s;
	i = *p_i;
	if (g_mtest.tmp == 1)
		cmd->reds = add_strarr(cmd->reds, tmp);
	if (s[i])
		i++;
	if (g_mtest.tmp == 1)
		tmp = get_str_cmd(&s, &i);
	if (g_mtest.tmp)
		cmd->reds = add_strarr(cmd->reds, tmp);
	*p_s = s;
	*p_i = i;
}

static int	add_strcmd(t_cmd *cmd, char *tmp, char **p_s, int *p_i)
{
	int		chkcmd;
	int		i;
	char	*s;

	i = *p_i;
	g_mtest.tmp = check_redirect(tmp);
	s = *p_s;
	if (tmp && !cmd->cmd)
		cmd->cmd = tmp;
	else if (tmp && !cmd->opt && tmp[0] == '-')
		cmd->opt = tmp;
	else if (tmp && g_mtest.tmp != -1 && !g_mtest.state)
		get_str_redir(cmd, &s, &i, tmp);
	else if (tmp)
		cmd->arg = add_strarr(cmd->arg, tmp);
	*p_i = i;
	*p_s = s;
	return (0);
}

static int	parser_cmd(t_cmd *cmd, char *s)
{
	int		i;
	int		chkcmd;
	char	*tmp;

	i = 0;
	chkcmd = 0;
	tmp = NULL;
	while (s[i])
	{
		i += ft_skpchr(&s[i], ' ');
		if (!s[i])
			break ;
		tmp = get_str_cmd(&s, &i);
		add_strcmd(cmd, tmp, &s, &i);
		g_mtest.state = 0;
	}
	return (0);
}

int	ft_parser(t_mtest *mtest, char *s)
{
	int		i;
	char	**tsplit;

	i = -1;
	tsplit = split_pipe(s);
	if (!tsplit)
		return (1);
	mtest->cnt = ft_arrlen(tsplit);
	mtest->cmds = ft_calloc(mtest->cnt + 1, sizeof(t_cmd));
	while (tsplit[++i])
		parser_cmd(&mtest->cmds[i], tsplit[i]);
	frarr(tsplit);
	return (0);
}
