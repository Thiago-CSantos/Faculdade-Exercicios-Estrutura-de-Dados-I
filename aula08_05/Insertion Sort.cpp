#include<stdio.h>


void insertionSort(int A[], int tamanho){
	int i, j, elemento, k;
	
	for(j=1; j<tamanho;j++){
		i = j -1;
		elemento=A[j];
		
		k=j;
		
		while((i>=0)&&(A[i]>elemento)){
			A[k] =A[i];
			i--;
			k--;
		}
		A[k] =elemento;
	}
	
}

int main(){
	int a[] = {8,1,6,9,5,4};
	int x;
	insertionSort(a,6);
	
	for( x = 0; x<6; x++){
		printf("%d", a[x]);
	}
	
}
