#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 10


typedef struct produto{
    int codigo;
    char nome[TAM];
    float preco;
}tp_produto;

typedef struct nodo{
    tp_produto produto;
    struct nodo *next;
    struct nodo *prev;
}tp_nodo;

typedef struct lista{
    int nItens;
    struct nodo *first;
    struct nodo *last;
}tp_lista;

tp_lista *inicializar(tp_lista *sentinela) {

    sentinela = (tp_nodo*)malloc(sizeof(sentinela)); //GERA U UM ENDEREÇO DE MEMORIA PARA A SENTINELA;
    sentinela -> first = NULL;
    sentinela -> last = NULL;
    sentinela -> nItens = 0;

    return sentinela;
}





tp_lista *inserirNodo(tp_lista *sentinela){

    tp_nodo *novoNodo; // CRIO NOVA VARIAVEL ALEATORIA 
    tp_nodo *auxNodo;

    if(sentinela-> first == NULL && sentinela->last == NULL) // lISTA  SEM ENDEREÇO DE MEMORIA
    {
        novoNodo = (tp_nodo*)malloc(sizeof(novoNodo)); //GERA U UM ENDEREÇO DE MEMORIA PARA A NOVO NODO;
        printf("DIGITE O CODIGO\n"); 
        scanf("%d",&novoNodo -> produto.codigo);
        printf("DIGITE O NOME\n"); 
        scanf("%s", novoNodo -> produto.nome);
        printf("DIGITE O PRECO\n"); 
        scanf("%f",&novoNodo -> produto.preco);
        sentinela -> first = novoNodo;
        sentinela -> last = novoNodo;
        sentinela -> nItens = sentinela -> nItens+1;

        novoNodo->next = NULL;
        novoNodo->prev = NULL;

        return sentinela;

        
    }else{
        auxNodo = sentinela -> last;
        novoNodo = (tp_nodo*)malloc(sizeof(novoNodo)); //GERA U UM ENDEREÇO DE MEMORIA PARA A NOVO NODO;
        printf("DIGITE O CODIGO\n"); 
        scanf("%d",&novoNodo -> produto.codigo);
        printf("DIGITE O NOME\n"); 
        scanf("%s", novoNodo -> produto.nome);
        printf("DIGITE O PRECO\n"); 
        scanf("%f",&novoNodo -> produto.preco);

        
        auxNodo -> next = novoNodo; //NEXT APONTO PARA 0X12 = NOVO NODO;
        novoNodo-> next = NULL;
        novoNodo -> prev = auxNodo;
        sentinela -> last = novoNodo;
        sentinela -> nItens = sentinela -> nItens+1;

        return sentinela;

        
    }
 

}

tp_lista *mostrarItens(tp_lista *sentinela){

    tp_nodo *auxNodo;
    auxNodo = sentinela -> first;

    for (auxNodo; auxNodo != NULL; auxNodo = auxNodo -> next )
    {
        printf( "o codigo do produto é %d \n", auxNodo -> produto.codigo);
        printf( "o codigo do produto é %s \n", auxNodo -> produto.nome);
        printf( "o codigo do produto é %f \n", auxNodo -> produto.preco);
        printf("=========================\n");
    }
    


}


tp_lista *excluir (tp_lista *sentinela){




}


int main(){

    int y;
    tp_lista *listaSentinela = inicializar(listaSentinela); // VARIAVEL RECEBE 0X10
    int num_remove;
    
    do{
        printf("\nO que vc quer fazer com a lista: Digite:\n\n 1=Inserir()\n 2=Retirar()\n 3=Mostrar()\n 0=Sair\n\n");
        scanf("%d",&y);
        if(y==1){
           listaSentinela = inserirNodo(listaSentinela);
        }else if(y==2){
            
             printf("========= DIGITE O NUMERO QUE VOCÊ QUER REMOVER =========\n");
             scanf("%d",&num_remove);
             //lista = retirar(lista,num_remove);
        }else if(y==3){
             
             printf("============= VEJA SEUS PRODUTOS =============\n");
             mostrarItens(listaSentinela);
             
        }else if(y==0){
            break;
        }else{
             printf("Esta opcao e invalida!\n");
        }
    }while(y!=0);
     printf("\nVoce optou por sair do programa, as operacoes foram finalizadas\n");

     
     
     


}