// Spinelli Isaia
// gcc -Wall -g -o Ex1_3 Ex1_3.c
// valgrind ./Ex1_3


#include "stdio.h"
#include "stdlib.h"
#include <string.h>

int segmentation(void);

int main(int argc, char *argv[]) {
  
  	printf("Ex1_3 !\n"); 
  	segmentation();
	return EXIT_SUCCESS;
}

int segmentation(void)
{

	char* caractere = NULL; 
	caractere[0] = 'A'; // Segmentation fault !

	 return 0;
}
