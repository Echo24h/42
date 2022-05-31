#include "microshell.h"

void    free_strs(char **strs)
{
    int i;

    if (!strs)
        return ;
    i = 0;
    while (strs[i])
        free(strs[i++]);
    free(strs);
}

int ft_strlen(char *str)
{
    int i;

    if (!str)
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    print_error(char *msg)
{
    write(2, "error: ", 7);
    write(2, msg, ft_strlen(msg));
}

int strslen(char **strs)
{
    int i;

    if (!strs)
        return (0);
    i = 0;
    while (strs[i])
        i++;
    return (i);
}

void    print_strs(char *pfx, char **strs)
{
    printf("%s\n", pfx);
    if (!strs)
    {
        printf("NULL\n");
        return ;
    }
    while (*strs)
    {
        printf("-> %s\n", *strs);
        strs++;
    }
}

char    *ft_strdup(char *str)
{
    int     i;
    char    *new;

    new = malloc(sizeof(char) + (ft_strlen(str) + 1));
    i = 0;
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

int builtin_cd()
{
    return (0);
}

char    **get_cmds(char **av)
{
    int     i;
    char    **cmds;

    i = 0;
    while (av[i] && strcmp(av[i], ";"))
        i++;
    cmds = malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (av[i] && strcmp(av[i], ";"))
    {
        cmds[i] = ft_strdup(av[i]);
        i++;
    }
    cmds[i] = NULL;
    return (cmds);
}

char    **get_args(char **cmds)
{
    int     i;
    char    **args;

    i = 0;
    while (cmds[i] && strcmp(cmds[i], "|"))
        i++;
    args = malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (cmds[i] && strcmp(cmds[i], "|"))
    {
        args[i] = ft_strdup(cmds[i]);
        i++;
    }
    args[i] = NULL;
    return (args);
}

int exec_cmd(char **args, char **env)
{
    return (0);
}

int exec_cmds(char **cmds, char **env)
{
    char    **args;
    int     i;
    int     pipe_fd;

    i = 0;
    while (cmds[i])
    {
        args = get_args(&cmds[i]);
        i += strslen(args);
        if (!strcmp(cmds[i], "|"))
        {
            if (pipe(pipe_fd) == 1)
            {
                
            }
            // open pipe, fork and exec
        }
        else
        {
            // 
        }
        printf("args[i]: %s\n", cmds[i]);
        //exec_cmd(args, env);
        print_strs("args", args);
        free_strs(args);
        printf("i: %d\n", i);
    }
    return (0);
}

int main(int ac, char *av[], char **env)
{
    int     i;
    char    **cmds;

    i = 1;
    while (av[i])
    {
        if (!strcmp(av[i], ";"))
        {
            i++;
            continue ;
        }
        cmds = get_cmds(&av[i]);
        i += strslen(cmds);
        print_strs("cmd", cmds);
        exec_cmds(cmds, env);
        free_strs(cmds);
    }
    return (0);
}
