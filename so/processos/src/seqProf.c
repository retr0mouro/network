#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void){
	int i, status;
	pid_t pid;
	for(i = 0;i != 10;i++){
		if(fork() == 0) { /* filho */
			printf("filho %d: pid = %d, ppid = %d\n",i,getpid(),getppid());
			return i + 1; /* => _exit(i+1) */
		}
		/* pai */
		//wait(NULL);
		pid = wait(&status);
		if(WIFEXITED(status))
			printf("pai %d: filho %d, %d\n",getpid(),pid,WEXITSTATUS(status));

	
		
		else {
			printf("pai %d: filho morreu sem ser com exit", getpid());
		}
	}
	return 0;
}
