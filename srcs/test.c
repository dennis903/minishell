#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <unistd.h>

 
 
# define DIRTYPE_TO_STRING(X)                        \
                ((X) == DT_DIR ? "directory" :        \
                 (X) == DT_REG ? "regular file" :    \
                                  "unknown file")
 
int main(int argc, char *argv[], char *envp[])
{

    char path[256];
    memset(path, 0, 256);
    if (getcwd(path, 256) == NULL)
    {
        printf("%s", strerror(errno));
        return (-1);
    }
    printf("Before chdir, current path : %s\n", path);
 
    if (chdir("..") == -1)
    {
        printf("%s", strerror(errno));
        return (-1);
    }
    if (getcwd(path, 256) == NULL)
    {
        printf("%s", strerror(errno));
        return (-1);
    }
    char *arge[] = {"ls", "-la", NULL};
    execve("/bin/ls", arge, NULL);
    printf("after chdir, current path : %s\n", path);
 
    // DIR *p_dir;
    // if ((p_dir = opendir(path)) == NULL)
    // {
    //     printf("fail opendir()\n");
    //     return (-1);
    // }
 
    // struct dirent *dir_ent;
    // while ((dir_ent = readdir(p_dir)) != NULL)
    // {
    //     printf("*****************************************\n");
    //     printf("d_name : %s\n", dir_ent->d_name);
    //     printf("d_type : %s\n", DIRTYPE_TO_STRING(dir_ent->d_type));
    //     printf("*****************************************\n");
    // }
 
    // if (closedir(p_dir) == -1)
    // {
    //     printf("fail closedir()\n");
    //     return (-1);
    // }
 
    return (0);
}