#include "../include/hyeolee_minishell.h"
#include <string.h>
char		*find_path(t_list **head)
{
	t_list *temp;
	char	*buf;

	temp = *head;
	while (temp)
	{
	
		if (ft_strncmp(temp->key, "PATH", 4) == 0)
		{
			return (temp->value);
		}
		temp = temp->next;
	}
	return (NULL);
}

void	unset_list(t_list **head, char *str)
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

void	check_list(t_list *head)
{
	t_list *temp;

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

void	export_list(t_list **head, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[0] != '=' && str[i] == '=')
		{
			ft_lstadd_back(head, ft_lstnew(str));
			printf("here?\n");
			return ;
		}
		i++;
	}
}

// int main(int argc, char *argv[], char *envp[])
// {
// 	t_list *head;
// 	int len;
// 	char *str;
// 	str = "key=value";
	
// 	head = NULL;
// 	init_list(&head, envp);

// 	check_list(head);
	
// 	export_list(&head, str);

// 	unset_list(&head, "hi1");

// 	check_list(head);
// // 
// 	int fd;
// 	char *line;
// 	int id;
// 	int stay;
// 	int i = 0;
// 	fd = 0;
// 	int ret;
// 	(void)argv;

// 	write(1, "$>", 2);
// 	while ((ret = get_next_line(fd, &line)) > 0)
// 	{
// 		if (strncmp(line, "ls", 2) == 0)
// 		{
// 			id = fork();
// 			if (id != 0)
// 			{
// 				wait(&id);
// 			}
// 			else if (id == 0)
// 			{
// 				char *path_str;
// 				char **split;
// 				char *arge[] = {"ls", NULL};
// 				int idx;
// 				char *joinstr;
// 				idx = 0;
// 				path_str = find_path(&head);
// 				split = ft_split(path_str, ':');
// 				chdir("srcs");
// 				while (split[idx])
// 				{
// 					// printf("%s\n",split[idx]);
					
// 					joinstr = ft_strjoin(split[idx], "/a.out");
// 					printf("%s\n", joinstr);
// 					execve(joinstr ,arge, NULL);
// 					idx++;
// 				}
// 				execve("a.out", NULL, NULL);
// 				printf("$> command not found: %s\n", "asdqwd");
// 				exit(0);
// 			}
// 		}

// 		if (strncmp(line, "cat ", 4) == 0)
// 		{
// 			char *str;
// 			int a;
// 			char *l;
// 			str = strchr(line, ' ');
// 			a = open(str + 1, O_RDONLY);
// 			while (get_next_line(a, &l) > 0)
// 			{
// 				printf("%s\n", l);
// 			}
// 			printf("%s\n", l);
// 		}
// 		write(1, "$>", 2);
// 	}
// 	return (0);
// }




// #include <stdio.h>
// #include <string.h>
// #include <errno.h>
// #include <dirent.h>
// #include <unistd.h>
 
// # define DIRTYPE_TO_STRING(X)                        \
//                 ((X) == DT_DIR ? "directory" :        \
//                  (X) == DT_REG ? "regular file" :    \
//                                   "unknown file")
 
// int main(void)
// {
//     char path[256];
//     memset(path, 0, 256);
//     if (getcwd(path, 256) == NULL)
//     {
//         printf("%s", strerror(errno));
//         return (-1);
//     }
//     printf("Before chdir, current path : %s\n", path);
 
//     if (chdir("..") == -1)
//     {
//         printf("%s", strerror(errno));
//         return (-1);
//     }
//     if (getcwd(path, 256) == NULL)
//     {
//         printf("%s", strerror(errno));
//         return (-1);
//     }
//     printf("after chdir, current path : %s\n", path);
// 	if (chdir("..") == -1)
//     {
//         printf("%s", strerror(errno));
//         return (-1);
//     }
// 	if (getcwd(path, 256) == NULL)
//     {
//         printf("%s", strerror(errno));
//         return (-1);
//     }
// 	printf("after chdir, current path : %s\n", path);
// 	if (chdir("/bin") == -1)
//     {
//         printf("%s", strerror(errno));
//         return (-1);
//     }
// 	if (getcwd(path, 256) == NULL)
//     {
//         printf("%s", strerror(errno));
//         return (-1);
//     }
// 	printf("after chdir, current path : %s\n", path);
 
//     DIR *p_dir;
//     if ((p_dir = opendir(path)) == NULL)
//     {
//         printf("fail opendir()\n");
//         return (-1);
//     }
 
//     struct dirent *dir_ent;
//     while ((dir_ent = readdir(p_dir)) != NULL)
//     {
//         printf("*****************************************\n");
//         printf("d_name : %s\n", dir_ent->d_name);
//         printf("d_type : %s\n", DIRTYPE_TO_STRING(dir_ent->d_type));
//         printf("*****************************************\n");
//     }
 
//     if (closedir(p_dir) == -1)
//     {
//         printf("fail closedir()\n");
//         return (-1);
//     }
 
//     return (0);
// }
