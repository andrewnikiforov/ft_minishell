/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:10:15 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 18:44:08 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
static int	herdoc(char *end)
{
	char	*line;
	int		fd;

	line = NULL;
	fd = open("temp_file", O_WRONLY | O_CREAT, S_IRWXU);
	while (1)
	{
		line = readline(">");
		ft_putstr_fd(line, fd);
		if ((ft_strlen(end) == ft_strlen(line)) && \
			(ft_strnstr(line, end, ft_strlen(end))))
			break ;
		ft_putstr_fd("\n", fd);
		free(line);
		line = NULL;
	}
	free(line);
	close(fd);
	fd = open("temp_file", O_RDONLY);
	return (fd);
}

static int	openred(t_cmd *cmd, int *fd_in, int *fd_out, int i)
{
	if (cmd->reds[i][0] == '<' && cmd->reds[i][1] == '<')
		*fd_out = herdoc(cmd->reds[i + 1]);
	else if (cmd->reds[i][0] == '<')
		*fd_out = open(cmd->reds[i + 1], O_RDONLY, S_IRWXU);
	else if (cmd->reds[i][0] == '>' && cmd->reds[i][1] == '>')
		*fd_in = open(cmd->reds[i + 1], O_CREAT | O_WRONLY + O_APPEND, S_IRWXU);
	else if (cmd->reds[i][0] == '>')
		*fd_in = open(cmd->reds[i + 1], O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	return (0);
}

static char	**split_redir(char *s)
{
	int		i;
	int		start;
	char	chr;
	char	*tmp;
	char	**tmp_redir;

	if (!ft_skpnchr(s, '>') && !ft_skpnchr(s, '<'))
		return (0);
	i = 0;
	tmp_redir = NULL;
	while (s[i])
	{
		start = i;
		chr = s[i];
		if ((s[i] == '>' && s[i + 1] == '>') || \
			(s[i] == '<' && s[i + 1] == '<'))
			i++;
		if (chr != '>' && chr != '<')
			i += ternopr_i(ft_skpnchr(&s[i], '>') < ft_skpnchr(&s[i], '<'), \
						ft_skpnchr(&s[i], '>'), ft_skpnchr(&s[i], '<')) - 1;
		tmp = ft_substr(s, start, i - start + 1);
		tmp_redir = add_strarr(tmp_redir, tmp);
		i++;
	}
	return (tmp_redir);
}

int	redir_all(t_cmd *cmd)
{
	int	i;
	int	fd_in;
	int	fd_out;

	i = 0;
	fd_out = 0;
	fd_in = 1;
	while (cmd->reds && cmd->reds[i])
	{
		openred(cmd, &fd_in, &fd_out, i);
		i += 2;
	}
	cmd->out = fd_out;
	cmd->in = fd_in;
	if (cmd->out != 0)
		cmd->type = REDIR_L;
	if (cmd->in != 1)
		cmd->type += REDIR_R;
	return (0);
}

int	cmdredir(t_cmd *cmd)
{
	int		i;
	char	**tmp;
	char	**tmp_red;

	i = 0;
	tmp_red = NULL;
	while (cmd->reds && cmd->reds[i])
	{
		if ((cmd->reds[i][0] == '>' || cmd->reds[i][0] == '<') && \
			ft_strlen(cmd->reds[i]) > 1)
		{
			tmp_red = ft_subarr(cmd->reds, 0, i);
			tmp = split_redir(cmd->reds[i]);
			tmp_red = cpyarr_add(tmp_red, tmp);
			tmp = ft_subarr(cmd->reds, i + 1, ft_arrlen(cmd->reds) - i);
			frarr(cmd->reds);
			cmd->reds = cpyarr_add(tmp_red, tmp);
		}
		i++;
	}
	return (1);
}
