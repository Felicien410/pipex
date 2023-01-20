#include "pipex.h"

// ./pipex infile "ls -l" "wc -l" outfile

void	child_process(char **argv, char **envp, int *fd)
{
	int		infile; //to check the reponse of "read"
	
	infile = open(argv[1], O_RDONLY); //argv[1] bcs we check the file (infile)
	if (infile < 0)
	{
		perror("error child process");
		close (infile);
		exit(127);
	}
	if (dup2(fd[WRITE_END], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	} // we want fd[1] to be execve() stdout in order to get the stdout in
	//the parent process (with pipe), the parent will be able to make the command (ls..) on the result of child process 
	if (dup2(infile, STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd[READ_END]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fileout < 0)
	{
		perror("error parent process");
		close(fileout);
		exit(127);
	}
	if (dup2(fd[READ_END], STDIN_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	if (dup2(fileout, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	close(fd[WRITE_END]);
	execute(argv[3], envp);
}


int	main(int argc, char **argv, char **envp)
{
	int		fd[2]; //for pipe to get write and read entrees
	pid_t	pid1; //fork if pid=0-> child process , other dad

	int	infile;
	int	outfile;

	if (argc == 5) //./pipex file1 cmd1 cmd2 file2
	{
		if (pipe(fd) == -1)
			perror("error with the pipe");
		pid1 = fork();
		if (pid1 == -1)
			perror("error with Fork");
		if (pid1 == 0)
			child_process(argv, envp, fd);
		waitpid(pid1, NULL, 0); //command wich wait that the child process to end
		parent_process(argv, envp, fd); 
	}
	else
	{
		ft_putstr_fd("Bad arguments\n", 1);
		ft_putstr_fd("Please use with this composition -> ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
		exit(EXIT_FAILURE);
	}
}