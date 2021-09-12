/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_for_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:50:22 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 18:50:23 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	setval_int(int *v, int a)
{
	*v = a;
	return (1);
}

int	ternopr_i(int w, int y, int n)
{
	if (w)
		return (y);
	return (n);
}

void	**ternopr_arr(int w, void **y, void **n)
{
	if (w)
		return (y);
	return (n);
}
