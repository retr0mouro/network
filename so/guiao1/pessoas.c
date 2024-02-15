#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFERSIZE 1024

void printaPessoas(int file,int n){
	for(int i = 0;i < n;i++){
		char buffer[BUFFERSIZE];
		int n;
		char flag = '0';
		while((n=read(file,buffer,sizeof(buffer)))>0){
			
		}
	}
}

int main(int argc, char ** argv){
	printf(argv[1]);
	return 0;
}
