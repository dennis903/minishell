#include "minishell.h"

void			signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putstr("\b\b  \b\b\n");
		ft_putstr("minishell$> ");
	}
}

char			**tokenization(char *line)
{
	char		**tokens;
	char		*token;

	while (*line)
	{
		line++;
	}
}

void			parse_minishell(char *line)
{
	t_list		**tokens;

	tokens = tokenization(line);
}

int				main(int argc, char *argv[], char *envp[])
{
	char		*line;
	char		*new_line;

	while (1)
	{
		ft_putstr("minishell$> ");
		signal(SIGINT, signal_handler);
		while (!get_next_line(0, &line))
			;
		if (ft_strcmp(line, "exit") == 0)
			exit(0);
		new_line = ft_strdup(line);
		free(line);
		parse_minishell(new_line);
	}
	return (0);
}
