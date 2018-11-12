#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"funcoes.h"

//teste

struct filmess{ //depois de usar a strtok passa pra string
  int codigo;
  char titulo[100];
  int ano;
  int quantidade;
  char genero[10];
}vetor[42];

int carregar(){
    FILE *arquivo;
    int n; //numero total de filmes
    int c=0;//codigo do filme
    char texto[116]; //guarda o texto lido em uma linha do arquivo
    char titulo[100]; //guarda o titulo do filme retirado da string "texto"
    char ano[5]; //guarda o ano do filme retirado da string "texto"
    char quantidade; //guarda a quantidade em estoque retirado da string "texto"
    char genero[10]; //guarda o genero do filme retirado da string "texto"
    int a; // usado para correcao de digitos do ano
    int b; // quantidade
    int y; //contador da posic�o da string "texto"
    int x=0;

    if((arquivo=fopen("entrada.txt", "rt"))==NULL){
        printf("Erro ao abrir o arquivo!");
    }

/********************************************************************************************************************************/

  fseek(arquivo,0,SEEK_SET); //botando o ponteiro no inicio
  fscanf(arquivo, "%d \n", &n); //colocando o 41 na variavel n


  while(fscanf(arquivo, "%[^\n]\n", texto)!=EOF){ //le o arquivo, linha por linha salvando cada linha na string texto
    y=0;

  //STRING DE TEXTO

        while(texto[y]!=';'){ //le o texto da string ate o ;
           titulo[y]=texto[y]; //coloca tudo lido ate o ; na string titulo, letra por letra
           y++;
        }

        titulo[y]='\0'; //delimita os espa�os de memoria usados pelo titulo
        y++; //corrige a posicao do y (pulando o caracter do ;)
        x=0;

  //STRING DE ANO (deve ser alterada para int depois)

        while(texto[y]!=';'){ //le o texto da linha ate o proximo ;
            ano[x]=texto[y];  //coloca tudo lido ate o ; na string ano, letra por letra
            y++;
            x++;
        }

        y++; //corrige a posicao do y (pula o caracter do ;)

        a = atoi(ano); //converte o ano para int

  //STRING DA QUANTIDADE EM ESTOQUE (deve ser alterado para int depois)

        while(texto[y]!=';'){ //le o texto da linha at� o proximo ;
            quantidade=texto[y];
            y++;
            x++;
        }

        y++; //corrige a posicao do y (pula o caracter do ;)
        x=0;

  //STRING QUE SALVA O GENERO DO FILME

        while(texto[y]!='\0'){ //le o texto da linha at� o proximo ;
            genero[x]=texto[y];
            x++;
            y++;
        }

        genero[x]='\0'; //delimita os espa�os de memoria usados pelo titulo

        strcpy(vetor[c].titulo, titulo);
        vetor[c].ano = a;
        vetor[c].quantidade = quantidade - '0'; //passando quantidade pra int
        strcpy(vetor[c].genero, genero);
        vetor[c].codigo = c;
        c++;
    }

    fclose(arquivo);
    return n; //retornando o total para usar no backup
}

/********************************************************************************************************************************/

void locar(){
  FILE *arquivo;
  int i=0, cod, unidade;

  if((arquivo=fopen("entrada.txt", "r+"))==NULL){
        printf("Erro ao abrir o arquivo!");
  }

  else{
    printf("Insira o código do filme:\n");
    scanf("%d", &cod);

    while((vetor[i].codigo != cod) && (i<41)){
      i++;
    }

    if(vetor[i].codigo == cod){
      printf("Quantas unidades você deseja locar?\n");
      scanf("%d", &unidade);

      if(unidade > vetor[i].quantidade){
        printf("Essa quantidade não está disponível. Possuímos apenas %d unidades.\n", vetor[i].quantidade);
      }else{
        printf("Sua locação foi realizada com sucesso!!!\n\n");
        vetor[i].quantidade = vetor[i].quantidade - unidade;
        printf("Nosso acervo possui %d unidades restantes do filme %s.\n", vetor[i].quantidade, vetor[i].titulo);
      }
    }

    else{
      printf("Código não encontrado, tente novamente.\n");
    }

    fclose(arquivo);
  }
}

/********************************************************************************************************************************/

void entregar(){
  FILE *arquivo;
  int i=0, cod, unidade;

  if((arquivo=fopen("entrada.txt", "r+"))==NULL){
        printf("Erro ao abrir o arquivo!");
  }

  else{

    printf("Insira o código do filme:\n");
    scanf("%d", &cod);


    while((vetor[i].codigo != cod) && (i<41)){
      i++;
    }

    if(vetor[i].codigo == cod){
      printf("Quantas unidades você está entregando?\n");
      scanf("%d", &unidade);

        printf("Sua entrega foi realizada com sucesso!!!\n\n");
        vetor[i].quantidade = vetor[i].quantidade + unidade;
        printf("Nosso acervo possui %d unidades restantes do filme %s.\n", vetor[i].quantidade, vetor[i].titulo);
      }

    else{
      printf("Código não encontrado, tente novamente.\n");
    }

    fclose(arquivo);
    }
  }

/********************************************************************************************************************************/

int buscacodigo(){
    __fpurge(stdin);

    FILE *arquivo;
    int cod;
    int i=0;

    printf("Insira o código:\n");
    scanf("%d", &cod);

    if((arquivo=fopen("entrada.txt", "r+"))==NULL){
          printf("Erro ao abrir o arquivo!");
    }

    else{
      while((vetor[i].codigo != cod) && (i<41)){
        i++;
      }

      if(vetor[i].codigo == cod){
        imprimir(i);
      }else{
        printf("Desculpe, não encontramos esse código no nosso acervo.\n");
      }
    }

    fclose(arquivo);

    return 0;
  }

/********************************************************************************************************************************/

int buscanome(){
    __fpurge(stdin);

    FILE *arquivo;
    char nome[100];
    int i=0;

    printf("Insira o título:\n");
    scanf("%[^\n]s", &nome); //precisou de [^\n] para salvar apos o espaço

    if((arquivo=fopen("entrada.txt", "r+"))==NULL){
          printf("Erro ao abrir o arquivo!");
        }

        else{

          while((strcasecmp(vetor[i].titulo, nome)!=0) && (i<41)){
            i++;
          }

          if(strcasecmp(vetor[i].titulo, nome)==0){
            imprimir(i);
          }else{
            printf("Desculpe, não encontramos esse título no nosso acervo.\n");
          }
        }

    fclose(arquivo);
    return 0;
  }

/********************************************************************************************************************************/

int buscaano(){
  __fpurge(stdin);

  FILE *arquivo;
  int ano;
  int i=0, controle=0;


  printf("Insira o ano:\n");
  scanf("%d", &ano);

  if((arquivo=fopen("entrada.txt", "r+"))==NULL){
        printf("Erro ao abrir o arquivo!");
  }

  else{
    while(i<41){

      if(vetor[i].ano == ano){
        imprimir(i);
      i++;
      controle++;
    }else{
      i++;
    }
  }
}

if(controle=0){
  printf("Não encontramos título algum com esse ano.\n");
}

  fclose(arquivo);
  return 0;
}

/********************************************************************************************************************************/

int buscagenero(){
  __fpurge(stdin);

  FILE *arquivo;
  char genero[10];
  int i=0, controle=0;

  printf("Insira o genero:\n");
  scanf("%s", &genero);

  if((arquivo=fopen("entrada.txt", "r+"))==NULL){
        printf("Erro ao abrir o arquivo!");
      }

      else{



        while(i<41){

          if(strcasecmp(vetor[i].genero, genero)==0){
            imprimir(i);
          i++;
          controle++;
          }else{
          i++;
          }
          }
          }

          if(controle=0){
          printf("Não encontramos título algum com esse genero.\n");
          }

  fclose(arquivo);
  return 0;
}

/********************************************************************************************************************************/

int imprimir(int i){ //funcao utilizada na busca para imprimir todos os filmes que estao dentro da informa�ao digitada pelo usuario

  	FILE *arquivo;


  	if((arquivo=fopen("entrada.txt", "rt"))==NULL){
          printf("Erro ao abrir o arquivo!");
    }


          printf("\nCODIGO: %d\n", vetor[i].codigo);
          printf("TITULO: %s\n", vetor[i].titulo);
          printf("ANO: %d\n", vetor[i].ano);
          printf("QUANTIDADE: %d\n", vetor[i].quantidade);
          printf("GENERO: %s\n\n", vetor[i].genero);

  fclose(arquivo);

  return 0;
}

/********************************************************************************************************************************/

int buscar(){ //funcao que pergunta ao usuario o tipo de busca que ele deseja fazer
  __fpurge(stdin);

  int opcao=0;

  while(opcao != 5){

    printf("\n\n\nPor qual modo você deseja pesquisar no nosso acervo?\n");
    printf("1 - Pesquisa por código\n");
    printf("2 - Pesquisa por título\n");
    printf("3 - Pesquisa por ano\n");
    printf("4 - Pesquisa por gênero\n");
    printf("5 - Sair da busca\n");
    scanf("%d", &opcao);

    switch(opcao){
      case 1:
      buscacodigo();
      break;

      case 2:
      buscanome();
      break;

      case 3:
     buscaano();
      break;

      case 4:
     buscagenero();
      break;

      case 5:
      printf("Voltando para o menu principal...\n");
      break;

      default:
      printf("Opção inválida, tente novamente.\n");
      break;

    }

  }

  return 0;
}

/********************************************************************************************************************************/

void imprimirtudo(){

  __fpurge(stdin);

	FILE *arquivo;
	int c=0;

	if((arquivo=fopen("entrada.txt", "rt"))==NULL){
        printf("Erro ao abrir o arquivo!");
  }


    while(c<41){

        printf("\nCODIGO: %d\n", vetor[c].codigo);
        printf("TITULO: %s\n", vetor[c].titulo);
        printf("ANO: %d\n", vetor[c].ano);
        printf("QUANTIDADE: %d\n", vetor[c].quantidade);
        printf("GENERO: %s\n\n", vetor[c].genero);
        c++;
	}
fclose(arquivo);
}

/********************************************************************************************************************************/
void imprimirselecao(){ //procedimento que pergunta o tipo de impress�o

	int op=0, n;

 n = carregar();

while(op != 3){

    printf("\n\n\nSelecione o tipo de impressão\n");
    printf("1 - Imprimir acervo completo\n");
    printf("2 - Imprimir por nome do filme\n");
    printf("3 - Voltar ao programa principal\n");
    scanf("%d", &op);

    switch(op){
      case 1:
      imprimirtudo();
      break;

      case 2:
      buscanome(); //reutilizamos a funcao de busca por titulo j� que ela faz a mesma coisa que precisamos aqui
      break;

      case 3:
      printf("Voltando ao menu principal...\n");
      break;

      default:
      printf("Opção inválida, tente novamente.\n");
      break;

    }

  }
  }




  /********************************************************************************************************************************/

void salvar(int i, FILE *arquivobackup){ //funcao que salva, � utilizada nas duas formas de backup

  char string[116];

  sprintf(string, "%s;%d;%d;%s\n", vetor[i].titulo, vetor[i].ano, vetor[i].quantidade, vetor[i].genero);
  fprintf(arquivobackup, "%s", string); //salvando cada linha do arquivo
  printf("%s", string);

}

/********************************************************************************************************************************/


int backup(int n){ //backup do acervo inteiro atualiza, recebe o numero de filmes "n" como parametro
FILE *arquivobackup;
char total[3];
int i;



if((arquivobackup=fopen("entrada_backup.txt", "w+"))==NULL){
      printf("Erro ao abrir o arquivo!");
}

else{

  sprintf(total, "%d\n", n); //salvando o total de filmes na string "total"
  printf("%s", total);
  fprintf(arquivobackup, "%s", total); //gravando na primeira linha do arquivo o total de filmes

  for(i=0; i<41; i++){
  salvar(i, arquivobackup); //funcao que salva em um arquivo baseada na posicao do vetor e ponteiro
}
}

fclose(arquivobackup);

}

/********************************************************************************************************************************/


int backup_ano(FILE *arquivobackup2){ //funcao que procura os filmes por ano e os salva em um arquivo
  __fpurge(stdin);

  int ano;
  int i=0, controle=0;


  printf("Insira o ano:\n");
  scanf("%d", &ano);


    while(i<41){

      if(vetor[i].ano == ano){
      salvar(i, arquivobackup2);
      i++;
      controle++;

	}else{
      i++;
    }
  }

if(controle=0){
  printf("O arquivo de backup está vazio, não encontramos titulo algum com esse ano.\n");
}

  return 0;
}


/********************************************************************************************************************************/

int backup_genero(FILE *arquivobackup2){ //funcao que procura os filmes por ano e os salva em um arquivo
  __fpurge(stdin);


  char genero[10];
  int i=0, controle=0;

  printf("Insira o genero:\n");
  scanf("%s", &genero);


        while(i<41){

          if(strcasecmp(vetor[i].genero, genero)==0){ //strcasecmp serve para ignorar se a letra � maiuscula ou minuscula
          salvar(i, arquivobackup2);
          i++;
          controle++;

		  }else{
          i++;
          }
          }


		  if(controle=0){
          printf("O arquivo de backup está vazio, não encontramos título algum com esse genero.\n");
          }
  return 0;
}



/********************************************************************************************************************************/

int backupselect(int n){

FILE *arquivobackup2;
char string[116], total[3];
int i, op=0;



if((arquivobackup2=fopen("filmes_backup.txt", "w+"))==NULL){
      printf("Erro ao abrir o arquivo!");
}

else{

while(op!=1){ //se selecionar para sair ou imprimir, o op fica com o valor de 1 e sa�mos, isso foi feito para n�o ficar repetindo ap�s a pessoas selecionar 1 ou 2

    __fpurge(stdin);
    printf("Selecione o tipo de pesquisa:\n");
    printf("1 - Pesquisa por ano\n");
    printf("2 - Pesquisa por genero\n");
    printf("3 - Voltar ao programa principal\n");
    scanf("%d", &op);

    switch(op){
      case 1:
      backup_ano(arquivobackup2); //chamando a funcao que busca por ano e salva os filmes em um arquivo de texto
      op = 1;
      break;

      case 2:
      backup_genero(arquivobackup2); //chamando a funcao que busca por genero e salva os filmes em um arquivo de texto
      op = 1;
      break;

      case 3:
      printf("Voltando ao menu principal...\n");
      op = 1;
      break;

      default:
      printf("Opção inválida, tente novamente.\n");
      break;

    }

  }
  }


fclose(arquivobackup2);

}
/********************************************************************************************************************************/
