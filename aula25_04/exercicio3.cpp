#include <stdio.h>

// numeros de 1 ate o M
// exercicio 3

void numerosAteM(int M) {
	
    if(M == 1){
    	printf("1");
	}
	else{
		numerosAteM(M-1);
		printf("%d", M);
	}
	
}

int main() {
    int M = 10, s;
    numerosAteM(M);

}

