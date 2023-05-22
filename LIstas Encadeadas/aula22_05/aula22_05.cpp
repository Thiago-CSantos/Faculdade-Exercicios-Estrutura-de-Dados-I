#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

struct No{
	int valor; //armazena o dado do n�
	struct No *proximos; // guarda o endere�o do proximo
//	struct Aluno aluno;
};

//struct Aluno{
//	char nome[100];
//	int RA;
//};

int main(){
	setlocale(LC_ALL,"");
	//exemplo para Listas de inteiros
	struct No *inicio = NULL;
	printf("\nNo inicio o programa a lista �: %p", inicio);
	printf("\nO inicio � uma variavel com outra qualquer e esta em: %p", &inicio);
	
	
	// alocando um n�
	struct No *novo = (struct No*)malloc(sizeof(struct No));
	printf("\nO n� foi alocado em %p", novo);
	printf("\nO endereco de novo �: %p", &novo);
	
	novo->valor=10;
	novo->proximos = NULL;
	
	//criar a liga��o do n� com a lista
	
	inicio = novo; // recebe o endere�o
	printf("Se inicio recebe o novo ent�o: %d = %d",novo->valor, inicio->valor);
	
	// exercicio 3: alocar o n� para guardar o 20
	novo =(struct No*)malloc(sizeof(struct No));
	novo->valor=20;
	novo->proximos = NULL;
	
	//Exercicio 4: colocar o n� 20 como sucessor do n� 10.
	inicio->proximos = novo;
	//exercicio 5: a partir do n� inicio, imprimir o valor 20
	printf("\nO segundo elemento vale %d", inicio->proximos->valor);
}
