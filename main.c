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
    __uint8_t loop = 1;

    while (loop == 1)
    {

        printf("Digite o tamanho da base de dados : \n");
        scanf("%d", &qtd);

        if(qtd <= 0)
        {
            printf("Digite um tamanho válido, maior que 0 e menor que 200001\n");
            continue;;
        }

        printf(" 1 - bubble_sort\n 2 - selection_sort\n 3 - insertion_sort\n 4 - merge_sort\n 5 - quick_sort\n 6 - counting_sort\n");

        printf("Qual modelo de ordenação deseja usar : \n");
        scanf("%d", &select);

        int base[qtd];
        gerar_base_dados(base, qtd);

        switch (select)
        {
        case 1:
            bubble_sort(&base, qtd);
            break;
        case 2:
            selection_sort(&base, qtd);
            break;
        case 3:
            insertion_sort(&base, qtd);
            break;
        case 4:
            merge_sort(&base, qtd);
            break;
        case 5:
            quick_sort(&base, qtd);
            break;
        case 6:
            counting_sort(&base, qtd);
            break;
        case 0:
            loop = 0;
            break;

        default:
            printf("Opção inválida\n");
            break;
        }

        if(loop != 0)
        {
            listar_base(&base, qtd);
        }
    }

    return 0;
}