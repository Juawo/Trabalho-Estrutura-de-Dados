#include <stdio.h>
#include "ordenacao.h"

void listar_base(int *base_dados[], int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        printf("| base_dados[%d] = %d |\n", i, base_dados[i]);
    }
}


void bubble_sort(int *base_dados[], int qtd)
{
    for (int i = 0; i < qtd - 1; i++)
    {
        for (int j = 0; j < qtd - i - 1; j++)
        {
            if (base_dados[j] > base_dados[j + 1])
            {
                int temp = base_dados[j];
                base_dados[j] = base_dados[j + 1];
                base_dados[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int *base_dados[], int qtd)
{

}

void insertion_sort(int *base_dados[], int qtd)
{

}

void merge_sort(int *base_dados[], int qtd)
{

}

void quick_sort(int *base_dados[], int qtd)
{

}

void counting_sort(int *base_dados[], int qtd)
{

}