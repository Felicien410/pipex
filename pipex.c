#include<unistd.h>
#include<stdlib.h>
#include <fcntl.h>

void    pipex(int f1, int f2)
{
    int   fd[2];
    pid_t parent;
    pipe(fd);
    parent = fork();
    if (parent < 0)
    {
        close(fd[0]);
        close(fd[1]);
        return (perror("Fork: "));
    }
    if (!parent) // if fork() returns 0, we are in the child process
        child_process(f1, cmd1);
    else
        parent_process(f2, cmd2);
}

int child_process(f1, cmd1)
{
// add protection if dup2() < 0
// dup2 close stdin, f1 becomes the new stdin
dup2(fd[1], STDOUT_FILENO); // we want end[1] to be execve() stdout
close(fd[0]);
execve(cmd1, args1, NULL);
perror ("error child process");
exit(EXIT_FAILURE);
}




int main(int ac, char **ag, char **envp)
{
     int f1;
     int f2;
     f1 = open(ag[1], O_RDONLY);
     f2 = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
     if (f1 < 0 || f2 < 0)
          return (-1);
     pipex(f1, f2, ag, envp);
     return (0);
}