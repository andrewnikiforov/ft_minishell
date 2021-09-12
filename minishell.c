/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:01:43 by omillan           #+#    #+#             */
/*   Updated: 2021/09/12 15:33:00 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "termios.h"

void	frcmds(void)
{
	int	i;

	i = 0;
	while (i < g_mtest.cnt)
	{
		free(g_mtest.cmds[i].cmd);
		free(g_mtest.cmds[i].opt);
		if (g_mtest.cmds[i].reds)
		{
			frarr(g_mtest.cmds[i].reds);
		}
		if (g_mtest.cmds[i].arg)
			frarr(g_mtest.cmds[i].arg);
		i++;
	}
	free(g_mtest.cmds);
}

void	setting_initval(void)
{
	int	i;

	i = 0;
	g_mtest.cmds = NULL;
	g_mtest.cnt = 0;
}

void	start_initial(t_mtest *mshll, char *line)
{
	g_mtest.pid = 0;
	frcmds();
	setting_initval();
	free(line);
}

void	helper(char *line)
{
	g_mtest.line = line;
	if (!line)
		ctrl_d(131);
	add_history(line);
}

int	main(int ac, char **av, char **ev)
{
	char	*line;
	int		r;
	int		i;
	int		j;

	line = NULL;
	g_mtest.env = cpyarr(ev);
	signal(SIGINT, sigint_work);
	signal(SIGQUIT, sigquit_work);
	while (1)
	{
		if (g_mtest.pid == 0)
			line = readline("🤩$: ");
		helper(line);
		!check_incom_str(line) && !ft_parser(&g_mtest, line);
		cmds_redir();
		if (errno && setval_int(&g_mtest.exit, 1))
			printf("🤩: %s\n", strerror(errno));
		else
			run_cmds();
		unlink("temp_file");
		start_initial(&g_mtest, line);
	}
}
