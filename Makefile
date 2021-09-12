NAME = minishell
BDIR = ./buildin
CHKL = ./check_incom_string
PDIR = ./parser
SDIR = ./signal
UDIR = ./utils
MSRC = minishell.c
TSRC = ./parser/test/check_arg.c
SRCS =	minishell.c					\
		$(BDIR)/main_cmd.c			\
		$(BDIR)/run_cmdshell.c		\
		$(BDIR)/redir.c 			\
		$(BDIR)/libft.c				\
		$(BDIR)/list.c				\
		$(BDIR)/list_util.c			\
		$(BDIR)/list_util2.c		\
		$(BDIR)/builtin.c			\
		$(BDIR)/ft_cd.c				\
		$(BDIR)/ft_echo.c			\
		$(BDIR)/ft_env.c			\
		$(BDIR)/ft_export.c			\
		$(BDIR)/ft_pwd.c			\
		$(BDIR)/ft_unset.c			\
		$(BDIR)/ft_exit.c			\
		$(CHKL)/check_income_str.c	\
		$(CHKL)/str_check_func1.c	\
		$(CHKL)/str_check_func2.c	\
		$(CHKL)/str_check_func3.c	\
		$(PDIR)/ft_parser.c			\
		$(PDIR)/parse_env.c			\
		$(PDIR)/parse_cmd.c			\
		$(PDIR)/parse_check.c		\
		$(PDIR)/parse_split.c		\
		$(PDIR)/skip.c				\
		$(UDIR)/func_for_norm.c		\
		$(UDIR)/free.c				\
		$(UDIR)/sort.c				\
		$(UDIR)/len.c				\
		$(UDIR)/copy.c				\
		$(UDIR)/add.c				\
		$(UDIR)/ft_strjoin_fr.c		\
		$(UDIR)/signalc.c			\
		$(UDIR)/print.c				

OBJSRCS = $(SRCS:.c=.o)

LIB = ./libft/libft.a 

CFLAGS = -g -Ilibft -Ignl -I. -I/Users/$(USER)/.brew/Cellar/readline/8.1/include -lreadline -L/Users/$(USER)/.brew/Cellar/readline/8.1/lib/

all: $(NAME)

$(NAME): $(OBJSRCS) minishell.h
		$(MAKE) -C libft
		gcc $(CFLAGS) $(OBJSRCS) $(LIB) -o $(NAME)

%.o : %.c
			@$(CC) $(CFLAGS) -c $< -o $@ 2> /dev/null

clean :
	rm -rf $(OBJSRCS)
	$(MAKE) fclean -C libft
fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re