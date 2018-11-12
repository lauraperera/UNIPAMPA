#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funcoes.h"

struct filmess{ //depois de usar a strtok passa pra string
  int codigo;
  char titulo[100];
  int ano;
  int quantidade;
  char genero[10];
}vetor[42];

int main(){
  int op=0, n;

 n = carregar(); //salvando o numero total de filmes na variavel n

while(op != 7){

    printf("\n--------------------Locadora do Alcemar--------------------\n\n");
    printf("1 - Alugar um filme------------------------------------------\n");
    printf("2 - Entregar um filme----------------------------------------\n");
    printf("3 - Buscar por um filme no acervo----------------------------\n");
    printf("4 - Imprimir-------------------------------------------------\n");
    printf("5 - Salvar as modificações em um arquivo e imprimir tudo-----\n");
    printf("6 - Pesquisar filmes, imprimir e salvá-los em um arquivo-----\n");
    printf("7 - Sair-----------------------------------------------------\n");
    printf("\n--------------Selecione uma das opções acima:--------------\n");
    scanf("%d", &op);

    switch(op){
      case 1:
      locar(); //alugar um filme
      break;

      case 2:
      entregar(); //devolver um filme
      break;

      case 3:
      buscar(); //buscar e imprimir informa��es de filmes baseado em codigo, titulo, genero ou ano
      break;

      case 4:
      imprimirselecao(); //imprimir, pode imprimir o acervo completo ou imprimir informa��es de um determinado filme
      break;

      case 5:
      backup(n); //criar um arquivo novo com as informa��es atualizadas
      break;

      case 6:
      backupselect(n); //criar um arquivo novo com as informa��es atualizadas de um certo tipo de filme, baseado em ano e genero
      break;

	  case 7:
	  printf("Você deixou o programa.\n");
	  break;

      default:
      printf("Opção inválida, tente novamente.\n");
      break;

    }

  }

  return 0;
}
