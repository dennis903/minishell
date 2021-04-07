#include "../include/hyeolee_minishell.h"

void			signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr_fd("\b\b  \b\b\n", 1);
		ft_putstr_fd("minishell$> ", 1);
	}
	if (signo == SIGTERM)
	{
		exit(0);
	}
}

int				is_in_char(char ch, char *str)
{
	while(*str)
	{
		if (ch == *str)
			return (1);
		str++;
	}
	return (0);
}

int				is_space(char ch)
{
	if (ch >= 9 && ch <= 13)
		return (1);
	if (ch == ' ')
		return (1);
	return (0);
}

t_list			*tokenization(char *line, t_var *var)
{
	int			i;
	int			token_len;
	char		*temp;
	t_list		*tokens;

    token_len = 0;
	i = 0;
	while (is_space(line[i]) || !line[i])
		i++;
	while(line[i])
	{
		if (var->quote == 0 && is_in_char(line[i], "|;"))
		{
			token_len = 1;
			temp = ft_substr(&line[i], 0, 1);
			ft_lstadd_back(&tokens, ft_lstnew(temp));
			token_len = 0;
			free(temp);
		}
		if (is_in_char(line[i], "\'\""))
		{
			if (var->quote && line[i] == var->quote)
				var->quote = 0;
			else if (var->quote == 0)
				var->quote = line[i];
		}
		token_len++;
		i++;
	}
}

int				parse_minishell(char *line, t_list **head)
{
	t_list		*tokens;
	int			i;
	t_var		var;

	i = 0;
	tokens = tokenization(line, &var);
	return (0);
}

int				main(int argc, char *argv[], char *envp[])
{
	char		*line;
	char		*new_line;
	t_list		*head;

	head = NULL;
	init_list(&head, envp);
	while (1)
	{
		ft_putstr_fd("minishell$> ", 1);
		signal(SIGINT, signal_handler);
		while (get_next_line(0, &line) > 0)
			break;
		if (ft_strncmp(line, "exit", 4) == 0)
			exit(0);
		new_line = ft_strdup(line);
		free(line);
		if (parse_minishell(new_line, &head) == -1)
			printf("error\n");
	}
	return (0);
}
