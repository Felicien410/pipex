#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>


// void run_pipe ( void )
// {
//     int const READ_END = 0;
//     int const WRITE_END = 1;
//     pid_t   child = -1;
//     char *cmd1 = NULL;
//     char *cmd2 = NULL;
//     char *args1[3];
//     char *args2[3];
//     int pdes[2];

//     cmd1 = "/bin/ls";
//     args1[0] = cmd1;
//     args1[1] = "-l";
//     args1[2]= NULL;

//     cmd2 = "/bin/cat";
//     args2[0] = cmd2;
//     args2[1] = "-e";
//     args1[2]= NULL;

//     pipe( pdes );

//     printf("%s\n" , cmd1);
//     printf("%s\n" , args1[0]);
//     printf("%s\n" , args1[1]);
//     printf("%s\n" , args1[2]);
//     printf("%s\n" , cmd2);
//     printf("%s\n" , args2[0]);
//     printf("%s\n" , args2[1]);
//     printf("%s\n" , args2[2]);

//     child = fork();
//     if (child == -1)
//     {
//         close (pdes[0]);
//         close (pdes[1]);
//         perror ("error with fork");
//         return;
//     }

//     if (child == 0) //child
//     {
//         dup2(pdes[WRITE_END], STDOUT_FILENO);
//         close(pdes[READ_END]);
//         execve(cmd1, args1, NULL);
//         perror ("error with child prcess");
//         return;
//     }

//     else 
//     {
//         dup2 (pdes[READ_END], STDIN_FILENO);
//         close(pdes[WRITE_END]);
//         wait(NULL);
//         execve( cmd2, args2, NULL);
//         return;
//     }
// }

// int main()
// {
//     pid_t child = -1;

//     child = fork();
//     if (child == -1)
//     {
//         perror (" pb main fork ");
//         return 0;
//     }
//     if (child == 0)
//     {
//         run_pipe();
//         perror (" pb run pipe in main");
//         return 0;
//     }
//     wait ( NULL );

//     return 0;
// }

int main(int ac, char **ag, char **envp)
{
    int i = 0;
    while (envp[i])
    {
        printf("%s\n\n", envp[i]);
        i++;
    }
    //  int f1;
    //  int f2;
    //  f1 = open(ag[1], O_RDONLY);
    //  f2 = open(ag[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
    //  if (f1 < 0 || f2 < 0)
    //       return (-1);
    //  pipex(f1, f2, ag, envp);
    //  return (0);
}