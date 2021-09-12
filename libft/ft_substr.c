/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:54:38 by rbliss            #+#    #+#             */
/*   Updated: 2021/09/04 15:45:43 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*str;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	if (ft_strlen(s + start) > len)
		k = len;
	else
		k = ft_strlen(s);
	i = -1;
	str = malloc(sizeof(char) * (k + 1));
	if (!str)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (++i < k && *(s + start + i))
		*(str + i) = *(s + start + i);
	*(str + i) = '\0';
	return (str);
}
