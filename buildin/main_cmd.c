/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:09:45 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 18:01:23 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmds_redir(void)
{
	int	i;

	i = -1;
	while (++i < g_mtest.cnt)
	{
		cmdredir(&g_mtest.cmds[i]);
		redir_all(&g_mtest.cmds[i]);
	}
}

int	run_cmds(void)
{
	int	i;
	int	prev[2];
	int	next[2];

	i = -1;
	next[0] = -1;
	next[1] = -1;
	while (++i < g_mtest.cnt)
	{
		prev[0] = next[0];
		prev[1] = next[1];
		if (i != g_mtest.cnt - 1)
			pipe(next);
		if (prev[1] != -1)
			close(prev[1]);
		runfork(prev, next, i);
		if (prev[0] != -1)
			close(prev[0]);
	}
	return (0);
}
