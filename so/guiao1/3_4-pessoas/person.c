#include "person.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

//typedef struct person Person;

#define SIZE 64

struct person{
	char name[SIZE];
	unsigned short age;
};


static int getReversedAgeString(char * buffer,unsigned short age){
	int length = 0;
	while(age != 0){
		buffer[length++] = age % 10 + '0';
		age /= 10;
	}
	return length;
}

static void reverseString(char * buffer,int length){
	length -= 1;
	for(int i = 0;i < length;i++,length--){
		char temp = buffer[i];
		buffer[i] = buffer[length];
		buffer[length] = temp;
	}
}

static void ageToString(char * buffer,unsigned short age){
	int size = getReversedAgeString(buffer,age);
	reverseString(buffer,size);
}

void insertPerson(int fd,char * name, unsigned short age){
	lseek(fd,0,SEEK_END);
	char buffer[sizeof(struct person)];
	memset(buffer,'\0',SIZE);
	strcpy(buffer,name);
	char ageString[sizeof(age)];
       	ageToString(ageString,age);
	memcpy(buffer + SIZE,&ageString,sizeof(ageString));
	if(write(fd,&buffer,sizeof(struct person)) != 0){
		write(STDOUT_FILENO,"Pessoa inserida com sucesso!\n",30);
		return;
	}
	write(STDERR_FILENO,"Aconteceu um problema a inserir a pessoa",41);
}

int getPersonName(int filed){
	char name[SIZE];
	memset(name,'\0',SIZE);
	read(filed,&name,SIZE);
	return write(STDOUT_FILENO,&name,SIZE);
}

int setPersonName(int filed,char * name){
	return write(filed,name,SIZE);
}

unsigned short  getPersonAge(int filed){
	unsigned short age;
	lseek(filed,SIZE,SEEK_CUR);
	read(filed,&age,sizeof(unsigned short));
	return age;
}

int setPersonAge(int fd,char * name,char * age){
	lseek(fd,0,SEEK_SET);
	char buffer[SIZE];
	//char ageString[sizeof(unsigned short)];
	while((read(fd,buffer,SIZE)) > 0){
		if(strcmp(name,buffer) == 0){
			//ageToString(ageString,age);
			write(fd,age,sizeof(ageToString));
			return 0;
		}
		lseek(fd,sizeof(struct person) - SIZE,SEEK_CUR);
	}
	return 1;
}

void printPerson(int fd){
	char buffer[sizeof(struct person)];
	read(fd,&buffer,sizeof(struct person));
	write(STDOUT_FILENO,buffer,sizeof(struct person));
}
