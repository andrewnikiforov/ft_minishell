/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_income_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:14:44 by omillan           #+#    #+#             */
/*   Updated: 2021/09/12 12:37:11 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	trim_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

// check single quotes are closed
void	skip_next_quote(char quote, int *flag, int *j, char *str)
{
	*flag = 1;
	while (str[++(*j)])
	{
		if (str[*j] == quote)
		{
			*flag = 0;
			break ;
		}
	}
}

int	quotes_check(char *str)
{
	int	i;
	int	j;
	int	flag_sin;
	int	flag_dub;

	flag_sin = 0;
	flag_dub = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == '\'')
			skip_next_quote('\'', &flag_sin, &j, (str + i));
		else if (str[i] == '"')
			skip_next_quote('"', &flag_dub, &j, (str + i));
		i += j + 1;
	}
	if (flag_sin != 0)
		return (10);
	if (flag_dub != 0)
		return (11);
	return (0);
}

//general func that include small func to check their own keys
int	check_incom_str(char *str)
{
	if (pipe_at_start(str) == 1)
		return (ft_error(1));
	if (pipe_at_end(str) == 2)
		return (ft_error(2));
	if (too_much_rdrct(str) == 3)
		return (ft_error(3));
	if (too_much_pipe(str) == 4)
		return (ft_error(4));
	if (is_slash(str) == 5)
		return (ft_error(5));
	if (is_semicolon(str) == 6)
		return (ft_error(6));
	if (only_one_rdrct(str) == 7)
		return (ft_error(7));
	if (only_twice_rdrct(str) == 8)
		return (ft_error(8));
	if (is_empty(str) == 9)
		return (ft_error(9));
	if (quotes_check(str) == 10)
		return (ft_error(10));
	if (quotes_check(str) == 11)
		return (ft_error(11));
	return (0);
}
