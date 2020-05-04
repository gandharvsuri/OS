#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
	int pid, pid1, pid2;

    pid = fork();

    if (pid == 0)
    {
		sleep(3);
        printf("1st child with pid %d and ppid %d\n", getpid(), getppid());
	}
	else
    {
		pid1 = fork();
		if (pid1 == 0){
			sleep(2);
			printf("2nd child with pid %d and ppid %d\n",getpid(), getppid());
		}
		else{
			pid2 = fork();
			if (pid2 == 0){
				printf("3rd child with pid %d and ppid %d\n",getpid(), getppid());
			}

		}
	}
	waitpid(pid,NULL,0);  

	return 0;
}
