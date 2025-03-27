#include <stdio.h>
#include <stdlib.h>
#include "ordenacao.h"
#include <time.h>

void listar_base(int  base_dados[], int qtd)
{
    for (int i = 0; i < qtd; i++)
    {
        printf("| base_dados[%d] = %d |\n", i, base_dados[i]);
    }
}

double medir_tempo(void (*sort_function)(int *, int), int base_dados[], int qtd)
{
    clock_t inicio, fim;
    inicio = clock();
    sort_function(base_dados, qtd);
    fim = clock();

    return ((double)(fim - inicio) / CLOCKS_PER_SEC);
}

void bubble_sort(int  base_dados[], int qtd)
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

// Selection Sort
void selection_sort(int  base_dados[], int qtd)
{
    for (int i = 0; i < qtd - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < qtd; j++)
        {
            if (( base_dados)[j] < ( base_dados)[min_idx])
            {
                min_idx = j;
            }
        }
        // Troca os valores
        int temp = ( base_dados)[i];
        ( base_dados)[i] = ( base_dados)[min_idx];
        ( base_dados)[min_idx] = temp;
    }
}

// Insertion Sort
void insertion_sort(int  base_dados[], int qtd)
{
    for (int i = 1; i < qtd; i++)
    {
        int chave = ( base_dados)[i];
        int j = i - 1;
        while (j >= 0 && ( base_dados)[j] > chave)
        {
            ( base_dados)[j + 1] = ( base_dados)[j];
            j--;
        }
        ( base_dados)[j + 1] = chave;
    }
}

// Merge Sort - Função auxiliar para mesclar os subarrays
void merge(int arr[], int esquerda, int meio, int direita)
{
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[esquerda + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    int i = 0, j = 0, k = esquerda;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

// Merge Sort Recursivo
void merge_sort_rec(int arr[], int esquerda, int direita)
{
    if (esquerda < direita)
    {
        int meio = esquerda + (direita - esquerda) / 2;
        merge_sort_rec(arr, esquerda, meio);
        merge_sort_rec(arr, meio + 1, direita);
        merge(arr, esquerda, meio, direita);
    }
}

// Merge Sort Wrapper
void merge_sort(int  base_dados[], int qtd)
{
    merge_sort_rec( base_dados, 0, qtd - 1);
}

// Quick Sort - Função auxiliar para particionar o array
int partition(int arr[], int baixo, int alto)
{
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j < alto; j++)
    {
        if (arr[j] < pivo)
        {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[alto];
    arr[alto] = temp;
    return (i + 1);
}

// Quick Sort Recursivo
void quick_sort_rec(int arr[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = partition(arr, baixo, alto);
        quick_sort_rec(arr, baixo, pi - 1);
        quick_sort_rec(arr, pi + 1, alto);
    }
}

// Quick Sort Wrapper
void quick_sort(int  base_dados[], int qtd)
{
    quick_sort_rec( base_dados, 0, qtd - 1);
}

// Counting Sort
void counting_sort(int  base_dados[], int qtd)
{
    int max_valor = 0;
    for (int i = 0; i < qtd; i++)
    {
        if (( base_dados)[i] > max_valor)
        {
            max_valor = ( base_dados)[i];
        }
    }

    int *contagem = calloc(max_valor + 1, sizeof(int));
    int *saida = malloc(qtd * sizeof(int));

    for (int i = 0; i < qtd; i++)
    {
        contagem[( base_dados)[i]]++;
    }

    for (int i = 1; i <= max_valor; i++)
    {
        contagem[i] += contagem[i - 1];
    }

    for (int i = qtd - 1; i >= 0; i--)
    {
        saida[contagem[( base_dados)[i]] - 1] = ( base_dados)[i];
        contagem[( base_dados)[i]]--;
    }

    for (int i = 0; i < qtd; i++)
    {
        ( base_dados)[i] = saida[i];
    }

    free(contagem);
    free(saida);
}