#include<stdio.h>

/*fscanf examble*/

int main(){
	FILE *pFile;
	char nome[50];
	char outroNome[100];
	int i,j;
	
	
	pFile=fopen("C:\\Users\\28067-4\\Desktop\\nomeArquivo.txt", "w");
	
	if(pFile!=NULL){
		
		for(i=0;i<3;i++){
			printf("Escreva um nome: ");
			gets(nome);
			fprintf(pFile,"Nome %d: %s\n",i+1,nome);
		}
	}
	printf("teste\n");
	fclose(pFile);
	pFile=fopen("C:\\Users\\28067-4\\Desktop\\nomeArquivo.txt", "r");
	
	if(pFile != NULL){
		
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				fscanf(pFile, "%s", nome);
				if(j==2){
				printf("Nomes: %s\n", nome);	
				}
				
			}
		}
		
	}
	
	fclose(pFile);
	return 0;
}
