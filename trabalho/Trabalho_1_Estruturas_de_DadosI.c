// Nomes: Rafael Almeida Vasconcelos
//        Thiago Carretero dos Santos
//        Raphael Baruque Souza
//        Guilherme Dias Gregorio


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 100

void openMenu();
void cadastrarFuncionario();
void planejamentosTurnos();
void trocaTurnos();
void printTurnos();

struct Turno
{
  int dia[100];
  int turno[100];
};
typedef struct funcionario
{
  char nome[50];
  char codigo[10];
  char cargo[50];
  struct Turno horario;
} Funcionario;

int main()
{
  setlocale(LC_ALL, "");
  openMenu();
}

void openMenu()
{
  int n;
  printf("---------MENU---------\n");
  printf("1 - Cadastrar funcionario\n");
  printf("Digite a opcao desejada: ");
  scanf("%d", &n);

  switch (n)
  {
  case 1:
    cadastrarFuncionario();
    break;
  default:
    printf("Opcao invalida!\n");
    return openMenu(n);
  }
}

void cadastrarFuncionario()
{

  int i, numFuncionarios = 0, j;
  printf("Digite o numero de funcionarios: ");
  scanf("%d", &numFuncionarios);

  Funcionario *funcionarios = (Funcionario *)malloc(numFuncionarios * sizeof(Funcionario));

  int id[numFuncionarios];
  for (i = 0; i < numFuncionarios; i++)
  {
    printf("Digite o nome do funcionario: ");
    fflush(stdin);
    scanf("%s", funcionarios[i].nome);
    printf("Digite o cargo do funcionario: (enfermeiro, medico ou residente)");
    fflush(stdin);
    scanf("%s", funcionarios[i].cargo);
    id[i] = i + 1;

    for (j = 0; j < i; j++)
    {
      if (id[j] == id[i])
      {
        printf("Codigo ja cadastrado. Por favor, digite outro codigo.\n");
        i--;
        break;
      }
    }
    if (j < i)
    {
      continue;
    }
  }
  
  printTurnos(funcionarios,numFuncionarios, id );
  planejamentosTurnos(numFuncionarios, funcionarios, id);
}
void planejamentosTurnos(int numFuncionarios, Funcionario *funcionarios, int *id)
{
  int i,compID;
  
  printf("Qual funcionario deseja planejar o turno? (digite numero de indentificacao)");
  scanf("%d", &compID); //id para comprovar que o funcionario existe
  
  for (i = 0; i < numFuncionarios; i++)
  {
    reset:; // label para retornar ao inicio do for usamos o goto para nos ajudar a sair do if
    if (id[i] == compID) { 
    	
	    printf("Digite o dia do funcionario %s: ", funcionarios[i].nome);
	    scanf("%d", &funcionarios[i].horario.dia[i]);
	    
	    if(funcionarios[i].horario.dia[i] < 1 || funcionarios[i].horario.dia[i] > 30)
	    {
	      printf("erro, o dia tem que ser entre 1 e 30");
	      goto reset;
	    }
	    printf("Digite o turno do funcionario %s: ( 1=noturno, 2=diurno )", funcionarios[i].nome);
	    scanf("%d", &funcionarios[i].horario.turno[i]);
	
	    printf("O funcionario so podera trabalhar novamente no dia %d ", funcionarios[i].horario.dia[i] + 2);
	    if (funcionarios[i].horario.turno[i] == 1)
	    {
	      printf("e horario noturno, em diante\n");
	    }
	    else if (funcionarios[i].horario.turno[i] == 2)
	    {
	      printf("e horario diurno, em diante\n");
	    }
	}
	else{
		continue;
	}
  }

  trocaTurnos(numFuncionarios, funcionarios, id);
}
// Troca de plantões
void trocaTurnos(int numFuncionarios, Funcionario *funcionarios, int* id)
{
  int tempdia, tempturno, i, compID; // variaveis temporarias
 
	printf("Qual funcionario deseja trocar turno? ");
	scanf("%d", &compID);
 
  for (i = 0; i < numFuncionarios; i++)
  {
    restart:; // label para retornar ao inicio do for usamos o goto para nos ajudar a sair do if
    
    if (id[i] == compID) {
    	
    printf("\nDigite o dia que o funcionario %s deseja trocar o turno:", funcionarios[i].nome);
    scanf("%d", &tempdia);
    
    if (funcionarios[i].horario.dia[i] + 1 == tempdia || funcionarios[i].horario.dia[i] == tempdia)
    {
      printf("erro, o funcionario tem que ter um descanso de 36 horas");
      goto restart;
    }
    if (funcionarios[i].horario.dia[i] + 2 == tempdia)
    {
      printf("Em qual turno o funcionario %s deseja trabalhar: ( 1=noturno, 2=diurno )", funcionarios[i].nome);
      scanf("%d", &tempturno);
	      if (funcionarios[i].horario.turno[i] != tempturno)
	      {
	        printf("erro, o funcionario tem que ter um descanso de 36 horas");
	        goto restart;
	      }
	      else
	      {
	        funcionarios[i].horario.dia[i] = tempdia;
	        funcionarios[i].horario.turno[i] = tempturno;
	        printf("Os turnos foram trocados!!!\n");
          printTurnos(funcionarios, numFuncionarios, id);
	      }
    }

	    if (funcionarios[i].horario.dia[i] + 2 < tempdia || funcionarios[i].horario.dia[i] > tempdia)
	    {
	      printf("Em qual turno o funcionario %s deseja trabalhar: ( 1=noturno, 2=diurno )", funcionarios[i].nome);
	      scanf("%d", &tempturno);
	      funcionarios[i].horario.dia[i] = tempdia;
	      funcionarios[i].horario.turno[i] = tempturno;
	      printf("Os turnos foram trocados!!!\n");
        printTurnos(funcionarios, numFuncionarios, id);
	    }
	}
	else{
		continue;
	}
  }

  printTurnos(funcionarios, numFuncionarios, id);
}
void printTurnos(Funcionario *funcionarios, int numFuncionarios, int* id)
{
  int i;
  for (i = 0; i < numFuncionarios; i++)
  {
    printf("\n%d-Nome: %s\n", id[i], funcionarios[i].nome);
    printf("Cargo: %s\n", funcionarios[i].cargo);
    if(strcmp(funcionarios[i].cargo, "enfermeiro") == 0){
      printf("Codigo: COREN\n");
    }
    if(strcmp(funcionarios[i].cargo, "medico") == 0){
      printf("Codigo: CRM\n");
    }
    
    printf("Dia: %d", funcionarios[i].horario.dia[i]);
    
    if(funcionarios[i].horario.turno[i] == 1){
      printf(" Turno: diurno");
    }else if(funcionarios[i].horario.turno[i] == 2){
      printf(" Turno: noturno");
    }

    printf("\nnumero de identificacao: %d", id[i]);
    printf("\n");
  }
}
