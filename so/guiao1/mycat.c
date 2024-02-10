#include <unistd.h> 
#include <fcntl.h>
#include <stdio.h>

int main(int argc,char ** argv){
        if(argc < 2){
                return 1;
        }
        int opened = open(argv[1],O_RDONLY,440);
        if(opened == -1){ 
                return 1;
        }
        char buffer[5];
        int max = lseek(opened,0,SEEK_END);
        lseek(opened,0,SEEK_SET);
        int count = 0;
        
        count = read(opened,&buffer,5); 

        while(count ==  5){
                printf("%s",buffer); 
                buffer[0] = '\0';
                buffer[1] = '\0';
                buffer[2] = '\0';
                buffer[3] = '\0';
                buffer[4] = '\0';
                count = read(opened,&buffer,5);
        }
        printf("%s",buffer);

        close(opened);
        return 0;
}

