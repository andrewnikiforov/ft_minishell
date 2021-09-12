/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 19:19:45 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 21:57:09 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_list	*ft_lstnew(char *line)
{
	t_list	*node;
	char	**arr;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	arr = ft_split(line, '=');
	node->key = ft_strdup(arr[0]);
	node->value = ft_strdup(arr[1]);
	node->next = NULL;
	frarr(arr);
	return (node);
}

void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	free(lst->key);
	free(lst->value);
	free(lst);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		free(tmp->key);
		free(tmp->value);
		*lst = tmp->next;
		free(tmp);
	}
	*lst = NULL;
}

void	ft_ifequal(char *line, t_list *tmp)
{
	if (ft_strrchr(line, '='))
	{
		free(tmp->value);
		tmp->value = ft_strdup(line);
	}
}

int	if_key_eq(t_list *tmp, char **arr, char *line)
{
	if (ft_strrchr(line, '='))
	{
		free(tmp->value);
		tmp->value = ft_strdup(arr[1]);
	}
	frarr(arr);
	return (0);
}
