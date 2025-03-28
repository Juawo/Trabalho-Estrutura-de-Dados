# Projeto de Comparação de Algoritmos de Ordenação

Este projeto tem como objetivo implementar e comparar o desempenho de diferentes algoritmos de ordenação. Ele foi desenvolvido como parte do estudo de Estruturas de Dados, utilizando a linguagem C. Através deste projeto, é possível analisar o tempo de execução de cada algoritmo para diferentes tamanhos de bases de dados.

## Estrutura do Projeto

O projeto é composto pelos seguintes arquivos:

- **`main.c`**: Arquivo principal que permite ao usuário interagir com o programa, escolhendo o algoritmo de ordenação e o tamanho da base de dados.
- **`avaliacaoAutomatica.c`**: Realiza testes automáticos de desempenho para todos os algoritmos de ordenação implementados, salvando os resultados em um arquivo de texto.
- **`ordenacao.h` e `ordenacao.c`**: Contêm as implementações dos algoritmos de ordenação, como Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort e Counting Sort.
- **`gerador.h` e `gerador.c`**: Contêm a função para gerar bases de dados aleatórias.
- **`resultados_sorts.txt`**: Arquivo onde os resultados dos testes automáticos são armazenados.
- **`README.md`**: Documento explicativo do projeto e tabela com os resultados obtidos.

## Algoritmos Implementados

Os seguintes algoritmos de ordenação foram implementados:

1. **Bubble Sort**: Algoritmo simples baseado em trocas repetidas de elementos adjacentes.
2. **Selection Sort**: Seleciona o menor elemento e o coloca na posição correta.
3. **Insertion Sort**: Insere elementos em suas posições corretas em um subarray ordenado.
4. **Merge Sort**: Algoritmo baseado na técnica de divisão e conquista.
5. **Quick Sort**: Algoritmo eficiente que utiliza a técnica de particionamento.
6. **Counting Sort**: Algoritmo não comparativo baseado em contagem de elementos.

## Funcionamento

1. **Execução Manual (`main.c`)**:

   - O usuário escolhe o algoritmo de ordenação e o tamanho da base de dados.
   - O programa gera uma base de dados aleatória e mede o tempo de execução do algoritmo escolhido.

2. **Execução Automática (`avaliacaoAutomatica.c`)**:
   - Testa todos os algoritmos de ordenação para diferentes tamanhos de bases de dados.
   - Os resultados são exibidos no terminal e salvos no arquivo `resultados_sorts.txt`.

## Ambiente de Testes

Os testes foram realizados em um notebook com as seguintes especificações:

- **Processador**: Intel Core i3 de 7ª geração
- **Memória RAM**: 4GB DDR4 2400MHz

É importante destacar que os resultados apresentados podem variar dependendo do hardware utilizado. Máquinas com processadores mais rápidos, maior quantidade de memória RAM ou diferentes arquiteturas podem apresentar tempos de execução distintos para os mesmos algoritmos e tamanhos de bases de dados. Portanto, os tempos registrados neste projeto são específicos para o ambiente de testes descrito acima.

## Resultados

Os resultados obtidos para cada algoritmo e tamanho de base de dados estão apresentados na tabela abaixo:

| Método de Ordenação | Base de Dados | Tempo (s)  |
| ------------------- | ------------- | ---------- |
| Bubble Sort         | 100           | 0.000154   |
| Bubble Sort         | 500           | 0.003049   |
| Bubble Sort         | 1000          | 0.011554   |
| Bubble Sort         | 5000          | 0.148254   |
| Bubble Sort         | 30000         | 4.009516   |
| Bubble Sort         | 80000         | 27.513993  |
| Bubble Sort         | 100000        | 42.886987  |
| Bubble Sort         | 150000        | 96.714914  |
| Bubble Sort         | 200000        | 174.790515 |
| Selection Sort      | 100           | 0.000029   |
| Selection Sort      | 500           | 0.000502   |
| Selection Sort      | 1000          | 0.001812   |
| Selection Sort      | 5000          | 0.049034   |
| Selection Sort      | 30000         | 1.573784   |
| Selection Sort      | 80000         | 11.120934  |
| Selection Sort      | 100000        | 17.155942  |
| Selection Sort      | 150000        | 38.573908  |
| Selection Sort      | 200000        | 68.496389  |
| Insertion Sort      | 100           | 0.000019   |
| Insertion Sort      | 500           | 0.000293   |
| Insertion Sort      | 1000          | 0.001037   |
| Insertion Sort      | 5000          | 0.031017   |
| Insertion Sort      | 30000         | 0.891573   |
| Insertion Sort      | 80000         | 6.123621   |
| Insertion Sort      | 100000        | 9.563467   |
| Insertion Sort      | 150000        | 21.470546  |
| Insertion Sort      | 200000        | 38.111177  |
| Merge Sort          | 100           | 0.000031   |
| Merge Sort          | 500           | 0.000175   |
| Merge Sort          | 1000          | 0.000337   |
| Merge Sort          | 5000          | 0.001795   |
| Merge Sort          | 30000         | 0.010494   |
| Merge Sort          | 80000         | 0.030625   |
| Merge Sort          | 100000        | 0.036167   |
| Merge Sort          | 150000        | 0.058085   |
| Merge Sort          | 200000        | 0.078517   |
| Quick Sort          | 100           | 0.000013   |
| Quick Sort          | 500           | 0.000067   |
| Quick Sort          | 1000          | 0.000144   |
| Quick Sort          | 5000          | 0.001112   |
| Quick Sort          | 30000         | 0.019450   |
| Quick Sort          | 80000         | 0.126312   |
| Quick Sort          | 100000        | 0.189212   |
| Quick Sort          | 150000        | 0.410025   |
| Quick Sort          | 200000        | 0.720172   |
| Counting Sort       | 100           | 0.000006   |
| Counting Sort       | 500           | 0.000014   |
| Counting Sort       | 1000          | 0.000023   |
| Counting Sort       | 5000          | 0.000086   |
| Counting Sort       | 30000         | 0.000441   |
| Counting Sort       | 80000         | 0.001233   |
| Counting Sort       | 100000        | 0.002024   |
| Counting Sort       | 150000        | 0.003643   |
| Counting Sort       | 200000        | 0.004876   |

## Compilação e Execução

Para compilar e executar o projeto, utilize os seguintes comandos no terminal:

```bash
gcc -o main main.c ordenacao.c gerador.c avaliacaoAutomatica.c
./main
```

ou

```bash
gcc -o avaliacaoAutomatica avaliacaoAutomatica.c ordenacao.c gerador.c
./avaliacaoAutomatica
```

## Conclusão

Através deste projeto, foi possível observar o desempenho de diferentes algoritmos de ordenação em relação ao tempo de execução. Os resultados demonstram que algoritmos como Merge Sort e Quick Sort são significativamente mais eficientes para grandes conjuntos de dados em comparação com Bubble Sort e Selection Sort. O Counting Sort, por sua vez, se destacou em conjuntos de dados com valores limitados.
