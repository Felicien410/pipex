#include "pipex.h"

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (0);
}

char **get_after_variable_path (char **envp)
{
    int i = 0;
    char *path;
    while (envp[i])
    {
        if (ft_strstr(envp[i], "PATH="))
        {
            path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
            if (!path)
				perror("Error");
            return (ft_split(envp[i], ':'));
        }
        i++;
    }
    return (NULL);
}

char *get_paths(char **envp, char *command)
{
	char	**all_paths;
	char	*path;
	int		i;
	char	*part_path;

    all_paths = get_after_variable_path(envp);
    i = 0;
	while (all_paths[i])
	{
		part_path = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(part_path, command);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
    free_paths (all_paths);
    return (0);
}

void	execute(char *ag, char **envp)
{
    int  i;
    char **command;
    char *mypath;

    i = 0;
    command = ft_split(ag, ' ');
    mypath = get_paths(envp, command[0]);
    if (!mypath)
    {
        free_paths(command);
        perror ("erreur au niveau du chemin d'acces");
    }
    execve(mypath, command, envp);
    perror ("erreur avec execve");
    return;
}

void    free_paths (char **all_paths)
{
    int i;

	i  = 0;
	while (all_paths[i])
    {
		free(all_paths[i]);
        i++;
    }
	free(all_paths);
}