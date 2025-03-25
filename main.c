#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gerador.h"
#include "ordenacao.h"

int main()
{
    srand(time(NULL));

    __uint16_t qtd;
    __uint8_t select;

    // Definindo tamanho da base de dados
    printf("Digite o tamanho da base de dados : \n");
    scanf("%d", &qtd);

    printf(" 1 - bubble_sort\n 2 - selection_sort\n 3 - insertion_sort\n 4 - merge_sort\n 5 - quick_sort\n 6 - counting_sort\n");
    
    printf("Qual modelo de ordenação deseja usar : \n");
    scanf("%d", &select);

    int base[qtd];
    gerar_base_dados(base, qtd);

    switch (select)
    {
    case 1:
        bubble_sort(&base);
        break;
    case 2:
        selection_sort(&base);
        break;
    case 3:
        insertion_sort(&base);
        break;
    case 4:
        merge_sort(&base);
        break;
    case 5:
        quick_sort(&base);
        break;
    case 6:
        counting_sort(&base);
        break;

    default:
        printf("Opção inválida\n");
        break;
    }

    return 0;
}