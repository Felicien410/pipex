#include "pipex.h"

char	*find_path(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (0);
}


char **get_after_variable_path (char **envp)
{
    int i = 0;
    char *path;
    while (envp[i])
    {
        if (find_path(envp[i], "PATH", 4))
        {
            path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
            if (!path)
			{
				perror("Error");
				return (NULL);
			}
            return (ft_split(path, ':'));
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

void	realisation(char *ag, char **envp)
{
    char **command;
    char *mypath;

    command = ft_split(ag, ' ');
    mypath = get_paths(envp, command[0]);
    if (!mypath)
    {
        free_paths(command);
        perror ("erreur au niveau du chemin d'acces");
		exit(EXIT_FAILURE);
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