/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:50:41 by omillan           #+#    #+#             */
/*   Updated: 2021/08/29 12:49:54 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_echo(char **line, char *n)
{
	int		i;
	int		j;
	char	*s;

	s = 0;
	i = -1;
	if (line)
	{
		j = ft_arrlen(line);
		while (++i < j)
		{
			if (n != 0 && ft_strcmp(n, "-n") != 0)
			{
				s = ft_strjoin_fr(s, n);
				s = ft_strjoin_fr(s, " ");
			}
			s = ft_strjoin_fr(s, line[i]);
			s = ft_strjoin_fr(s, " ");
		}
		printf("%s", s);
	}
	if (n == 0 || ft_strcmp(n, "-n") != 0)
		printf("\n");
	free(s);
	return (0);
}
