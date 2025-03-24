#include <stdio.h>
#include <stdlib.h>
#include "gerador.h"

void gerar_base_dados(int *vetor, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        vetor[i] = rand() % 100;
    }
}