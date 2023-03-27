#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int vet[] = {3,14,25,36};
	int *ptr = vet;	
	int i;
	
	
	for(i = 0; i<4; i++){
		printf("%d\n", *(ptr+i));
	}
}
