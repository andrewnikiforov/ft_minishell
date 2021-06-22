# ifndef MINISHELL_H
# define MINISHELL_H

#include <fcntl.h>
#include <sys/ioctl.h>
#include <sched.h>
#include <sys/mman.h>
#include <signal.h>
#include <term.h>
#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
#include "libft/libft.h"
#include "readline/history.h"
#include "readline/readline.h"

typedef struct s_itrr
{
	int			i;
	int			j;
}				t_itrr;

typedef struct s_prs
{
	int			shld;	// Flag for '\'
	int			oqut;	// Flag for '
	int			dqut;	// Flag for "
	int			closeq;	// Последовательность закрытия '"'" <- Error 
}				t_prs;

typedef struct s_env
{
	char		**def;
	char		**srtdef;
	char		**new_env;
	char		**srt_new_env;
}				t_env;

typedef struct s_mshll
{
	int			exit;
	int			err;	// Для ошибок
	char		*cmd;	// Записывается название комманды echo, etc...
	char		*opt;	// Записываются опции для комманды ls -la (Записывается la)
	char		**arg;	// Записываются аргументы для комманды, если есть grep p (p является аргументом)
	char		**cmds;
	char		**env;	// Что-бы выебываться, что ты тоже перезаписываешь env который тебе передают с main
	char		**sort_defenv;
	char		**nenv;
	char		**sort_nenv;
	int			in;		// хз
	int			out;	// хз
	int			type;
	t_prs		*prs;	// Структура для удобочитаемости и для раздиления логики :) Миф парного программирования 
}				t_mshll;

int	init_mshll(t_mshll *mshll);
int	init_prs(t_prs *prs);
char	**cpyarr(char **arr);
char	**sort_arrstr(char **arr);
int		dynamic_arr(char ***arr);
#endif