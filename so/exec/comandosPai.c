#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void){
	execl("/bin/ls","ls","-l",NULL);
	return 0;
}
