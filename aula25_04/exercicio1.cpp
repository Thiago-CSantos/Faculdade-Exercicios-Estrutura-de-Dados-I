#include <stdio.h>

// exercicio 1
int calcular(int m, int n){
	
	
	if(n == 0){
		return m;
	}
	
	else if(n>0){
		printf("\nM=%d\nN=%d", m, n);
		return 1+calcular(m,n-1);
		
	}
	
	
}

int main(){
	int M=7, N=3;
	int soma;
	soma = calcular(M,N);
	
	printf("\n%d\n", soma);
}
