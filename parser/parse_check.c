/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:00:28 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 22:00:29 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_redirect(char *s)
{
	int	i;
	int	chk_file;

	if (s && ft_strlen(s) < 3 && (s[0] == '<' || s[0] == '>'))
		return (1);
	i = 0;
	chk_file = -1;
	while (s && s[i])
	{
		if (s[i] == '<' || s[i] == '>')
			chk_file = 1;
		else if (chk_file == 1 && (s[i] != '<' || s[i] != '>'))
			chk_file = 0;
		i++;
	}
	return (ternopr_i(chk_file == -1, -1, 1));
}
