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

char		*find_in_env(t_list **head, char *str)
{
	t_list *temp;
	char	*buf;

	
	temp = *head;
	while (temp)
	{
		if (ft_strncmp(temp->key, str, ft_strlen(str)) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
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
		if (!is_space(*line) && !is_in_char(*line, ";|"))
			option.word = 1;
		if (is_in_char(*line, ";|"))
		{
			if (option.word == -1)
			{
				return (0);
			}
			else if (!quote.quote)
			{
				option.option = *line;
				option.word = -1;
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

int				is_seperate_token(char *line, int i, t_quote quote)
{
	if ((!quote.quote && is_in_char(line[i + 1], "|;"))
	|| !line[i + 1])
		return (1);
	return (0);
}

// int				is_variation(char *token, int i, t_quote quote)
// {
// 	if (quote.quote == '\'')
// 		return (0);
// 	if (!token[i - 1] && token[i - 1] == '\\')
// 		return (0);
// 	return (1);
// }

char			*change_to_constant(char *token, int *var_len, t_list **head)
{
	char		*temp;
	char		*temp2;
	t_list		*tmp_list;
	char		buf[2];
	char		*value;

	(*var_len)++;
	buf[1] = 0;
	if (is_space(token[*var_len]))
	{
		temp2 = ft_strdup("");
		return (temp);
	}
	while (!is_space(token[*var_len]) && token[*var_len] != 0)
	{
		buf[0] = token[*var_len];
		temp = ft_strjoin(temp2, buf);
		(*var_len)++;
	}
	printf("%s\n", temp);
	tmp_list = *head;
	while (tmp_list)
	{
		value = find_in_env(head, temp);
		tmp_list = tmp_list->next;
	}
	return (value);
}

char			*remove_quote(char *token, int *var_len, t_list **head)
{
	char		quote_check;
	int			i;
	int			idx_len;
	char		*ret;
	char		buf[2];

	quote_check = token[i];
	i = 1;
	buf[1] = 0;
	ret = ft_strdup("");
	printf("%s\n",token);
	while (token[i] != quote_check)
	{
		idx_len = 0;
		if (quote_check == '\"' && token[i] == '$' &&
		(i - 1 >= 0 && token[i - 1] != '\\'))
			ret = ft_strjoin(ret, change_to_constant(&token[i], &idx_len, head));
		else
		{
			buf[0] = token[i];
			ret = ft_strjoin(ret, buf);
			idx_len = 1;
		}
		i += idx_len;
	}
	return (ret);
}

char			*manufacture_token(char *token, t_list **head)
{
	char		*ret;
	char		buf[2];
	t_quote		quote;
	int			i;
	int			var_len;

	i = 0;
	ret = 0;
	buf[1] = 0;
	quote_init(&quote);
	if (!ret)
		ret = ft_strdup("");
	while (token[i])
	{
		var_len = 0;
		if (is_in_char(token[i], "\'\""))
			ret = ft_strjoin(ret, remove_quote(&token[i], &var_len, head));
		else if (token[i] == '$')
			ret = ft_strjoin(ret, change_to_constant(&token[i], &var_len, head));
		else
		{
			buf[0] = token[i];
			ft_strjoin(ret, buf);
			var_len = 1;
		}
		i += var_len;
	}
	return (ret);
}

void			erase_blank(t_token **tokens)
{
	char		*temp;
	t_token		*tmp_token;

	tmp_token = (*tokens);
	while (tmp_token)
	{
		temp = ft_strtrim(tmp_token->token, " ");
		free(tmp_token->token);
		tmp_token->token = ft_strdup(temp);
		free(temp);
		tmp_token = tmp_token->next;
	}
}

void			manufacture_cmdline(t_token **tokens, t_var *var, t_list **head)
{
	t_token		*temp;
	char		*tmp_str;
	int			i;

	i = 0;
	temp = *tokens;
	while (temp)
	{
		tmp_str = manufacture_token(temp->token, head);
		temp->token = ft_strdup(tmp_str);
		free(tmp_str);
		temp = temp->next;
		i++;
	}
}

void			get_cmdline(t_token **tokens, t_var *var, t_list **head)
{
	erase_blank(tokens);
	manufacture_cmdline(tokens, var, head);
}


void			big_tokenizer(char *line, t_var *var, t_token**tokens)
{
	int			i;
	int			token_len;
	t_quote		quote;
	char		*temp;

	token_len = 0;
	i = 0;
	quote_init(&quote);
	while (is_space(line[i]))
		i++;
	while (line[i])
	{
		if (is_in_char(line[i], "\'\""))
			quote_check(line[i], &quote);
		if (!quote.quote && is_in_char(line[i], "|;"))
		{
			temp = ft_substr(&line[i], 0, 1);
			token_add_back(tokens, new_token(temp));
			token_len = 0;
		}
		else if (is_seperate_token(line, i, quote))
		{
			temp = ft_substr((line + i) - token_len, 0, token_len + 1);
			token_add_back(tokens, new_token(temp));
			token_len = 0;
		}
		else
			token_len++;
		i++;
	}
}


int				check_syntax_error(char *line)
{
	if (!quote_error_check(line))
		return (0);
	if (!option_error_check(line))
		return (0);
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
		return (-1);
	big_tokenizer(line, &var, &tokens);
	get_cmdline(&tokens, &var, head);
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
