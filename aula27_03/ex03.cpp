#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	
	int *computadorA;
	
	computadorA = (int*)malloc(sizeof(int)*10);
	
	//vetor auxiliar para armazenar necessario  do vetor original
	int *backup = (int*)malloc(sizeof(int)*9);
	int i;
	for(i=0;i<10; i++){
		computadorA[i] = i+1; // computadorA = {1,2,3,...10}
	}
	
	//passar as informações importante para backup
	for (i=0; i<9;i++){
		backup[i] = computadorA[i+1];
	}
	
	//apagar tudo o que está em computadorA
	free(computadorA);
	
	//passar o backup para computadorA
	computadorA = backup;
	
	//imprimir o conteudo
	for(i=0; i<9; i++){
		printf("\n%d", computadorA[i]);
	}
	
}
