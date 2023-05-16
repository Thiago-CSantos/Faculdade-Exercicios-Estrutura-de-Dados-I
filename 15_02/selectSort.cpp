#include <stdio.h>

void selectSort(int *v, int tamanho){
	
	int i,j,min, aux,c;
	
		
	for(i=0;i<tamanho-1;i++){
		min = i;
		
		for(j=i+1;j<tamanho;j++){
			if(v[j] <= v[min]){
				min=j;
			}
		}
		aux= v[i];
		v[i] = v[min];
		v[min] = aux;
	}

	
}

int main(){
	int A[6] = {9,6,2,3,1,2};
	
	int tamanho = 6,i;
	
	selectSort(A, tamanho);
	
	for(i= 0; i<tamanho; i++){
		printf("%d", A[i]);
	}
}
