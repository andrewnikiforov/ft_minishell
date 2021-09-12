/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_check_func3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:45:29 by omillan           #+#    #+#             */
/*   Updated: 2021/09/12 14:23:55 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//return func
int	ft_return(char *str, int i)
{
	printf("%s", str);
	return (i);
}

//error func
int	ft_error(int i)
{
	if (i == 1)
		return (ft_return("Error: pipe at start\n", 1));
	if (i == 2)
		return (ft_return("Error: pipe at the end\n", 2));
	if (i == 3)
		return (ft_return("Error: to much simbols of redirect\n", 3));
	if (i == 4)
		return (ft_return("Error: to much pipes\n", 4));
	if (i == 5)
		return (ft_return("Error: there is a revers slash\n", 5));
	if (i == 6)
		return (ft_return("Error: there is a semicolon\n", 6));
	if (i == 7)
		return (ft_return("Error: there is only one redirect\n", 7));
	if (i == 8)
		return (ft_return("Error: there is only twice redirect\n", 8));
	if (i == 9)
		return (ft_return("", 9));
	if (i == 10)
		return (ft_return("Error: the single quotes are not closed\n", 10));
	if (i == 11)
		return (ft_return("Error: the double quotes are not closed\n", 11));
	if (i == 12)
		return (ft_return("", 12));
	return (0);
}

//pipe at start
int	pipe_at_start(char *str)
{
	if (*(str + trim_space(str)) == '|')
		return (1);
	return (0);
}
