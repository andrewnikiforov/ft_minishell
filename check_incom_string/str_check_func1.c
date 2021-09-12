/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_check_func1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:42:24 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 21:59:06 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//is there a simbol "\"
int	is_slash(char *str)
{
	if (ft_strchr(str, '\\') != 0)
		return (5);
	return (0);
}

// is there a simbol ';'
int	is_semicolon(char *str)
{
	if (ft_strchr(str, ';') != 0)
		return (6);
	return (0);
}

// is there only one redirect '<' or '>'
int	only_one_rdrct(char *str)
{
	char	*s;

	s = ft_strtrim(str, " ");
	if (s[0] == '>' || s[0] == '<')
	{
		free(s);
		return (7);
	}
	free(s);
	return (0);
}

// is there only string like '>>' or '<<'
int	only_twice_rdrct(char *str)
{
	char	*s;

	s = ft_strtrim(str, " ");
	if (ft_strnstr(str, "<<", 2) || ft_strnstr(str, ">>", 2))
	{
		free(s);
		return (8);
	}
	free(s);
	return (0);
}

// is there an empty line
int	is_empty(char *str)
{	
	if (ft_strlen(str + trim_space(str)) == 0)
		return (9);
	return (0);
}
