/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 10:21:14 by rbliss            #+#    #+#             */
/*   Updated: 2021/09/04 15:31:19 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src_tmp;
	unsigned char	*dest_tmp;

	src_tmp = (unsigned char *)src;
	dest_tmp = (unsigned char *)dst;
	if (dest_tmp < src_tmp)
		while (len-- > 0)
			*dest_tmp++ = *src_tmp++;
	if (dest_tmp > src_tmp)
		while (len-- > 0)
			dest_tmp[len] = src_tmp[len];
	return (dst);
}
