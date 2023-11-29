#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 10


typedef struct produto{ 
    int codigo;
    char nome[TAM];
    float preco;
}tp_produto; // Representa a estrutura de um produto, contendo um código, um nome e um preço.

typedef struct nodo{
    tp_produto produto;
    struct nodo *next;
    struct nodo *prev;
}tp_nodo; //Representa um nó da lista dupla, contendo um produto, um ponteiro para o próximo nó e um ponteiro para o nó anterior.

typedef struct lista{
    int nItens; //número de itens na lista
    struct nodo *first;//ponteiro para o primeiro nó
    struct nodo *last;//ponteiro para o último nó


}tp_lista; //Representa a lista dupla, contendo o número de itens na lista, um ponteiro para o primeiro nó e um ponteiro para o último nó.

tp_lista *inicializar(tp_lista *sentinela) {

  //Inicializa a lista dupla, alocando memória para a sentinela (estrutura que guarda informações sobre a lista).

    sentinela = (tp_nodo*)malloc(sizeof(sentinela)); //GERA U UM ENDEREÇO DE MEMORIA PARA A SENTINELA;
    sentinela -> first = NULL; // first aponta pra null
    sentinela -> last = NULL; // last aponta pra null
    sentinela -> nItens = 0; // nItens aponta pra null

    return sentinela;
}



//Insere um novo nó na lista dupla. 

tp_lista *inserirNodo(tp_lista *sentinela){

    tp_nodo *novoNodo; // CRIO NOVA VARIAVEL ALEATORIA 
    tp_nodo *auxNodo;
   
    if(sentinela-> first == NULL && sentinela->last == NULL) // Verifica se a lista está vazia.
    {// Se estiver, cria um novo nó, solicita informações do produto 
        novoNodo = (tp_nodo*)malloc(sizeof(novoNodo)); //GERA U UM ENDEREÇO DE MEMORIA PARA A NOVO NO;

        printf("DIGITE O CODIGO\n"); 
        scanf("%d",&novoNodo -> produto.codigo);
        printf("DIGITE O NOME\n"); 
        scanf("%s", novoNodo -> produto.nome);
        printf("DIGITE O PRECO\n"); 
        scanf("%f",&novoNodo -> produto.preco);

        // atribui o novo nó como primeiro e último da lista.
        sentinela -> first = novoNodo;
        sentinela -> last = novoNodo;
        sentinela -> nItens = sentinela -> nItens+1;

        //next e prev fica null, pq tem só 1
        novoNodo->next = NULL;
        novoNodo->prev = NULL;

        return sentinela;
        //Se a lista estiver vazia, o novo nó se torna o primeiro e último nó.
        
    }else{   //Caso contrário, ele é adicionado ao final da lista.

        
        //variavel auxiliar que é = ao last da sentinela
        
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
    //Inicializa um ponteiro auxiliar para percorrer a lista, começando pelo primeiro nó.
    tp_nodo *auxNodo;
    auxNodo = sentinela -> first;

    for (auxNodo; auxNodo != NULL; auxNodo = auxNodo -> next )
    //Percorre a lista utilizando o ponteiro auxiliar. O loop continua enquanto auxNodo não for nulo.
    {//Imprime as informações 
        printf( "o codigo do produto é %d \n", auxNodo -> produto.codigo);
        printf( "o nome do produto é %s \n", auxNodo -> produto.nome);
        printf( "o preco do produto é %f \n", auxNodo -> produto.preco);
        printf("=========================\n");
    }
    


}


tp_lista *excluir(tp_lista *sentinela) {
    int codigo;

    tp_nodo *auxNodo, *prev, *next;

    if (sentinela->first == NULL) { // valida se a lista ta vazia
        printf("A lista está vazia. Nada a excluir.\n");
        return sentinela;
    }

    printf("Digite o código do produto que deseja excluir: ");
    scanf("%d", &codigo);

    auxNodo = sentinela->first;
    anterior = NULL;

    // Procurar o nodo com o código especificado
    while (auxNodo != NULL && auxNodo->produto.codigo != codigo) {
        prev = auxNodo;
        auxNodo = auxNodo->next;
    }

    if (auxNodo == NULL) {
        printf("Produto com o código %d não encontrado na lista.\n", codigo);
        return sentinela;
    }

    // Atualizar os ponteiros prev e next dos nodos adjacentes
    if (prev != NULL) {
        prev->next = auxNodo->next;
    } else {
        sentinela->first = auxNodo->next;
    }

    if (auxNodo->next != NULL) {
        auxNodo->next->prev = prev;
    } else {
        sentinela->last = prev;
    }

    // Liberar a memória do nodo excluído
    free(auxNodo);

    // Atualizar o número de itens na lista
    sentinela->nItens--;

    printf("Produto com código %d removido da lista.\n", codigo);

    return sentinela;
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
             listaSentinela = excluir(listaSentinela);
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
