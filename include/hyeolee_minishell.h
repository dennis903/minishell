#ifndef HYEOLEE_MINISHELL_H
# define HYEOLEE_MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"
# include <termios.h>
# include <termcap.h>

# define BACKSPACE 127
# define LEFT_ARROW 4479771
# define RIGHT_ARROW 4414235
# define UP_ARROW 4283163
# define DOWN_ARROW 4348699


typedef struct  s_var
{
	char		quote;
	int			start_idx;
	int			end_idx;
	int			quote_idx;
	int			prev;
}               t_var;

typedef struct	s_quote
{
	char		quote;
	int			quote_idx;
}				t_quote;

typedef struct	s_options
{
	int			word;
	char		option;
}				t_options;

typedef struct  s_token
{
	char *token;
	int flag;
	char *cmd;
	char *argv;
	struct s_token *next;
}               t_token;

typedef struct	s_history
{
	char				*str;
	struct s_history	*next;
	struct s_history	*prev;
}				t_history;


// typedef struct	s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// 	char			*key;
// 	char			*value;
// }				t_list;


void			unset_list(t_list **head, char *str);
void			check_list(t_list *head);
void			init_list(t_list **head, char *envp[]);
void			export_list(t_list **head, char *str);
char			*upper_str(char *str);
void     		parsing_data(t_token **tokens, t_list **head);
char			*find_in_env(t_list **head, char *str);
void			add_list(t_list **head, char *str);
void			sub_list(t_list **head, char *str);
void			free_split(char **split);
t_list			*new_history(char *str);
#endif