#include <stdio.h>

// Função para realizar a busca binária
int buscaBinaria(int arr[], int tamanho, int elemento) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio] == elemento) {
            return meio;
        }

        if (arr[meio] > elemento) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    }

    return -1;
}

// Função para ordenar a lista usando o Bubble Sort
void bubbleSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; ++i) {
        for (int j = 0; j < tamanho - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos se estiverem fora de ordem
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Função para remover um elemento da lista
void removerElemento(int arr[], int *tamanho, int elemento) {
    int indice = buscaBinaria(arr, *tamanho, elemento);

    if (indice != -1) {
        // Desloca os elementos para a esquerda para preencher o espaço do elemento removido
        for (int i = indice; i < *tamanho - 1; ++i) {
            arr[i] = arr[i + 1];
        }

        // Atualiza o tamanho da lista
        (*tamanho)--;
        printf("Elemento removido com sucesso.\n");
    } else {
        printf("Elemento não encontrado na lista.\n");
    }
}

int main() {
    int tamanhoMaximo = 100;
    int lista[tamanhoMaximo];
    int tamanhoAtual = 0;

    // Solicita ao usuário inserir números na lista
    printf("Digite os números na lista (digite -1 para encerrar):\n");

    int numero;
    do {
        scanf("%d", &numero);

        // Verifica se o número é diferente de -1 antes de adicioná-lo à lista
        if (numero != -1) {
            lista[tamanhoAtual++] = numero;
        }
    } while (numero != -1 && tamanhoAtual < tamanhoMaximo);

    // Ordena a lista usando o Bubble Sort
    bubbleSort(lista, tamanhoAtual);

    // Solicita ao usuário digitar o número a ser removido
    int elementoProcurado;
    printf("Digite o número que deseja remover da lista: ");
    scanf("%d", &elementoProcurado);

    // Chama a função de remoção
    removerElemento(lista, &tamanhoAtual, elementoProcurado);

    // Exibe a lista atualizada
    printf("Lista atualizada:\n");
    for (int i = 0; i < tamanhoAtual; ++i) {
        printf("%d ", lista[i]);
    }
    printf("\n");

    return 0;
}
