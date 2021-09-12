/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:20:51 by rbliss            #+#    #+#             */
/*   Updated: 2021/09/04 15:53:53 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	help(int res1, int sign1, int k1)
{
	if (k1 >= 19)
	{
		if (sign1 == -1)
			res1 = 0;
		else
			res1 = -1;
	}
	return (res1);
}

int	skip_zero(const char *s, int *i)
{
	int	k;
	int	j;

	j = *i;
	k = 0;
	while (s[k] == '0')
	{
		k++;
		j++;
	}
	return (j);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		rez;
	int		sign;
	int		k;

	i = 0;
	sign = 1;
	rez = 0;
	k = 1;
	while (((*(str + i) > 8 && *(str + i) < 14) || *(str + i) == ' '))
		i++;
	if ((*(str + i) == '-' || *(str + i) == '+') && ft_isdigit(*(str + i + 1)))
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	i = skip_zero(str + i, &i);
	while (ft_isdigit(*(str + i)))
	{
		rez = rez * 10 + (*(str + i++) - '0');
		k++;
	}
	return (sign * help(rez, sign, k));
}
