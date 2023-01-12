#include "pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		perror("error child process");
	dup2(fd[WRITE_END], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[READ_END]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		perror("error parent process");
	dup2(fd[READ_END], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[WRITE_END]);
	execute(argv[3], envp);
}


int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			perror("error with the pipe");
		pid1 = fork();
		if (pid1 == -1)
			perror("error with Fork");
		if (pid1 == 0)
			child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		parent_process(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("Bad arguments\n", 1);
		ft_putstr_fd("Please use with this composition -> ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}