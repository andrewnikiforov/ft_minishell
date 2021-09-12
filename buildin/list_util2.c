/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:08:38 by omillan           #+#    #+#             */
/*   Updated: 2021/09/12 12:25:43 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_value(char *key, t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key) && (ft_strlen(key) \
											== ft_strlen(tmp->key)))
			return (tmp->value);
		tmp = tmp->next;
	}
	return ("\n");
}

t_list	*if_unset_first(t_list **list, t_list *tmp)
{
	*list = tmp->next;
	ft_lstdelone(tmp);
	return (*list);
}

t_list	*for_unset(t_list **list, char *key)
{
	t_list	*tmp;
	t_list	*ptr;
	int		i;

	i = 0;
	tmp = *list;
	ptr = *list;
	while (tmp)
	{
		if (!ft_strcmp(key, tmp->key) && (ft_strlen(key) \
										== ft_strlen(tmp->key)))
		{
			if (i == 0)
				return (if_unset_first(list, tmp));
			ptr->next = tmp->next;
			ft_lstdelone(tmp);
			return (*list);
		}
		i++;
		ptr = tmp;
		tmp = tmp->next;
	}
	return (*list);
}

char	*ft_getenv(char *key)
{
	t_list	*list;
	char	*value;

	if (!ft_strcmp(key, "?"))
		return (ft_itoa(g_mtest.exit));
	list = ft_lst_make(g_mtest.env);
	value = get_value(key, &list);
	g_mtest.list = list;
	free(key);
	return (value);
}

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*tmp;

	size = 0;
	tmp = lst;
	if (!tmp)
		return (size);
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
