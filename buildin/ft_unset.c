/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:35:00 by omillan           #+#    #+#             */
/*   Updated: 2021/09/04 15:00:37 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_unset(char **env, char **str)
{
	t_list	*list;
	int		i;

	i = -1;
	list = ft_lst_make(sort_arrstr(env));
	while (str[++i])
		for_unset(&list, str[i]);
	frarr(g_mtest.env);
	g_mtest.env = convert_tkn(list);
}
