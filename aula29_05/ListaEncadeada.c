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

//Fazer as seguintes fun��es:
int tamanhoLista(){
	//deve calcular quantos n�s existem na lista
	//e retornar
	struct No* aux = inicio;
	int cont = 0;
	
	while(aux!= NULL){
		aux = aux->proximo;
		cont++;
	}
	
	return cont;
	
}


struct No *procura(char Nome[]){
	// deve procurar o nome na lista
	//caso n�o encontre, retorna NULL
	//se encontrar retora a n� na lista onde o nome est�
	
	struct No* aux = inicio;
	
	while(aux!=NULL){
		
		if(strcmp(aux->nome, Nome) == 0){
			return aux->nome;
		}
		else if (strcmp(aux->nome, Nome) == 1){
			return NULL;
		}
		
		aux = aux->proximo;
	
	}
	
}

void inverterLista(){
	//dada uma lista
	//criar outra para imprimir a lista na ordem inversa;
	//ou seja a lista for Luiz, hugo, zezinho
	//deve gerar a Zezinho, hugo, luiz
	
	struct No* aux = inicio;
	struct No* aux2 = NULL;
	
	
	while(aux != NULL){
		
		aux2 = aux->proximo;
		aux->proximo = inicio;
		inicio = aux;
		aux = aux2;
	}
	
	do{
		printf("\n %s", aux->nome);
		aux= aux->proximo;
	}while(aux!=NULL);
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
	int n =tamanhoLista(); printf("%d", n);
	
	struct No* p = procura("Thiago"); printf(" %s\n", p->nome);
	
	inverterLista();
	
	
}
