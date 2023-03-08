#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>
#include"libft/libft.h"

void    ft_putstr_fd(char *s, int fd);
char    *ft_strstr(char *str, char *to_find);
char    **get_after_variable_path (char **envp);
char    *get_paths(char **envp, char *command);
void    realisation(char *ag, char **envp);
void    free_paths (char **all_paths);
void    child_process(char **argv, char **envp, int *fd);
void    parent_process(char **argv, char **envp, int *fd);
char    *find_path(const char	*big, const char *little, size_t len);

# ifndef READ_END
#  define READ_END 0
# endif

# ifndef WRITE_END
#  define WRITE_END 1
# endif

#endif