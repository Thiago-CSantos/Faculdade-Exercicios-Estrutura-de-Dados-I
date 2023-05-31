#include <stdio.h>
#include <string.h>

struct No{
	char nome[21];	//nome possui no maximo 20 caracteres
					//1 para guardar o \0
	struct No *proximo; //deve guardar o endereço do proximo elemento
};

struct No* inicio = NULL;

/*
	adiciona um nome à lista
*/

void inserirNoInicio (char nome[]){
	// 1º passo: construir um nó para armazernar o nome
	struct No *novo= malloc(sizeof(struct No));
	
	//2º passo: guardar as informações no No
	strcpy(novo->nome, nome);
	//3º passo:
	novo->proximo = inicio;
	
	//4º passo:
	inicio = novo; // recebe o indereço
	
}

void inserirNoFinal(char nome[]){
	// 1º passo: construir um nó para armazernar o nome
	struct No *novo= malloc(sizeof(struct No));
	
	//2º passo: guardar as informações no No
	strcpy(novo->nome, nome);
	novo->proximo = NULL;
	
	//3º passo: avaliar lista vazia
	if(inicio == NULL){
		inicio = novo;
	}
	else{
			struct No *temp = inicio;
		//4º passo: andar até o ultimo nó
		while(temp->proximo !=NULL){
			temp = temp->proximo;
		}
		//inserir após o ultimo
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
