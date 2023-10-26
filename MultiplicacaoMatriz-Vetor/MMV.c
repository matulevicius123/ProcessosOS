// Nome: Igor Benites Moura / TIA: 32275528
// Nome: Joao Pedro Maia Matulevicius / TIA: 32241429
// O codigo apresentado pelo professor esta correto. So faltava criar a main e as threads corretamente para completa-lo

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define linhas 3
#define colunas 3

//matriz, vetor e vetor de resultado globais para que possam ser acessados por todas as threads e dentro da funcao
//ja que o x de resultados esta presente aqui, nao havera necessidade de juntar 
//o y de todas as threads posteriormente.
double A[linhas][colunas];
double x[colunas];
double y[linhas]; 

void *Pth_mat_vect(void* rank) {
    long my_rank = (long) rank;
    int i, j;
    int local_m = linhas / linhas;
    int my_first_row = my_rank * local_m;
    int my_last_row = (my_rank + 1) * local_m - 1;

        for (i = my_first_row; i <= my_last_row; i++) {
        for (j = 0; j < colunas; j++) {
            y[i] += A[i][j] * x[j];
        }
    }
    
    return NULL;
}

int main() {
    //O seguinte itera pela A e x e incrementa cada espaço com  um valor incrementado por 1
    //a cada item.
    int i, j = 0;
    double k = 0;
    //Portanto, o problema sera calculado para vetor [1, 2, 3] e matriz [[1, 2, 3]
    //                                                                   [4, 5, 6]
    //                                                                   [7, 8, 9]]

    for (i = 0; i < linhas; i++) {
        for (j = 0; j < colunas; j++) {
            k++;
            A[i][j] = k;
        }
    }
    
    k = 0;
    for (i = 0; i < colunas ; i++) {
        k++;
        x[i] = k;
    }

    //A partir daqui, geramos as threads e as armazenamos em um vetor.
    pthread_t* thread_handles;
    thread_handles = malloc(linhas * sizeof(pthread_t));

    //O mais eficiente e sempre utilizar uma thread por linha. Com menos, o problema nao e totalmente
    //paralelamente, e com excedentes, threads excessivas nao faram nada, apenas ocupando memoria.
    
    //Enviamos cada thread diretamente a funcao do enunciado.
    for (long thread = 0; thread < linhas; thread++) {
        pthread_create(&thread_handles[thread], NULL, Pth_mat_vect, (void*) thread);
    }

    //As threads voltarao e esperarao no join ate que todas estejam aqui.
    for (long thread = 0; thread < linhas; thread++) {
        pthread_join(thread_handles[thread], NULL);
    }

    //as threads serao liberadas e o y exibido.
    free(thread_handles);
    printf("Resultado: [ ");
    for (i = 0; i < linhas ; i++) {
            printf("%f ", y[i]);
    }
    printf("]");
    return 0;
}
