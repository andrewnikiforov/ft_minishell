/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 12:54:15 by omillan           #+#    #+#             */
/*   Updated: 2021/09/12 11:47:39 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*make_oldpwd(void)
{
	char	*oldpwd;
	char	buf[200];

	oldpwd = ft_strjoin("OLDPWD=", getcwd(buf, 200));
	return (oldpwd);
}

char	*make_pwd(char *path)
{
	char	*curent_pwd;
	char	buf[200];

	curent_pwd = ft_strjoin("PWD=", getcwd(buf, 200));
	curent_pwd = ft_strjoin_fr(curent_pwd, "/");
	curent_pwd = ft_strjoin_fr(curent_pwd, path);
	return (curent_pwd);
}

int	ft_cd(char *path, char **env)
{
	t_list	*list;
	char	*new;
	char	*old;
	char	buf[200];

	if (!path)
		path = ft_strdup(getenv("HOME"));
	list = ft_lst_make(sort_arrstr(env));
	new = make_pwd(path);
	old = make_oldpwd();
	if (chdir(path) == 0)
	{
		ft_lstadd_midle(&list, new);
		ft_lstadd_midle(&list, old);
		free(new);
		free(old);
	}
	else
		printf("🤩$: cd: %s %s\n", path, strerror(errno));
	frarr(g_mtest.env);
	g_mtest.env = convert_tkn(list);
	return (0);
}
