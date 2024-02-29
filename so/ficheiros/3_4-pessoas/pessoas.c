#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "person.h"
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char* argv[]){

    if ( argc < 3 )
    {
        printf("Usage:\n");
        printf("Add new person: ./pessoas -i [name] [age]\n");
        printf("List N persons: ./pessoas -l [N]\n");
        printf("Change person age: ./pessoas -u [name] [age]\n");
        printf("Change person age (v2): ./pessoas -o [position] [age]\n");
        return 1;
    }

    if ( strcmp(argv[1],"-i") == 0 )
    {
	int fd = open("./pessoas.db",O_CREAT|O_WRONLY,0666);
	if(fd != 0){
        	insertPerson(fd,argv[2],(unsigned short)atoi(argv[3]));
	}
	if((close(fd)) != 0){
		perror("Não fechou direito quando inseriu!");
		return 1;
	}
	return 0;
    }

    if ( strcmp(argv[1],"-l") == 0 )
    {
	int fd = open("./pessoas.db",O_RDONLY,0666);
	lseek(fd,0,SEEK_SET);
	char end;
        for(int i = 0;(i < (unsigned short) atoi(argv[2])) && (end = read(fd,&end,sizeof(end)) > 0);i++){
		lseek(fd,-sizeof(end),SEEK_CUR);
		printPerson(fd);
	}
	if((close(fd)) != 0){
		perror("Não fechou corretamente");
		return 2;
	}
	return 0;
    }

    if ( strcmp(argv[1],"-u") == 0 )
    {
	int fd = open("./pessoas.db",O_RDWR,0666);
	if(fd != 0){
		return setPersonAge(fd,argv[2],argv[3]);
	}
	perror("Não abriu o ficheiro");
	return 1;
    }

    if ( strcmp(argv[1],"-o") == 0 )
    {
        // TO DO
    }

    return 0;
}
