/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:41:46 by rbliss            #+#    #+#             */
/*   Updated: 2021/09/11 21:13:27 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "stdio.h"
# include "stdlib.h"
# include "unistd.h"
# define MAX_LONG 9223372036854775807

int					ft_atoi(const char *str);
void				ft_bzero(void *s, unsigned int n);
void				*ft_calloc(int count, int size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strchr(const char *str, int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
// void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
// char				**ft_split(const char *s, char c);
char				*strchr(const char *str, int c);
// char				*ft_strdup(const char *s1);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
// size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
int					ft_strlen(const char *s);
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haysack, \
								const char *needle, size_t len);
// char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char *s1, char *set);
char				*ft_substr(const char *s, int start, int len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strdup(char *s1);

#	endif
