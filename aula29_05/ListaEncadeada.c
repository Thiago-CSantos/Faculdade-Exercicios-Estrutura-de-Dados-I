#include <stdio.h>
#include <string.h>

struct No{
	char nome[21];	//nome possui no maximo 20 caracteres
					//1 para guardar o \0
	struct No *proximo; //deve guardar o endere�o do proximo elemento
};

struct No* inicio = NULL;

/*
	adiciona um nome � lista
*/

void inserirNoInicio (char nome[]){
	// 1� passo: construir um n� para armazernar o nome
	struct No *novo= malloc(sizeof(struct No));
	
	//2� passo: guardar as informa��es no No
	strcpy(novo->nome, nome);
	//3� passo:
	novo->proximo = inicio;
	
	//4� passo:
	inicio = novo; // recebe o indere�o
	
}

void inserirNoFinal(char nome[]){
	// 1� passo: construir um n� para armazernar o nome
	struct No *novo= malloc(sizeof(struct No));
	
	//2� passo: guardar as informa��es no No
	strcpy(novo->nome, nome);
	novo->proximo = NULL;
	
	//3� passo: avaliar lista vazia
	if(inicio == NULL){
		inicio = novo;
	}
	else{
			struct No *temp = inicio;
		//4� passo: andar at� o ultimo n�
		while(temp->proximo !=NULL){
			temp = temp->proximo;
		}
		//inserir ap�s o ultimo
		temp->proximo = novo;
	}
	
}

void printNomes(){
	
	struct No* aux = inicio;
	
	while(aux !=NULL){
		
		printf(" %s ", aux->nome);
		aux = aux->proximo;
	}
}

int main(){
	
//	char array[4][20] = {"Thiago",
//	                    "Raphael", 
//						"Rafael",
//						"Guilherme"
//						};
//	
//	int i;
//	for(i=0; i<4; i++){
//		inserirNoFinal(array[i]);	
//	}
	
	inserirNoFinal("Thiago");
	inserirNoFinal("Rafael");
	inserirNoFinal("Cris");
	inserirNoInicio("Gui");
	
	printNomes();
	
}
