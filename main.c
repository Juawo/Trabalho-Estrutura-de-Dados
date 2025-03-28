#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gerador.h"
#include "ordenacao.h"

int main()
{
    srand(time(NULL));

    int qtd;
    int select;
    int loop = 1;

    while (loop == 1)
    {

        printf(" 1 - bubble_sort\n 2 - selection_sort\n 3 - insertion_sort\n 4 - merge_sort\n 5 - quick_sort\n 6 - counting_sort\n 7 - Exibir Base de Dados\n 0 - Sair\n");

        printf("Digite uma opção : \n");
        scanf("%d", &select);

        printf("Digite o tamanho da base de dados que deseja usar : \n");
        scanf("%d", &qtd);

        if (qtd <= 0 || qtd > 200001)
        {
            printf("Digite um tamanho válido, maior que 0 e menor que 200001\n");
            continue;
        }
        

        int *base = (int *)malloc(qtd * sizeof(int));
        if (base == NULL)
        {
            printf("Erro ao alocar memória para a base de dados\n");
            return 1;
        }

        gerar_base_dados(base, qtd);
        double tempo_gasto;

        switch (select)
        {
        case 1:
            tempo_gasto = medir_tempo(bubble_sort, base, qtd);
            printf(" --- Bubble Sort -> base de dados = %d -> tempo gasto = %.6f segundos ---\n ", qtd, tempo_gasto);
            break;

        case 2:
            tempo_gasto = medir_tempo(selection_sort, base, qtd);
            printf(" --- Selection Sort -> base de dados = %d -> tempo gasto = %.6f segundos ---\n ", qtd, tempo_gasto);
            break;

        case 3:
            tempo_gasto = medir_tempo(insertion_sort, base, qtd);
            printf(" --- Insertion Sort -> base de dados = %d -> tempo gasto = %.6f segundos ---\n ", qtd, tempo_gasto);
            break;

        case 4:
            tempo_gasto = medir_tempo(merge_sort, base, qtd);
            printf(" --- Merge Sort -> base de dados = %d -> tempo gasto = %.6f segundos ---\n ", qtd, tempo_gasto);
            break;

        case 5:
            tempo_gasto = medir_tempo(quick_sort, base, qtd);
            printf(" --- Quick Sort -> base de dados = %d -> tempo gasto = %.6f segundos ---\n ", qtd, tempo_gasto);
            break;

        case 6:
            tempo_gasto = medir_tempo(counting_sort, base, qtd);
            printf(" --- Counting Sort -> base de dados = %d -> tempo gasto = %.6f segundos ---\n ", qtd, tempo_gasto);
            counting_sort(base, qtd);
            break;

        case 7:
            listar_base(base, qtd);
            break;
            
        case 0:
            loop = 0;
            break;

        default:
            printf("Opção inválida\n");
            break;
        }

        if (loop != 0)
        {
            int sair;
            // listar_base(base, qtd);
            printf("Pressione qualquer número para sair\n");
            scanf("%d", &sair);
        }

        free(base);
    }

    return 0;
}