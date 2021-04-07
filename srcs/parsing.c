#include "../include/hyeolee_minishell.h"

int				ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[i] != '\0' || str2[i] != '\0'))
	{
		if (str1[i] != str2[i])
		{
			return (int)(str1[i] - str2[i]);
		}
		i++;
	}
	return (int)(str1[i] - str2[i]);
}

void			exception_export(char *str)
{
	char	*key;
	char	*value;
	int		i;

	i = -1;
	while (str[++i] != '=')
		;
	key = ft_substr(str, 0, i);
	if ((int)ft_strlen(str) == i)
	{
		value = ft_substr(str, i, ft_strlen(str));
		printf("declare -x %s\"%s\"\n", key, value);
	}
	else
	{
		value = ft_substr(str, i + 1, ft_strlen(str));
		printf("declare -x %s=\"%s\"\n", key, value);
	}
}

void			sort_row(char **s1, char **s2)
{
	char	*temp;

	if (ft_strcmp(*s1, *s2) >= 0)
	{
		temp = (*s1);
		(*s1) = (*s2);
		(*s2) = temp;
	}
}

void			sort_str(char **env)
{
	int		row;
	int		i;
	int		j;

	row = 0;
	while (env[row])
		row++;
	i = -1;
	while (++i < row)
	{
		j = 0;
		while (j < row - 1)
		{
			sort_row(&env[j], &env[j + 1]);
			j++;
		}
	}
	i = -1;
	while (++i < row)
		exception_export(env[i]);
}

void			change_pwd(t_list **head, char *str)
{
	t_list *temp;

	temp = *head;
	while (temp)
	{
		if (ft_strncmp(temp->key, "PWD", 3) == 0)
		{
			free(temp->value);
			temp->value = 0;
			temp->value = ft_strdup(str);
			return ;
		}
		temp = temp->next;
	}
}

char		**fill_env_data(t_list **head, char **env)
{
	t_list		*temp;
	int			idx;
	char		*str;
	char		*str_temp;

	idx = 0;
	temp = *head;
	env = (char **)malloc(sizeof(char *) * ft_lstsize(*head) + 1);
	env[ft_lstsize(*head) + 1] = NULL;
	while (temp)
	{
		str_temp = ft_strjoin(temp->key, "=");
		str = ft_strjoin(str_temp, temp->value);
		if (str_temp)
			free(str_temp);
		str_temp = 0;
		env[idx++] = ft_strdup(str);
		if (str)
			free(str);
		str = 0;
		temp = temp->next;
	}
	return (env);
}


char		*find_in_env(t_list **head, char *str)
{
	t_list *temp;
	char	*buf;

	
	temp = *head;
	while (temp)
	{
		if (ft_strncmp(temp->key, str, ft_strlen(str)) == 0)
		{
			return (temp->value);
		}
		temp = temp->next;
	}
	return (NULL);
}

void       parsing_data(t_token **tokens, t_list **head)
{
	char	buf[256];
	int		id;
	char	**split;
	char	**env;
	char	**argv;
	char	*address;

	env = fill_env_data(head, env);
	if ((*tokens)->argv != NULL)
	{
		argv = ft_split((*tokens)->argv, ' ');
	}
	ft_memset(buf, 0, 256);
	if (ft_strncmp((*tokens)->cmd, "echo", 4) == 0)
	{
		address = ft_strchr((*tokens)->argv, ' ');
		if (!address)
		{
			printf("\n");
			return ;
		}
		while (*address == ' ')
			address++;
		printf("%s\n", address);
	}
	else if (ft_strncmp((*tokens)->cmd, "cd", 2) == 0)
	{
		address = ft_strchr((*tokens)->argv, ' ');
		if (!address)
			address = find_in_env(head, "HOME");
		while (*address == ' ')
			address++;
		chdir(address);
		if (getcwd(buf, 256) != NULL)
		{
			change_pwd(head, buf);
			ft_memset(buf, 0, 256);
		}
	}
	else if (ft_strncmp((*tokens)->cmd, "unset", 5) == 0)
	{
		address = ft_strchr((*tokens)->argv, ' ');
		if (!address)
			return ;
		while (*address == ' ')
			address++;
		sub_list(head, address);
	}
	else if (ft_strncmp((*tokens)->cmd, "pwd", 3) == 0)
	{
		getcwd(buf, 256);
		printf("%s\n",buf);
		ft_memset(buf, 0, 256);
	}
	else if (ft_strncmp((*tokens)->cmd, "export", 6) == 0)
	{
		if (ft_strcmp((*tokens)->cmd, (*tokens)->argv) == 0)
		{
			sort_str(env);
			return ;
		}
		address = ft_strchr((*tokens)->argv, ' ');
		while (*address == ' ')
			address++;
		if (!*address)
		{
			sort_str(env);
			return ;
		}	
		// if (ft_strcmp((*tokens)->cmd, address) == 0)
		// {
		// 	printf("here?\n");
		// 	sort_str(env);
		// 	return ;
		// }
		add_list(head, address);
	}
	else if (ft_strncmp((*tokens)->cmd, "env", 3) == 0)
	{
		check_list(*head);
	}
	else
	{
		id = fork();
		if (id != 0)
		{
			wait(&id);
		}
		else if (id == 0)
		{
			char *path_str;
			path_str = find_in_env(head, "PATH");
			if (path_str)
			{
				split = ft_split(path_str, ':');
				int idx = 0;
				char *buf2;
				char *cmd;

				cmd = ft_strjoin("/", (*tokens)->cmd);
				while (split[idx])
				{
					char *retstr;
					execve(ft_strjoin(split[idx], cmd), argv, env);
					idx++;
				}
				printf("$>: %s: command not found\n", (*tokens)->cmd);
				exit(0);
			}
			else if (ft_strncmp((*tokens)->cmd, "ls", 2) == 0)
				printf("$>: ls: No such file or directory\n");
			else
				printf("$>: %s: command not found\n", (*tokens)->cmd);
			exit(0);
		}
	}
	// free_split(env);
}