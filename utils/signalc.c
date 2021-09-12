/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signalc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 14:49:10 by omillan           #+#    #+#             */
/*   Updated: 2021/09/12 14:52:36 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ctrl_d(int sig)
{
	printf("exit\n");
	start_initial(&g_mtest, g_mtest.line);
	frarr(g_mtest.env);
	exit(sig);
}

void	sigquit_work(int sig)
{
	(void)sig;
	if (g_mtest.pid == 0)
		write(1, "\b\b \b", 4);
	if (g_mtest.pid != 0)
		printf("Quit: 3\n");
	rl_on_new_line();
	if (g_mtest.pid != 0)
		rl_replace_line("", 0);
	else
		rl_replace_line("  ", 0);
	rl_redisplay();
	if (g_mtest.pid != 0)
		write(1, "\b\b\b\b\b", 5);
}

void	sigint_work(int sig)
{
	(void)sig;
	if (g_mtest.pid)
		write(1, "\n", ft_strlen("\n"));
	else
	{
		rl_on_new_line();
		rl_redisplay();
		write(1, "  \b\b\n", 5);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
	if (g_mtest.pid != 0)
		printf("\b\b\b\b\b");
}
