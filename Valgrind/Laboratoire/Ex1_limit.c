// Spinelli Isaia
// gcc -Wall -g -o Ex1_limit Ex1_limit.c
// valgrind --tool=memcheck --leak-check=ful ./Ex1_limit


#include "stdio.h"
#include "stdlib.h"
#include <string.h>


int main(int argc, char *argv[]) {
  
  	printf("Ex1_limit !\n"); 

	if (1){
		int array[3];
   		array[3] = 0; //  dépassement d'un tableau alloué automatiquement
   		
   	// ne test pas le else
	} else {
		char* caractere = NULL; 
		caractere[0] = 'A'; // Segmentation fault !
	}
   
    	
	return EXIT_SUCCESS;
}

