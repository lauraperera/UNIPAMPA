#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"funcoes.h"

struct est{
	int codigo;
	char nome[15];
	float preco;
	int quantidade;
}estoque[2];

int cria(){
	int i;

	for(i=0; i<2; i++){ //tem 2 só pra testar, mudar pra 5
		printf("Insira o código do produto:\n");
		scanf("%d", &estoque[i].codigo);
		printf("Insira o nome do produto:\n");
		scanf("%s", &estoque[i].nome);
		printf("Insira o preço do produto:\n");
		scanf("%f", &estoque[i].preco);
		printf("Insira a quantidade desse produto:\n");
		scanf("%d", &estoque[i].quantidade);
	}

return 0;
}

int ler(){
	int i=0, cod, qnt;
	
	printf("Digite o código e a quantidade do produto que você deseja:\n");
	scanf("%d %d", &cod, &qnt);
	
	while((estoque[i].codigo != cod) && (i<2)){
		i++;
	}

	if(cod == estoque[i].codigo){
		if(qnt > estoque[i].quantidade){
			printf("Você pediu %d porém temos apenas %d. Quantidade indisponível no estoque.\n", qnt, estoque[i].quantidade);
		}else{
			estoque[i].quantidade = (estoque[i].quantidade - qnt);
			printf("Sua compra foi efetuada com sucesso! Ainda possuímos %d produtos como este.\n", estoque[i].quantidade);		
		}
	}else{
		printf("O código que você inseriu está errado.\n");
	}
return 0;	
}

int imprimir(){
	int i;
	
	for(i=0; i<2; i++){
		printf("*********************************************\n");
		printf("%d\n", estoque[i].codigo);
		printf("%s\n", estoque[i].nome);
		printf("%f\n", estoque[i].preco);
		printf("%d\n", estoque[i].quantidade);
		printf("*********************************************\n");
	}
return 0;
}
