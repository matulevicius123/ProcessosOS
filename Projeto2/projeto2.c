#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Estrutura para armazenar os dados de cada passageiro
typedef struct {
    int tempo;
    int direcao;
} passageiro;

//Funcao principal
int escadaRolanteDupla(passageiro* riders, int n) {
    passageiro currentRider = riders[0];
    passageiro* pendingRiders = (passageiro*)malloc(n/2 * sizeof(passageiro));

    int passageiroAtual = 0;
    int tempoChegada; 
    int direcaoAtual = -1;
    int frame = 0;
    bool fila = false;
    int restantes = 0;

    while (restantes != n) {
        if (fila && (riders[passageiroAtual].tempo > tempoChegada || passageiroAtual >= n)) {

            currentRider = pendingRiders[0];
            frame += 10;
            direcaoAtual = currentRider.direcao;
            tempoChegada = frame + 10;
            fila = false;
            restantes++;

        } else {
            currentRider = riders[passageiroAtual];

            if (direcaoAtual == -1) {
                frame = currentRider.tempo < frame ? frame : currentRider.tempo;
                direcaoAtual = currentRider.direcao;
                tempoChegada = currentRider.tempo + 10; 

                passageiroAtual++;
                restantes++;    
            } else if (direcaoAtual == currentRider.direcao) {
                frame = currentRider.tempo;
                tempoChegada = currentRider.tempo + 10;
                passageiroAtual++;
                restantes++;

            } else {
                if (riders[passageiroAtual].tempo > tempoChegada) {
                    frame = tempoChegada;
                    direcaoAtual = -1;
                }
                else if (riders[passageiroAtual].tempo <= tempoChegada) {
                    pendingRiders[0] = riders[passageiroAtual]; 
                    fila = true;
                    passageiroAtual++;
                }
            }
        }
    }
    frame += 10;
    return frame;
}

int main() {
    int n;
    passageiro* riders;
    FILE* file = fopen("entrada.txt", "r");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", "entrada.txt");
        exit(1);
    }
    fscanf(file, "%d", &n);
    riders = (passageiro*)malloc(n * sizeof(passageiro));

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d %d", &riders[i].tempo, &riders[i].direcao);
    }
    fclose(file);

    //readData("entrada.txt", riders, &n);
    int resultadoFinal = escadaRolanteDupla(riders, n);

    printf("Tempo final de parada: %d\n", resultadoFinal);
    return 0;
}
