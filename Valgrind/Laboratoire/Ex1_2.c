// Spinelli Isaia

// gcc -Wall -g -o Ex1_2 Ex1_2.c
// valgrind --leak-check=full ./Ex1_2


#include "stdio.h"
#include "stdlib.h"
#include <string.h>

int memoryLeak(void);

int main(int argc, char *argv[]) {
  
  	printf("Ex1_2 !\n"); 
  	memoryLeak();
	return EXIT_SUCCESS;
}

int memoryLeak(void)
{

	char* caractere = (char*) malloc(1);
	caractere[0] = 'A';
	printf("%c\n", caractere[0]);

	//free(caractere);
	caractere = NULL;

	 return 0;
}
