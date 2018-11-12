#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"funcoes.h"

int main(){
	int opcao;

	
	while(opcao!=0){
	printf("*********************************************\n");
	printf("1 - Criar um estoque\n");
	printf("2 - Ler um produto do estoque\n");
	printf("3 - Imprimir lista de produtos\n");
	printf("0 - Sair\n");
	printf("*********************************************\n");
	scanf("%d", &opcao);

		switch(opcao){


			case 1:
				cria();
			break;

			case 2:
				ler();
			break;
	
			case 3:
				imprimir();
			break;

			case 0:
				printf("Saindo do estoque.\n");
			break;

			default:
				printf("Opção inválida, por favor digite outra opção.\n");

			break;
		}
	}

return 0;
}

