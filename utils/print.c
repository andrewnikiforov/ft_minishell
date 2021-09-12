/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:50:29 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 18:50:30 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printarr(char **arr, char *what)
{
	int	i;

	i = -1;
	printf("%s: \n", what);
	while (arr && arr[++i])
		printf("%i) %s\n", i, arr[i]);
}
