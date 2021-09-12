/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:06:58 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 18:06:19 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	if_key_greater(t_list **lst, char **arr, char *line)
{
	ft_lstadd_front(lst, ft_lstnew(line));
	frarr(arr);
	return (1);
}

int	if_key_middle(t_list *ptr, t_list *tmp, char *line, char **arr)
{
	ptr = tmp->next;
	tmp->next = ft_lstnew(line);
	tmp->next->next = ptr;
	frarr(arr);
	return (0);
}

int	ft_lstadd_midle(t_list **lst, char *line)
{
	t_list	*tmp;
	t_list	*ptr;
	char	**arr;

	arr = ft_split(line, '=');
	tmp = *lst;
	ptr = 0;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->key, arr[0]) == 0)
			return (if_key_eq(tmp, arr, line));
		if (ft_strcmp(tmp->key, arr[0]) > 0)
			return (if_key_greater(lst, arr, line));
		if (ft_strcmp(tmp->key, arr[0]) < 0 \
					&& ft_strcmp(tmp->next->key, arr[0]) > 0)
			return (if_key_middle(ptr, tmp, line, arr));
		tmp = tmp->next;
	}
	ft_lstadd_back(lst, ft_lstnew(line));
	frarr(arr);
	return (0);
}

void	ft_lst_print(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->value)
			printf("declare -x %s=\"%s\"\n", tmp->key, tmp->value);
		else
			printf("declare -x %s\n", tmp->key);
		tmp = tmp->next;
	}
}

t_list	*ft_lst_make(char **line)
{
	int		count_arr;
	t_list	*lst;
	int		i;

	lst = 0;
	i = -1;
	count_arr = ft_arrlen(line);
	while (++i < count_arr)
		ft_lstadd_back(&lst, ft_lstnew(line[i]));
	return (lst);
}
