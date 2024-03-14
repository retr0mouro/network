#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc,char * argv[]){
	int status;
	pid_t son;
	
	son = fork();
	if(son == 0){ // Codigo para o filho
		execvp(argv[1],&argv[1]); // Termina se executar corretamente
		
		// Codigo a executar se correr mal
		perror("correu mal");
		_exit(-1);
	}

	son = wait(&status); // Pai espera pelo filho 

	if(WIFEXITED(status)){ // imprimir o estado de saida do filho
		printf("o filho %d terminou com um codigo %d",son,WEXITSTATUS(son));
	}
	return 0;
}
