/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_check_func2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:43:46 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 21:13:51 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//pipe at the end
int	pipe_at_end(char *str)
{
	char	*str1;

	str1 = ft_strtrim(str, " ");
	if (str[ft_strlen(str1) - 1] == '|')
	{
		free(str1);
		return (2);
	}
	free(str1);
	return (0);
}

//is there a string like '>>>' or '<<<'
int	too_much_rdrct(char *str)
{
	if (ft_strnstr(str, ">>>", ft_strlen(str)) || \
							ft_strnstr(str, "<<<", ft_strlen(str)))
		return (3);
	return (0);
}

// is space between redirect like '> >' or between pipe like '| |'
int	space_btw_rdrct(char *str)
{
	int	i;
	int	count;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = 0;
		if (str[i] == '>')
		{
			while (str[i + (++j)])
			{
				if (str[i + j] == ' ')
					continue ;
				if (str[i + j] == '>')
					return (12);
			}
		}
	}
	return (0);
}

int	space_btw_pipe(char *str)
{
	int	i;
	int	count;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = 0;
		if (str[i] == '|')
		{
			while (str[i + (++j)])
			{
				if (str[i + j] == ' ')
					continue ;
				if (str[i + j] == '|')
					return (12);
			}
		}
	}
	return (0);
}

//is there a string like '||'
int	too_much_pipe(char *str)
{
	if (ft_strnstr(str, "||", ft_strlen(str)))
		return (4);
	return (0);
}
