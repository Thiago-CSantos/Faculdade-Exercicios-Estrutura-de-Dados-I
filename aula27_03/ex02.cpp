#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int vet[] = {3,14,25,36};
	int *ptr = vet+3;	//ptr esta com edereco do quarto elemento
	*ptr = 8;
	int i;
	ptr = vet;
	
	for(i =0; i<4; i++){
		printf("\n%d", *(ptr+i));
	}
	
}
