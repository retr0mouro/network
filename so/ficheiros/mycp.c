#include <sys/types.h>
#include <unistd.h> // chamadas ao sistema: defs e decls essenciais
#include <fcntl.h> // O_RDONLY | O_WRONLY | O_CREAT | O_*
#include <stdio.h>

int main(int argc,char ** argv){
	char buffer[1024];
	int n; 
	int fdi = open(argv[1],O_RDONLY);
	if(fdi == -1){
		perror(argv[1]);
		return 1;
	}
	int fdo = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC,0666);
	if(fdo == -1){
		perror(argv[2]);
		close(fdi);
		return 1;
	}
	while((n = read(fdi,buffer,sizeof(buffer)))>0){
		write(fdo,buffer,n);
	}
	close(fdi);
	close(fdo);
	return 0;
}
