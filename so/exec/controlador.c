#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(int argc, char ** argv){
	
	int status;
	pid_t son;
	repeat:
	for(int i = 1;i < argc;i++){
		son = fork();
		if(son == 0){
			execvp(argv[i],&argv[i]);
			perror("N fechou corretamente");
			_exit(-1);
		}
	}
	
	for(int i = 0; i < argc - 1;i++){
		sleep(1);
		son = wait(&status);
		if(WIFEXITED(status)){
			if(WEXITSTATUS(status) == 0){
				printf("Calhou 0\n");
			} else {
				goto repeat;	
			}
		}
		
	}
	


	return 0;
}
