/*Criar um vetor de inteiros de tamanho 10, de modo que seja possível inserir valores via teclado e já
insira ordenadamente no vetor existente. Após todos os elementos serem inseridos, o programa
permite que busquemos os elementos do vetor via busca binária. Se encontrar o elemento, informa
em qual posição do vetor ele se encontra e caso não encontrar, informa que o elemento não foi
encontrado.*/

#include<stdio.h>
#include<stdlib.h>
#define MAXVET 10


void InserirOrdenado(int vetor[]){

    int i, j, aux;

    for (i = 0; i < MAXVET - 1; i++) {
        for (j = 0; j < MAXVET - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) { // verifica se o vetor da posicao j(comeca com 0 primeira posicao) e maior que o proximo conteudo do vetor
                aux = vetor[j];   //fazendo a troca para ordenar
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void ImprimirConteudoVet(int vetor[MAXVET]){
    int i;      
    for(i=0;i<10;i++){
        printf("Vetor[%d] = %d \n\n", i, vetor[i]);
    }
    
}
int BuscaBinaria(int vetor[MAXVET],int item){
    int comeco = 0;
    int fim = MAXVET -1; 

    printf("FIm: %d\n", fim);
   
    while(comeco<=fim){
        int meio = (comeco + fim) /2; //dividindo o vetor no meio   
   
        //printf("meio = %d\n", meio);
   
        if(vetor[meio] == item){//verificar se o item equivale ao vetor
            printf("Vetor encontrado!!\n");
            
            return meio;
        }if(vetor[meio] < item){
            comeco = meio + 1;
            printf("item esta a direita\n");
        }else{
            //printf("Elemento nao foi encontrado\n, Posicao: %d\n",vetor[]);            
            fim =meio -1;
            printf("Fim no else: %d\n3", fim);
        }   
    }

    return -1;
}

int main(){

    int i, vetor[MAXVET], item=0, opc, posicao;
    
    printf("Insira os valores das 10 possicoes no vetor:\n");

    for(i=0; i<10; i++){
        printf("Posicao [%d]: ", i);
        scanf("%d", &vetor[i]);
        
   }
        InserirOrdenado(vetor);
    do{
         printf("O que deseja fazer?\n\n Digite:\n (1)Imprimir conteudos do vetor\n (2)Encontrar conteudo do vetor\n (3)Sair\n");
         scanf("%d", &opc);

        if(opc == 1){
            ImprimirConteudoVet(vetor);
        }else if(opc==2){
            printf("Qual item deseja encontrar?\n");
            scanf("%d", &item);
            posicao=BuscaBinaria(vetor,item);
                if (posicao != -1) {
                    printf("Elemento encontrado na posicao %d do vetor.\n", posicao);
                } else {
                    printf("Elemento nao encontrado no vetor.\n");
                }

        }else if(opc==3){
            break;
        }else{
            printf("Opcao invalida");
        }
    }while(opc!=3);
        printf("Programa finalizado!!");

    return 0;
}