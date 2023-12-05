   /*
Exercícios com listas duplamente encadeadas:

1) Implemente um programa para:
a) Inserir um produto na lista 
b) Remover um produto da lista
c) Alterar um produto
d) Imprimir a lista

2) Crie uma função que receba como parâmetro duas listas e um número inteiro, N, e retorne a lista resultante da inserção 
da segunda lista na primeira, sequencialmente, a partir da posição N da primeira lista.

3) Crie uma função que receba como parâmetro duas listas e retorne, numa terceira lista, a intersecção das duas primeiras.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct _produto{
	int codigo;
	char nome[20];
	float preco;
} TpProduto;

typedef struct _nodo{
	TpProduto produto;
	struct _nodo *prox;
	struct _nodo *anterior;
} TpNodo;

typedef struct _cabeca{
	int nItens;
	struct _nodo *primeiro;
	struct _nodo *ultimo;
} TpCabeca;

TpCabeca *inicializalista(){
	TpCabeca *novo=(TpCabeca*)malloc(sizeof(TpCabeca));
	novo->nItens=0;
	novo->primeiro=NULL;
	novo->ultimo=NULL;
	return novo;
}

TpCabeca *inserir(TpCabeca *cabecaMain, TpNodo *nodo){
	 
	if(cabecaMain->nItens == 0){
		TpNodo *novo = (TpNodo*)malloc(sizeof(TpNodo));

		printf("Digite o codigo\n");
		scanf("%d", &novo->produto.codigo);
		printf("Digite o nome\n");
		scanf("%s", novo->produto.nome);
		printf("Digite o valor\n");
		scanf("%f", &novo->produto.preco);

		novo -> prox= NULL;
		novo->anterior=NULL;
		cabecaMain->primeiro = novo;
		cabecaMain-> ultimo = novo;
		cabecaMain -> nItens++;
		return cabecaMain;
	}else{
		TpNodo *novo = (TpNodo*)malloc(sizeof(TpNodo));

		printf("Digite o codigo\n");
		scanf("%d", &novo->produto.codigo);
		printf("Digite o nome\n");
		scanf("%s", novo->produto.nome);
		printf("Digite o valor\n");
		scanf("%f", &novo->produto.preco);

		cabecaMain -> ultimo -> prox = novo;
		novo-> anterior = cabecaMain -> ultimo;
		cabecaMain-> ultimo = novo;
		cabecaMain-> nItens ++;
		return cabecaMain;
	}
}

void imprimir(TpCabeca *cabecaMain){

	TpNodo *pAux = 0;

	if(cabecaMain-> nItens == 0){
			printf("Lista esta vazia\n");
			cabecaMain =inicializalista();
		}else{
			printf("Elementos da lista:\n");
			for(pAux = cabecaMain -> primeiro; pAux != NULL; pAux = pAux -> prox ){
				 printf("Codigo: %d", pAux-> produto.codigo);
       			 printf("|| Nome: %s", pAux-> produto.nome);
        		 printf("|| Preco:  %.2f\n", pAux -> produto.preco);
				 printf("A quantidade de itens e: %d\n ", cabecaMain-> nItens); 
			}

	}
	
}	

TpCabeca *remover(TpCabeca *cabecaMain, TpNodo *nodo,int codigoMain){
	TpNodo *pAux = cabecaMain -> primeiro;

	if( cabecaMain -> nItens == 0){
		printf("Lista esta vazia, nao e possivel excluir!\n");
		cabecaMain =inicializalista();
	}else{
		//caso se o item a ser excluido seja o unico na lista
		
		
		if(pAux-> anterior == NULL && pAux -> prox == NULL && pAux-> produto.codigo == codigoMain){
			cabecaMain-> ultimo = NULL;
			cabecaMain -> primeiro = NULL;
			cabecaMain-> nItens --;
			return cabecaMain;
			//remove primeiro
		}else if(pAux -> anterior == NULL && pAux->produto.codigo == codigoMain){
			cabecaMain->primeiro = pAux-> prox;
			cabecaMain->primeiro->anterior=NULL;
			cabecaMain-> nItens --;
			return cabecaMain;
		}
		//remove ultimo
     for( ; pAux != NULL; pAux = pAux->prox){
        if(pAux->prox == NULL && pAux->produto.codigo == codigoMain){
			cabecaMain->ultimo = pAux->anterior;
			cabecaMain->ultimo->prox = NULL;
			cabecaMain->nItens--;
			return  cabecaMain;
		}else if (pAux->anterior != NULL && pAux->prox != NULL && pAux->produto.codigo == codigoMain){
                // Remove no meio
                pAux->anterior->prox = pAux->prox;
                pAux->prox->anterior = pAux->anterior;
                cabecaMain->nItens--;
                return cabecaMain;
		}
		 
	}
}
}

int main(){
	TpCabeca *cabeca;
	TpNodo *nodo =NULL;
    int opc=0;
	cabeca =inicializalista();

	do{
		printf("MENU\n");
		printf("Escolha a opcao:\n(1)Inserir elementos na lista dupla\n(2)Excluir elementos da lista dupla\n(3)Mostrar lista dupla\n(0)Sair do programa\n");
		scanf("%d", &opc);
		if(opc == 1){
			cabeca = inserir(cabeca, nodo);
		}else if(opc==2){
			int codigoMain;
			printf("Digite o o codigo a ser removido\n");
			scanf("%d", &codigoMain);
		
			cabeca = remover(cabeca, nodo, codigoMain);
		}else if(opc==3){
 			imprimir(cabeca);
		}else if(opc==0){
			break;
		}else{
			printf("Opcao invalida, digite novamente");
		}
}while(opc!=0);
    printf("Programa finalizado!!");
}

