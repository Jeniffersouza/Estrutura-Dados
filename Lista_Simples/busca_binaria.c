#include <stdio.h>

// Função para realizar a busca binária
int buscaBinaria(int arr[], int tamanho, int elemento) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        // Calcula o índice do meio
        int meio = inicio + (fim - inicio) / 2;

        // Verifica se o elemento está no meio
        if (arr[meio] == elemento) {
            return meio;  // Elemento encontrado, retorna o índice
        }

        // Se o elemento for menor, ignora a metade direita
        if (arr[meio] > elemento) {
            fim = meio - 1;
        }
        // Se o elemento for maior, ignora a metade esquerda
        else {
            inicio = meio + 1;
        }
    }

    return -1;  // Elemento não encontrado
}

int main() {
    // Exemplo de uso
    int lista[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tamanho = sizeof(lista) / sizeof(lista[0]);
    int elementoProcurado = 6;

    // Chama a função de busca binária
    int resultado = buscaBinaria(lista, tamanho, elementoProcurado);

    // Exibe o resultado
    if (resultado != -1) {
        printf("Elemento encontrado no índice %d.\n", resultado);
    } else {
        printf("Elemento não encontrado na lista.\n");
    }

    return 0;
}
