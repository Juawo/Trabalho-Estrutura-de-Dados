#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "gerador.h"


int main()
{
    srand(time(NULL));

    int base[30];
    gerar_base_dados(base, 30);

    return 0;
}