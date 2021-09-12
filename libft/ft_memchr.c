/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:14:51 by rbliss            #+#    #+#             */
/*   Updated: 2021/09/04 15:29:17 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	a;

	p = (unsigned char *)s;
	a = (unsigned char)c;
	while (n--)
	{
		if (*p == a)
			return (p);
		p++;
	}
	return (NULL);
}
