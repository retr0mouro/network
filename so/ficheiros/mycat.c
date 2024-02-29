#include <unistd.h> 
#include <fcntl.h>
#include <stdio.h>


int main(int argc,char ** argv){
	char buffer[1024];
	int n;
	while((n=read(0,buffer,sizeof(buffer)))>0){
		write(1,buffer,n);
	}
	return 0;
}
