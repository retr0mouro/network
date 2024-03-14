#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
	int status;
	pid_t son;
	son = fork();
	if(son == 0){
		execl("/bin/ls","ls","-l",".",NULL);
		_exit(0);
	} else if (son < 0){
		perror("Erro ao criar o filho");
		_exit(-1);
	}
	son = wait(&status);
	if(WIFEXITED(status))
		printf("Filho %d executou e saiu com código %d.\n",son,WEXITSTATUS(son));
	return 0;
}
