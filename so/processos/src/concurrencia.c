#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

void endChild(int num){
	printf("Filho %d - pid : %d, pid do pai : %d -> morreu\n",num,getpid(),getppid());
	sleep(1);
}



int main(void){
	int status;
	pid_t son;
	for(int i = 0;i < 10;i++){
		son = fork();
		if(son == 0){
			endChild(i);
			_exit(i+1);
		} else if (son < 0){
			perror("Erro ao criar processo filho");
			_exit(-1);
		}
	}
	
	for(int i = 0; i < 10;i++){
		son = wait(&status);
		if(WIFEXITED(status)){
			printf("Processo filho %d terminou com código de saida %d\n",son,WIFEXITED(status));

		}
	}

	return 0;
}
