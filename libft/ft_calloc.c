/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:29:00 by rbliss            #+#    #+#             */
/*   Updated: 2021/09/04 15:47:33 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int count, int size)
{
	void	*ar;

	ar = (void *)malloc(count * size);
	if (!ar)
		return (NULL);
	ft_bzero(ar, count * size);
	return (ar);
}
