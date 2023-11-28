#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define LIMITE_THREADS 100
pthread_mutex_t mutex;
bool semSaldo = false;
bool inverter = false;

struct c {int saldo;};
typedef struct c conta;
conta from, to;
int valorTransferencia;

void *transferencia(void *arguments) {
  int random = rand() % 2;
  if (random % 2 == 0) {
    inverter = true;
  } else {
    inverter = false;
  }
  
  conta *conta1 = &from;
  conta *conta2 = &to;
  
  if (inverter == true) {
    conta1 = &to;
    conta2 = &from;
  }

  pthread_mutex_lock(&mutex);
  if ((*conta1).saldo <= 0 || (*conta2).saldo <= 0) {
    semSaldo = true;
    return (void *)1;
  }
  
  if ((*conta1).saldo >= valorTransferencia) {
    (*conta1).saldo -= valorTransferencia;
    (*conta2).saldo += valorTransferencia;
    if (inverter == true) {
      printf("Transferência de 'to' para 'from' completa!\nSaldo da conta from: %d\nSaldo da conta to: %d\n", from.saldo, to.saldo);
    } else {
      printf("Transferência de 'from' para 'to' completa!\nSaldo da conta from: %d\nSaldo da conta to: %d\n", from.saldo, to.saldo);
    }
  } else {
    if (inverter == true) {
        printf("Transferência incompleta! Valor da transferencia maior do que da conta sorteada.\nSaldo da conta 'to': %d\nValor da transferencia: %d\n", to.saldo, valorTransferencia);
      } else {
        printf("Transferência incompleta! Valor da transferencia maior do que da conta sorteada.\nSaldo da conta 'from': %d\nValor da transferencia: %d\n", from.saldo, valorTransferencia);
    }
  }
  pthread_mutex_unlock(&mutex);
  return (void *)0;
}

int main() {
  srand(time(NULL));
  pthread_mutex_init(&mutex, NULL);

  pthread_t vetorThreads[LIMITE_THREADS];
  int i;
  printf("Insira o valor que sera transferido entre contas.\n");
  scanf("%d", &valorTransferencia);
  printf("Insira o valor do saldo da conta 1.\n");
  scanf("%d", &from.saldo);
  printf("Insira o valor do saldo da conta 2.\n");
  scanf("%d", &to.saldo);

  if (valorTransferencia > from.saldo && valorTransferencia > to.saldo) {
    printf("Valor de transferencia maior do que ambas as contas. Transações são impossíveis. Finalizando o programa...");
    exit(0);
  }
  
  printf("Transferindo %d...\n", valorTransferencia);
  for (i = 0; i < LIMITE_THREADS; i++) {
    if (pthread_create(&vetorThreads[i], NULL, transferencia, NULL) != 0) {
      perror("O pthread_create falhou!");
      pthread_mutex_destroy(&mutex);
      exit(1);
    }
    if (semSaldo == true) {
      printf("O saldo foi zerado. Interrompendo as transferencias e encerrando o programa...\n");
      pthread_mutex_destroy(&mutex);
      exit(0);
    }
  }

  for (i = 0; i < LIMITE_THREADS; i++) {
    if (semSaldo == false) {
      pthread_join(vetorThreads[i], NULL);
    }
  }

  printf("Transferências finalizadas. Liberando a memoria e encerrando o programa...\n");
  pthread_mutex_destroy(&mutex);
  return 0;
}

