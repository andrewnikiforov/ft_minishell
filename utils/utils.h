/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:50:59 by omillan           #+#    #+#             */
/*   Updated: 2021/09/11 18:51:00 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

char	*add_chr(char *s, char c);
char	**add_strarr(char **arr, char *s);

char	**cpyarr(char **arr);
char	**cpyarr_add(char **arr, char **add);
char	**ft_subarr(char **arr, int start, int len);

int		frln(void *ln);
int		frarr(char **arr);

char	*ft_strjoin_fr(char *s1, char *s2);

int		setval_int(int *v, int a);
int		ternopr_i(int w, int y, int n);
void	**ternopr_arr(int w, void **y, void **n);

int		ft_arrlen(char **arr);

void	printarr(char **arr, char *what);

char	**sort_arrstr(char **arr);
int		ft_strcmp(char *s1, char *s2);

#endif