#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

#define SIZE 10

void processChild(int num){
	printf("Filho %d - pid : %d, pid do pai : %d\n",num,getpid(),getppid());
	_exit(num);
}

int main(void){
	int status;
	pid_t son;
	for(int i = 0;i < 10;i++){
		son = fork();
		if(son == 0){ // value returned in the child
			processChild(i);
		} else if(son < 0){ // child was not created, fork failed
			perror("Erro ao criar o filho");
			_exit(-1);
		} else {
			wait(&status);
			if(WIFEXITED(status)){
				printf("Filho %d terminou com um código de saída: %d\n",i,WEXITSTATUS(status));
			}else{
				printf("Filho %d saiu anormalmente.",i);
			}
		}
	}
	return 0;	
}
