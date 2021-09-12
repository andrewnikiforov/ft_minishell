/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmdshell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:10:50 by omillan           #+#    #+#             */
/*   Updated: 2021/09/12 15:25:49 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*getpth(char *cmd)
{
	int		i;
	int		fd;
	char	*result_pth;
	char	**path_bin;

	i = 0;
	fd = 0;
	result_pth = NULL;
	if ((cmd[0] == '/') || (cmd[0] == '.' && cmd[1] == '/'))
		return (ft_strdup(cmd));
	path_bin = ft_split(ft_getenv(ft_strdup("PATH")), ':');
	while (path_bin[++i])
	{
		free(result_pth);
		result_pth = NULL;
		result_pth = ft_strjoin("/", cmd);
		fd = open(ft_strjoin(path_bin[i], result_pth), O_RDONLY);
		result_pth = ft_strjoin(path_bin[i], result_pth);
		close(fd);
		if (fd > 1)
			break ;
	}
	return (result_pth);
}

static void	runcmd(t_cmd *cmd)
{
	int		i;
	int		j;
	int		cnt;
	char	**arg;

	i = 0;
	j = 0;
	cnt = 1;
	if (cmd->opt)
		cnt++;
	cnt += ft_arrlen(cmd->arg);
	arg = ft_calloc((cnt + 1), sizeof(char *));
	arg[i++] = cmd->cmd;
	if (cmd->opt)
		arg[i++] = cmd->opt;
	while (cmd->arg && cmd->arg[j])
	{
		arg[i] = cmd->arg[j];
		j++;
		i++;
	}
	g_mtest.exit = execve(getpth(cmd->cmd), arg, g_mtest.env);
	g_mtest.exit = 127;
	if (g_mtest.exit)
		printf("bash: %s\n", "command not found");
}

static void	notbuildin(int *prev, int *next, int i)
{
	char	*exp[2];

	if (g_mtest.cnt != 1 && i != 0 && \
		g_mtest.cmds[i].type != REDIR_L && \
		g_mtest.cmds[i].type != REDIR_BOTH)
		g_mtest.cmds[i].out = prev[0];
	if (g_mtest.cnt != 1 && i != g_mtest.cnt - 1 && \
		g_mtest.cmds[i].type != REDIR_R && \
		g_mtest.cmds[i].type != REDIR_BOTH)
		g_mtest.cmds[i].in = next[1];
	dup2(g_mtest.cmds[i].out, 0);
	dup2(g_mtest.cmds[i].in, 1);
	if (ft_strcmp(g_mtest.cmds[i].cmd, "./minishell") == 0)
	{
		exp[0] = ft_strjoin("SHLVL=", \
			ft_itoa(ft_atoi(ft_getenv(ft_strdup("SHLVL"))) + 1));
		exp[1] = NULL;
		ft_export(g_mtest.env, exp);
	}
	if (is_builtin(g_mtest.cmds[i].cmd))
		runcmd(&g_mtest.cmds[i]);
	else
		builtin_chois(&g_mtest.cmds[i]);
	exit(g_mtest.exit);
}

void	runfork(int *prev, int *next, int i)
{
	int	id;

	g_mtest.pid = -1;
	if (is_builtin(g_mtest.cmds[i].cmd) || \
		(ft_strcmp(g_mtest.cmds[i].cmd, "echo") == 0) || \
		(ft_strcmp(g_mtest.cmds[i].cmd, "env") == 0))
		g_mtest.pid = fork();
	if (!g_mtest.pid)
		notbuildin(prev, next, i);
	if ((ft_strcmp(g_mtest.cmds[i].cmd, "echo")) && \
		(ft_strcmp(g_mtest.cmds[i].cmd, "env")) && g_mtest.cnt == 1)
		builtin_chois(&g_mtest.cmds[i]);
	waitpid(g_mtest.pid, &g_mtest.exit, 0);
	if (WIFEXITED(g_mtest.exit))
		g_mtest.exit = WEXITSTATUS(g_mtest.exit) % 255;
}
