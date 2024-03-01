#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>


int main(int argc,char ** argv){
	pid_t son;
	int status = 10;
       	switch((son = fork())){
		case -1: // erro
			perror("fork()");
			_exit(1);
			break;
		case 0: // filho	
			printf("Sou um filho com pid do filho = %d , pid do pai = %d\n\n",getpid(),getppid());
			_exit(0);
			break;
		default: // pai
			printf("Eu sou pai e sou o pid = %d , ppid = %d \n",getpid(),getppid());
			break;
	}
	//printf("\n\n\n%d\n\n\n",status);
	WIFEXITED(status);
	if(wait(&status) == son){
		puts("Canalha morreu");
		printf("status = %d\n",status);
	}	
	//printf("\n\n\n%d\n\n\n",status);
    	//printf("pid = %d\nppid = %d\n", getpid(),getppid());
   	return 0;
}
