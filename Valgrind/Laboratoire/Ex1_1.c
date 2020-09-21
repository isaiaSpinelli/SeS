// Spinelli Isaia
//gcc -Wall -g -o Ex1_1 Ex1_1.c
// valgrind --tool=memcheck ./Ex1_1

#include "stdio.h"
#include "stdlib.h"
#include <string.h>

int heapOverflow(void);

int main(int argc, char *argv[]) {
  
  	printf("Ex1_1 !\n"); 
  	heapOverflow();
	return EXIT_SUCCESS;
}

int heapOverflow(void)
{
	char*  stringBonjour = "Bonjour !";
	int size = sizeof(stringBonjour);

	char* heap = (char*) malloc(5);
	memcpy(heap, stringBonjour, size);

	free(heap);
	heap = NULL;

	 return 0;
}
