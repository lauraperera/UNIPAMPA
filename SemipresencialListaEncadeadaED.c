// Lista 02: Listas encadeadas
//Data: 21/09/2018
//Nome: Guilherme Domingues Goulart e Laura Perera E-mail: Guilhermegoulart3224@yahoo.com.br, lauraperera.pss@gmail.com



#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct ALUNO{
  char nome[10];
  int nota1;
  int nota2;
  int nota3;
  struct ALUNO *ponteiro_proximo;
};

typedef struct ALUNO aluno;



aluno *INSERIR(aluno *ponteiro_inicio){
  aluno *ponteiro_auxiliar = ponteiro_inicio;
  aluno *ponteiro_anterior;
  aluno *ponteiro_novo;

  ponteiro_novo = malloc(sizeof(aluno));

  printf("Nome:\n");
  scanf("%s", &ponteiro_novo->nome);
  printf("Nota 1:\n");
  scanf("%d", &ponteiro_novo->nota1);
  printf("Nota 2:\n");
  scanf("%d", &ponteiro_novo->nota2);
  printf("Nota 3:\n");
  scanf("%d", &ponteiro_novo->nota3);

  while((ponteiro_auxiliar != NULL) && (strcmp(ponteiro_auxiliar->nome, ponteiro_novo->nome) == -1)){
    ponteiro_anterior = ponteiro_auxiliar;
    ponteiro_auxiliar = ponteiro_auxiliar->ponteiro_proximo;
  }
  if(ponteiro_auxiliar == NULL){
    ponteiro_novo->ponteiro_proximo = ponteiro_inicio; //insere no inicio, quando a lista ainda n existe
    ponteiro_inicio = ponteiro_novo;
  }else{
    ponteiro_anterior->ponteiro_proximo = ponteiro_novo;
    ponteiro_novo->ponteiro_proximo = ponteiro_auxiliar;
  }


return ponteiro_inicio;
}




aluno *EXCLUIR(aluno *ponteiro_inicio){
  aluno *ponteiro_anterior = NULL;
  aluno *ponteiro_auxiliar = ponteiro_inicio;
  char remover[10];

  printf("O que voce quer remover?\n");
  scanf("%s", &remover);

  while((ponteiro_auxiliar != NULL) && (strcmp(ponteiro_auxiliar->nome, remover) != 0)){
    ponteiro_anterior = ponteiro_auxiliar; //anterior tava em null e o aux tava = pont inicial
    ponteiro_auxiliar = ponteiro_auxiliar->ponteiro_proximo;
  }

  if(ponteiro_auxiliar == NULL){
    return ponteiro_inicio; //se for null ou nao tem nd na lista ou ta no fim da lista por isso retorna a lista igual
  }else if(ponteiro_anterior == NULL){
    ponteiro_inicio = ponteiro_auxiliar->ponteiro_proximo; //no inicio da lista
    free(ponteiro_auxiliar);
  }else{
    ponteiro_anterior->ponteiro_proximo = ponteiro_auxiliar->ponteiro_proximo;
    free(ponteiro_auxiliar);
  }

free(ponteiro_anterior);
return ponteiro_inicio; 
}



void BUSCAR(aluno *ponteiro_inicio){
  aluno *ponteiro_auxiliar = ponteiro_inicio; //aux recebe inicio pra nao mexer no ponteiro_inicio
  char busca[10];

  printf("O que você quer buscar?\n");
  scanf("%s", &busca);

  while(ponteiro_auxiliar != NULL){
    if(strcmp(ponteiro_auxiliar->nome, busca) == 0){
      printf("%s, %d, %d, %d\n", ponteiro_auxiliar->nome, ponteiro_auxiliar->nota1, ponteiro_auxiliar->nota2, ponteiro_auxiliar->nota3);
    }
    ponteiro_auxiliar = ponteiro_auxiliar->ponteiro_proximo;
  }
}




void LISTAGEM(aluno *ponteiro_inicio){
  aluno *ponteiro_auxiliar = ponteiro_inicio;

  while(ponteiro_auxiliar != NULL){
    printf("%s, %d, %d, %d\n", ponteiro_auxiliar->nome, ponteiro_auxiliar->nota1, ponteiro_auxiliar->nota2, ponteiro_auxiliar->nota3);
    ponteiro_auxiliar = ponteiro_auxiliar->ponteiro_proximo;
  }

}




void main(){
  aluno *ponteiro_inicio = NULL;
	int opcao=10;

	while(opcao){
		printf("\nDigite:\n");
		printf("1 - Inserir.\n");
		printf("2 - Excluir um aluno\n");
		printf("3 - Buscar informacoes sobre determinado aluno\n");
		printf("4 - Mostrar toda a lista\n");
		printf("5 - Sair\n");
		scanf("%d", &opcao);

		switch(opcao){

			case 1:
      ponteiro_inicio =  INSERIR(ponteiro_inicio);
      break;

			case 2:
			ponteiro_inicio = EXCLUIR(ponteiro_inicio);
			break;

			case 3:
			BUSCAR(ponteiro_inicio);
	    break;

			case 4:
			LISTAGEM(ponteiro_inicio);
      break;

			case 5:
			opcao=0;
      break;

			default:
      printf("Erro.\n");
      break;
	}
}
}

