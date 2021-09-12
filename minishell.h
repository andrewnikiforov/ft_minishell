/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omillan <omillan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 18:52:36 by omillan           #+#    #+#             */
/*   Updated: 2021/09/12 14:51:38 by omillan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <fcntl.h>
# include <sys/ioctl.h>
# include <sched.h>
# include <sys/mman.h>
# include <signal.h>
# include <term.h>
# include "stdio.h"
# include "unistd.h"
# include "stdlib.h"
# include "libft/libft.h"
# include "utils/utils.h"
# include "readline/history.h"
# include "readline/readline.h"
# include "sys/errno.h"

# define DOUBLE_REDIR_R 1
# define REDIR_R 2
# define DOUBLE_REDIR_L 3
# define REDIR_L 4
# define REDIR_BOTH 6
# define Q ?
# define S :

typedef struct s_list
{
	char			*key;
	char			*value;
	struct s_list	*next;
}					t_list;

typedef struct s_envm
{
	char			**def;
	char			**srtdef;
	char			**new_env;
	char			**srt_new_env;
}					t_env;

typedef struct s_cmd
{
	char			*cmd;
	char			*opt;
	char			**arg;
	char			**reds;
	int				in;
	int				out;
	int				type;
}					t_cmd;

typedef struct s_mtest
{
	t_cmd			*cmds;
	t_list			*list;
	char			**env;
	char			*line;
	int				state;
	int				tmp;
	int				pid;
	int				cnt;
	int				exit;
}					t_mtest;

t_mtest				g_mtest;

char				**cpyarr(char **arr);
char				**sort_arrstr(char **arr);
int					dynamic_arr(char ***arr);
int					ft_arrlen(char **arr);

int					redir_all(t_cmd *cmd);
int					cmdredir(t_cmd *cmd);
void				cmds_redir(void);
int					run_cmds(void);

void				runfork(int *prev, int *next, int i);

int					ft_parser(t_mtest *mtest, char *s);

char				*get_env_str(char *s, int *p_i);
char				*join_env(t_mtest *mtest, char **p_olds, int *p_i);
int					loop_join_env(t_mtest *mtest, char **olds, int *p_i);

char				*get_str_cmd(char **p_s, int *p_i);

int					check_redirect(char *s);

char				**split_pipe(char *s);

char				*ft_getenv(char *key);

void				printarr(char **arr, char *what);
char				*add_chr(char *s, char c);
char				**add_strarr(char **arr, char *s);
char				*ft_strjoin_fr(char *s1, char *s2);
char				**cpyarr_add(char **arr, char **add);
char				**ft_subarr(char **arr, int start, int len);
int					ft_skpchr(char *s, int c);
int					ft_skpnchr(char *s, int c);
void				printarr(char **arr, char *what);

char				**cpyarr(char **arr);
char				**sort_arrstr(char **arr);
int					dynamic_arr(char ***arr);
int					ft_strcmp(char *s1, char *s2);
char				**add_strenv(char **env, char **arg);

char				**ft_split(char *s, char c);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *n);
char				*ft_strrchr(char *s, int c);
int					ft_strlcpy(char *dst, char *src, int dstsize);
char				*ft_strdup(char *s1);
int					ft_strcmp(char *s1, char *s2);

int					frarr(char **arr);

int					is_builtin(char *str);
void				builtin_chois(t_cmd *cmd);
int					ft_cd(char *path, char **env);
int					ft_echo(char **line, char *n);
void				ft_env(char **env);
void				ft_exit(t_cmd *cmd);
void				ft_export(char **env, char **str);
t_list				*ft_lst_make(char **line);
void				ft_lst_print(t_list **list);
t_list				*for_unset(t_list **list, char *key);
int					ft_lstadd_midle(t_list **lst, char *line);
void				ft_unset(char **env, char **str);
t_list				*ft_lstnew(char *line);
void				ft_lstclear(t_list **lst);
char				**convert_tkn(t_list *tkn);
t_list				*for_unset(t_list **list, char *key);
void				ft_lstdelone(t_list *lst);

int					check_incom_str(char *str);
int					ft_error(int i);
int					trim_space(char *str);

void				sigint_work(int sig);
void				sigquit_work(int sig);
void				ctrl_d(int sig);

#endif