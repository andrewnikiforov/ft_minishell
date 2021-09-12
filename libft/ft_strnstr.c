/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbliss <rbliss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 09:19:46 by rbliss            #+#    #+#             */
/*   Updated: 2020/11/07 15:37:10 by rbliss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haysack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_hay;
	size_t	len_need;

	i = 0;
	len_hay = ft_strlen(haysack);
	len_need = ft_strlen(needle);
	if (needle[0] == '\0' || haysack == needle)
		return ((char *)haysack);
	if (haysack[0] == '\0' || len == 0)
		return (NULL);
	while (haysack[i] && i < len)
	{
		if (i + len_need > len)
			return (NULL);
		if (!ft_strncmp(&haysack[i], needle, len_need))
			return ((char *)&haysack[i]);
		i++;
	}
	return (NULL);
}
