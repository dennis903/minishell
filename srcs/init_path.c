#include "../include/hyeolee_minishell.h"

char		*upper_str(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] < 'z')
		{
			str[i] = 'a' - 27;
		}
		i++;
	}
	return (str);
}

t_list			*new_history(char *str)
{
	t_list	*new;

	if (!str)
		return (0);
	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new)
		return (0);
	new->history = str;
	return (new);
}

void		unset_list(t_list **head, char *str)
{
	t_list *temp;
	t_list *temp2;
	t_list *prev;

	temp = *head;
	while (temp)
	{
		if ((ft_strncmp(temp->key, str, ft_strlen(temp->key)) == 0))
		{
			temp2 = temp->next;
			prev->next = temp2;
			ft_lstdelone(temp, free);
		}
		prev = temp;
		temp = temp->next;
	}
}

void	free_split(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	sub_list(t_list **head, char *str)
{
	char **split;
	int i;
	
	split = ft_split(str, ' ');
	i = 0;
	while (split[i])
	{
		unset_list(head, split[i]);
		i++;
	}
	i = 0;
	free_split(split);
}

void	check_list(t_list *head)
{
	while (head)
	{
		if (head->key)
		{
			printf("%s%c%s\n",head->key, '=', head->value);
		}
		head = (head)->next;
	}
}


void	init_list(t_list **head, char *envp[])
{
	int			i;

	i = 0;
	while (envp[i])
	{
		ft_lstadd_back(head, ft_lstnew(envp[i]));
		i++;
	}
}

void	change_value(t_list **head, char *str, int flag, char *value)
{
	t_list *temp;

	temp = *head;
	while (temp)
	{
		if (ft_strncmp(temp->key, str, ft_strlen(str)) == 0 && flag == 0)
		{
			temp->value = ft_strdup(" ");
			return ;
		}
		else if (ft_strncmp(temp->key, str, ft_strlen(str)) == 0 && flag == 1)
		{
			temp->value = ft_strdup(value);
			return ;
		}
		temp = temp->next;
	}
}
// a=b a == b abc = qwe qwe=e qwe========qwe
void	add_list(t_list **head, char *str)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	split = ft_split(str, ' ');
	while (split[i])
	{
		export_list(head, split[i]);
		i++;
	}
	free_split(split);
}

void	export_list(t_list **head, char *str)
{
	int		i;
	char	*temp;
	char	*value;
	int		save;
	int		flag;

	flag = 0;
	i = -1;
	save = 0;
	while (str[++i])
	{
		if ((flag == 0 && str[i] == '=') || (flag == 0 && str[i] >= '0' && str[i] <= '9'))
		{
			temp = ft_substr(str, 0, ft_strlen(str));
			printf("$>: export: '%s': not a valid identifier\n", temp);
			return ;
		}
		if (str[i] == '=' && save == 0)
			save = i;
		flag = 1;
	}
	i = -1;
	while (str[++i])
	{
		if (str[0] != '=' && str[i] == '=')
		{
			temp = ft_substr(str, 0, save);
			if (!(find_in_env(head, temp)))
				ft_lstadd_back(head, ft_lstnew(str));
			else
			{
				if (ft_strlen(str) == save)
					change_value(head, temp, 0, NULL);
				else
				{
					value = ft_substr(str, save + 1, ft_strlen(str));
					change_value(head, temp, 1, value);
				}
			}
			return ;
		}
	}
}