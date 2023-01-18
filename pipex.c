#include "pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int		filein; //to check the reponse of "read"

	filein = open(argv[1], O_RDONLY, 0777); //argv[1] bcs we check the command (ex ; ls, wc ...)
	if (filein == -1)
	{
		perror("error child process");
		close (filein);
		exit(127);
	}
	dup2(fd[WRITE_END], STDOUT_FILENO); // we want fd[1] to be execve() stdout in order to get the stdout in
	//the parent process (with pipe), the parent will be able to make the command (ls..) on the result of child process 
	dup2(filein, STDIN_FILENO);// we want filein to be execve() input
	close(fd[READ_END]);
	execute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout;

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
	{
		perror("error parent process");
		close(fileout);
		exit(127);
	}
	dup2(fd[READ_END], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[WRITE_END]);
	execute(argv[3], envp);
}


int	main(int argc, char **argv, char **envp)
{
	int		fd[2]; //for pipe to get write and read entrees
	pid_t	pid1; //fork if pid=0-> child process , other dad

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

	// if (argc == 1 || argv == NULL)
	// {

	// }
	// int i =0;

	// while (envp[i])
    // {
	// 	printf("\n in fonction %s\n", ft_strstr(envp[i], "PATH"));
	// 	i++;
	// }

	// char **command;
    // char *mypath;

    // command = ft_split(argv[2], ' '); //????????
    // mypath = get_paths(envp, command[0]);
	// printf("----------\n");
	// printf("%s ceci est le mien ; \n", mypath);
	// printf("----------\n");
	// mypath = find_path(command[0], envp);
	// printf("----------\n");
	// printf("%s ceci m'est pas le mien ; \n", mypath);
	// printf("----------\n");

	// command = ft_split(argv[3], ' '); //????????
    // mypath = get_paths(envp, command[0]);
	// printf("----------\n");
	// printf("%s ceci est le mien ; \n", mypath);
	// printf("----------\n");
	// mypath = find_path(command[0], envp);
	// printf("----------\n");
	// printf("%s ceci m'est pas le mien ; \n", mypath);
	// printf("----------\n");
}