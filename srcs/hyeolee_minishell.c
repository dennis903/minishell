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

void			quote_init(t_quote *quote)
{
	quote->quote = 0;
	quote->quote_idx = 0;
}

void			option_init(t_options *option)
{
	option->word = -1;
	option->option = 0;
}

t_token			*token_lstlast(t_token *lst)
{
	t_token *new;

	if (!lst)
		return (0);
	new = lst;
	while (new->next)
		new = new->next;
	return (new);
}

void			token_add_back(t_token **tokens, t_token *new)
{
	t_token *lstnew;

	if (!tokens || !new)
		return ;
	if (!*tokens)
	{
		*tokens = new;
		return ;
	}
	lstnew = token_lstlast(*tokens);
	lstnew->next = new;
	new->next = NULL;
}

void			quote_check(char ch, t_quote *quote)
{
	if (quote->quote)
	{
		if (quote->quote == ch)
			quote->quote = 0;
	}
	else if (!quote->quote)
		quote->quote = ch;
}



int				quote_error_check(char *line)
{
	int			i;
	t_quote		quote;

	i = 0;
	quote_init(&quote);
	while (line[i])
	{
		if (is_in_char(line[i], "\'\""))
			quote_check(line[i], &quote);
		i++;
	}
	if (quote.quote)
		return (0);
	return (1);
}

int				option_error_check(char *line)
{
	t_options	option;
	t_quote		quote;

	option_init(&option);
	quote_init(&quote);
	while (*line)
	{
		if (is_in_char(*line, "\'\""))
			quote_check(*line, &quote);
		if (!is_space(*line))
			option.word = 1;
		if (is_in_char(*line, ";|"))
		{
			if (option.word == 0)
				return (0);
			else
			{
				option.option = *line;
				option.word = 0;
			}
		}
		line++;
	}
	return (1);
}

t_token			*new_token(char *str)
{
	t_token	*new;

	if (!str)
		return (0);
	new = (t_token *)malloc(sizeof(t_token) * 1);
	if (!new)
		return (0);
	new->token = ft_strdup(str);
	new->next = 0;
	return (new);
}

void			tokenization(char *line, t_var *var, t_token**tokens)
{
	int			i;
	int			token_len;
	t_quote		quote;
	char		*temp;

	token_len = 0;
	i = 0;
	quote_init(&quote);
	line = ft_strtrim(line, " ");
	while (line[i])
	{
		if (is_in_char(line[i], "\'\""))
			quote_check(line[i], &quote);
		if ((quote.quote == 0 && is_in_char(line[i + 1], ";|"))
		|| !line[i + 1])
		{
			temp = ft_substr((line + i) - token_len, 0, token_len + 1);
			token_add_back(tokens, new_token(temp));
			token_len = 0;
		}
		token_len++;
		i++;
	}
}


int				check_syntax_error(char *line)
{
	if (!quote_error_check(line))
	{
		write(1, "syntax_error\n", ft_strlen("syntax_error"));
		return (0);
	}
	if (!option_error_check(line))
	{
		printf("why\n");
		write(1, "syntax_error\n", ft_strlen("syntax_error"));
		return (0);
	}
	return (1);
}

int				parse_minishell(char *line, t_list **head)
{
	t_token		*tokens;
	t_var		var;
	int			i;

	tokens = NULL;
	i = 0;
	if (!check_syntax_error(line))
		return (0);
	tokenization(line, &var, &tokens);
	while (tokens)
	{
		printf("%s\n", tokens->token);
		tokens = tokens->next;
	}
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
