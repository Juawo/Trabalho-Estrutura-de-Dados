#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gerador.h"
#include "ordenacao.h"

#define NUM_TAMANHOS 9

// Tamanhos das bases de dados para os testes
int tamanhos[] = {100, 500, 1000, 5000, 30000, 80000, 100000, 150000, 200000};

// Estrutura para armazenar os algoritmos de ordenação e seus nomes
typedef struct {
    const char *nome;
    void (*funcao)(int *, int);
} MetodoOrdenacao;

// Função para salvar os resultados no arquivo
void salvar_resultado(const char *metodo, int tamanho, double tempo_gasto) {
    FILE *arquivo = fopen("resultados_sorts.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    fprintf(arquivo, "%s -> base de dados = %d -> tempo = %.6f s\n", metodo, tamanho, tempo_gasto);
    fclose(arquivo);
}

int main() {
    srand(time(NULL));

    // Lista de algoritmos de ordenação
    MetodoOrdenacao metodos[] = {
        {"Bubble Sort", bubble_sort},
        {"Selection Sort", selection_sort},
        {"Insertion Sort", insertion_sort},
        {"Merge Sort", merge_sort},
        {"Quick Sort", quick_sort},
        {"Counting Sort", counting_sort}
    };

    int num_metodos = sizeof(metodos) / sizeof(metodos[0]);

    // Itera sobre cada método de ordenação
    for (int i = 0; i < num_metodos; i++) {
        // Itera sobre cada tamanho da base de dados
        for (int j = 0; j < NUM_TAMANHOS; j++) {
            int qtd = tamanhos[j];

            // Aloca a base de dados
            int *base = (int *)malloc(qtd * sizeof(int));
            if (base == NULL) {
                printf("Erro ao alocar memória para %d elementos\n", qtd);
                return 1;
            }

            gerar_base_dados(base, qtd);

            // Mede o tempo de execução
            double tempo_gasto = medir_tempo(metodos[i].funcao, base, qtd);
            printf(" %s -> base de dados = %d -> tempo gasto = %.6f segundos\n", metodos[i].nome, qtd, tempo_gasto);
            salvar_resultado(metodos[i].nome, qtd, tempo_gasto);

            free(base);
        }
    }

    printf("\nTodos os testes foram concluídos e salvos em 'resultados.txt'!\n");
    return 0;
}
