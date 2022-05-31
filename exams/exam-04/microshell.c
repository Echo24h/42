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

void    exit_error(char *pfx, char *cmd)
{
    write(2, "error: ", 7);
    write(2, pfx, ft_strlen(pfx));
    if (cmd)
    {
        write(2, " ", 1);
        write(2, cmd, ft_strlen(cmd));
    }
    write(2, "\n", 1);
    exit(1);
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

void    exec_last_cmd(char **args, char **env, int fd_in)
{
    int pid;

    pid = fork();
    if (pid == -1)
        exit_error("fatal", NULL);
    if (!pid)
    {
        dup2(fd_in, 0);
        close(fd_in);
        if (execve(args[0], args, env) == -1)
            exit_error("cannot execute", args[0]);
        exit(1);
    }
}

void     exec_cmd(char **args, char **env, int fd_in)
{
    int pid;
    int pipe_fd[2];

    if (pipe(pipe_fd) == -1)
        exit_error("fatal", NULL);
    pid = fork();
    if (pid == -1)
        exit_error("fatal", NULL);
    if (!pid)
    {
        close(pipe_fd[0]);
        dup2(fd_in, 0);
        close(fd_in);
        dup2(pipe_fd[1], 1);
        close(pipe_fd[1]);
        if (execve(args[0], args, env) == -1)
            exit_error("cannot execute", args[0]);
        exit(1);
    }
    close(pipe_fd[1]);
    dup2(pipe_fd[0], fd_in);
    close(pipe_fd[0]);
}

int exec_cmds(char **cmds, char **env)
{
    char    **args;
    int     i;
    int     fd_in;

    fd_in = 0;
    i = 0;
    while (cmds[i])
    {
        args = get_args(&cmds[i]);
        i += strslen(args);
        if (!strcmp(cmds[i], "|"))
        {
            exec_last_cmd(args, env, fd_in);
        }
        else
        {
            exec_cmd(args, env, fd_in);
        }
        while (waitpid(-1, NULL, 0) > 0) ;
        free_strs(args);
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
