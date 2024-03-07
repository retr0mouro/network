#include "matrix.h"


int **createMatrix() {

    // seed random numbers
    srand(time(NULL));

    // Allocate and populate matrix with random numbers.
    printf("Generating numbers from 0 to %d...", MAX_RAND);
    int **matrix = (int **) malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = (int*) malloc(sizeof(int) * COLUMNS);
        for (int j = 0; j < COLUMNS; j++) {
            matrix[i][j] = rand() % MAX_RAND;
        }
    }
    printf("Done.\n");

    return matrix;
}

void printMatrix(int **matrix) {

    for (int i = 0; i < ROWS; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < COLUMNS; j++) {
            printf("%7d ", matrix[i][j]);
        }
        printf("\n");
    }
}

static int verifyLine(int ** matrix,int line,int value){
	for(int i = 0;i < COLUMNS;i++){
		if(matrix[line][i] == value){
			return i;
		}
	}
	return 0;	
}


static void print_integer(int num) {
    char buffer[20];  // Assuming a maximum of 20 digits for the integer
    int length = 0;
    int temp = num;
    
    // Handle the case of negative numbers
    if (num < 0) {
        buffer[0] = '-';
        length++;
        temp = -temp;
    }
    
    // Convert the integer to a string
    do {
        buffer[length++] = temp % 10 + '0';
        temp /= 10;
    } while (temp != 0);
    
    // Reverse the string
    for (int i = 0; i < length / 2; i++) {
        char temp = buffer[i];
        buffer[i] = buffer[length - i - 1];
        buffer[length - i - 1] = temp;
    }
    
    // Add null terminator
    buffer[length] = '\0';
    
    // Write the string to the standard output (screen)
    write(STDOUT_FILENO, buffer, length);
}

// ex.5
int valueExists(int **matrix, int value) {
	int status;
	int flag = 0;
	for(int i = 0;i < ROWS;i++){
		if(fork() == 0){
			int n = verifyLine(matrix,i,value);
			if(n != 0) _exit(0);
			else _exit(1);
		}
	}
	for(int i = 0; i < ROWS; i++){
		wait(&status);
		if(WIFEXITED(status) && flag == 0){
			if(WEXITSTATUS(status) == 0){
				flag = 1;
			}
		}
	}
	return flag;
}


// ex.6
void linesWithValue(int **matrix, int value) {
	pid_t son;
	for(int i = 0; i < ROWS;i++){
		son = fork();
		if(son == 0){
			int flag = verifyLine(matrix,i,value);
			if(flag != 0){
				write(STDOUT_FILENO,"Linha ",6);
				print_integer(i);	
				write(STDOUT_FILENO," Posição ",11);
				print_integer(flag);
				write(STDOUT_FILENO,"\n",1);
			}
			_exit(i+1);
		} else if(son < 0) {
			perror("Erro ao criar processo filho!");
			_exit(-1);
		}
	}
		/*
		for(int i = 0;i < ROWS;i++){
			son = wait(&status);
			if(WIFEXITED(status)) printf("Linha %d Processo filho %d saiu com %d\n",i,son,WIFEXITED(status));
		}
		*/
	
}
