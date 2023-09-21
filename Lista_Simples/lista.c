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
    struct nodo *prox;
}tp_nodo;



tp_nodo *inserir(tp_nodo *lista){

    tp_nodo *novoLista; // CRIO NOVO ENDEREÇO PARA A LISTA

    if(lista == NULL) // lISTA  SEM ENDEREÇO DE MEMORIA
    {
        novoLista = (tp_nodo*)malloc(sizeof(novoLista)); //GERA U UM ENDEREÇO DE MEMORIA PARA A NOVA LISTA;
        printf("DIGITE O CÓDIGO\n"); 
        scanf("%d",&novoLista -> produto.codigo);
        printf("DIGITE O NOME\n"); 
        scanf("%s",&novoLista -> produto.nome);
        printf("DIGITE O CÓDIGO\n"); 
        scanf("%f",&novoLista -> produto.preco);
        novoLista ->prox = NULL;
        return novoLista;
        
    }else{
        novoLista = (tp_nodo*)malloc(sizeof(novoLista));

        printf("DIGITE O CÓDIGO\n"); 
        scanf("%d",&novoLista -> produto.codigo);
        printf("DIGITE O NOME\n"); 
        scanf("%s",&novoLista -> produto.nome);
        printf("DIGITE O CÓDIGO\n"); 
        scanf("%f",&novoLista -> produto.preco);
        novoLista ->prox = lista;

        lista = novoLista;

        return lista;
    }
 
}

 void mostra(tp_nodo *lista){

    for (lista;  lista!= NULL; lista = lista ->prox)
     {
        printf("O CODIGO DO PRODUTO É = %d\n", lista->produto.codigo);
     }
     
}

tp_nodo *retirar(tp_nodo *lista, int num_remove){
    
    tp_nodo *anterior = NULL;
    tp_nodo *auxiliar = lista;

     //SÓ SERVE PARA REMOVER O MEIO 

    while (auxiliar != NULL && auxiliar -> produto.codigo != num_remove) {
        anterior = auxiliar; //x30
        auxiliar = auxiliar -> prox; //x11
    }

    //CASO DO 3 
    if (anterior == NULL ){
        lista = auxiliar -> prox;
        return lista;
    }else{
        anterior -> prox = auxiliar-> prox;
        return lista;
    }

        //anterior -> prox = NULL; CASO DO 1
        //anterior -> prox = auxiliar-> prox; - CASO DO 2
        //CASO DO 3 

        
            
        



    return lista;
}



int main(){

    int y;
    tp_nodo *lista = NULL;
    int num_remove;
    
    do{
        printf("\nO que vc quer fazer com a lista: Digite:\n\n 1=Inserir()\n 2=Retirar()\n 3=Mostrar()\n 0=Sair\n\n");
        scanf("%d",&y);
        if(y==1){
           lista = inserir(lista);
        }else if(y==2){
            
             printf("========= DIGITE O NUMERO QUE VOCÊ QUER REMOVER =========\n");
             scanf("%d",&num_remove);
             lista = retirar(lista,num_remove);
        }else if(y==3){
             printf("=========================\n");
             printf("=============VEJA SUA LISTA = ============\n");
             mostra(lista);
        }else if(y==0){
            break;
        }else{
             printf("Esta opcao e invalida!\n");
        }
    }while(y!=0);
     printf("\nVoce optou por sair do programa, as operacoes foram finalizadas\n");

     
     
     


}

