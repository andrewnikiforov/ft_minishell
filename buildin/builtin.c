/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:16:16 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 18:01:56 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(char *str)
{
	if (ft_strcmp(str, "cd") == 0 || ft_strcmp(str, "echo") == 0 || \
	ft_strcmp(str, "env") == 0 || ft_strcmp(str, "exit") == 0 || \
	ft_strcmp(str, "export") == 0 || ft_strcmp(str, "pwd") == 0 || \
	ft_strcmp(str, "unset") == 0)
		return (0);
	return (1);
}

void	builtin_chois(t_cmd *cmd)
{
	if (ft_strcmp(cmd->cmd, "cd") == 0)
		ft_cd(cmd->arg Q cmd->arg[0] S 0, g_mtest.env);
	if (ft_strcmp(cmd->cmd, "echo") == 0)
		ft_echo(cmd->arg, cmd->opt);
	if (ft_strcmp(cmd->cmd, "env") == 0)
		ft_env(g_mtest.env);
	if (ft_strcmp(cmd->cmd, "exit") == 0)
		ft_exit(cmd);
	if (ft_strcmp(cmd->cmd, "export") == 0)
		ft_export(g_mtest.env, cmd->arg);
	if (ft_strcmp(cmd->cmd, "pwd") == 0)
		ft_pwd();
	if (ft_strcmp(cmd->cmd, "unset") == 0)
		ft_unset(g_mtest.env, cmd->arg);
}
