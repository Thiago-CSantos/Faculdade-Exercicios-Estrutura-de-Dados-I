#include <stdio.h>

void bubbleSort(int *v, int tamanho){
	
	int i,j,trocou=1, aux;
	
	i= tamanho-1;
	
	while(i >= 1 && trocou == 1){
		trocou = 0;
		
		for(j=0; j<i; j++){
			
			if(v[j]>v[j+1]){
				aux = v[j];
				
				v[j] = v[j+1];
				v[j+1] = aux;
				
				trocou = 1;
			}
			
		}
		
		i = i-1;
		
	}
	
}

int main(){
	int A[6] = {9,6,2,3,1,2};
	
	int tamanho = 6,i;
	
	bubbleSort(A, tamanho);
	
	for(i= 0; i<tamanho; i++){
		printf("%d", A[i]);
	}
}
