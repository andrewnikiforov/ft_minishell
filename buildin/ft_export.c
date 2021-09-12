/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 18:34:58 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 21:55:47 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**convert_tkn(t_list *tkn)
{
	int			n;
	char		**conv;
	int			i;
	t_list		*tmp;

	i = 0;
	n = ft_lstsize(tkn);
	conv = malloc(sizeof(char *) * (n + 1));
	conv[n] = 0;
	while (tkn)
	{
		conv[i] = ft_strjoin_fr(tkn->key, "=");
		conv[i] = ft_strjoin_fr(conv[i], tkn->value);
		tmp = tkn->next;
		free(tkn->value);
		free(tkn);
		tkn = tmp;
		i++;
	}
	return (conv);
}

void	ft_export(char **env, char **str)
{
	t_list	*list;
	int		i;

	i = -1;
	list = ft_lst_make(sort_arrstr(env));
	if (str == 0)
		ft_lst_print(&list);
	else
	{
		while (str[++i])
			ft_lstadd_midle(&list, str[i]);
	}
	frarr(g_mtest.env);
	g_mtest.env = convert_tkn(list);
}
