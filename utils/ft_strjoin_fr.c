/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_fr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:50:18 by omillan           #+#    #+#             */
/*   Updated: 2021/09/12 12:44:05 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_fr(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;
	int		len_str;

	if (!s1)
		return (s2);
	len_str = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(len_str + 1);
	if (!(str))
		return (NULL);
	i = 0;
	j = -1;
	while (s1[++j])
		str[i++] = s1[j];
	j = -1;
	while (s2 && s2[++j])
		str[i++] = s2[j];
	str[i] = '\0';
	free(s1);
	return (str);
}
