/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:03:02 by omillan           #+#    #+#             */
/*   Updated: 2021/09/12 15:16:08 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exit(t_cmd *cmd)
{
	int		stat_exit;

	stat_exit = 0;
	if (cmd->arg)
		stat_exit = ft_atoi(cmd->arg[0]);
	if (ft_arrlen(cmd->arg) > 1)
	{
		printf("exit: too many arguments\n");
		return ;
	}
	printf("exit\n");
	exit(stat_exit);
}
