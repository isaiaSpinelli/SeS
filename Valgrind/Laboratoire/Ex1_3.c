// Spinelli Isaia

// gcc -Wall -g -o Ex1_3 Ex1_3.c
// valgrind ./Ex1_3


#include "stdio.h"
#include "stdlib.h"


int segmentation(void);

int main(int argc, char *argv[]) {
  
  	printf("Ex1_2 !\n"); 
  	segmentation();
	return EXIT_SUCCESS;
}

int segmentation(void)
{

	int *p = NULL;
    *p = 0;
    return 0;   
}
