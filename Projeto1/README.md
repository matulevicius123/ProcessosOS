# Projeto 1

## Sobre o repositório
O programa a seguir foi criado utilizando a linguagem de programação C para realização do Projeto 1 da disciplina Sistemas Operacionais. 

Tanto a execução de cada teste, como o commit dos arquivos foi efetuado utilizando a plataforma AWS. 

![alt](/Projeto1/assets/add.png)


Visando consertar a condição de corrida presente no código fornecido, o projeto corrigiu o mau gerenciamento da concorrência das threads com a utilização da biblioteca pthread, garantindo, através do mutex, 
que apenas uma thread performe transações de cada vez, além de permitir que transações sejam feitas entre ambas as contas, pseudo-aleatoriamente trocando a conta que envia, e a conta que recebe em cada transação.

### Instalação
Instale o git com o comando `sudo dnf install git-all`. Com o git instalado, execute o comando `git clone https://github.com/matulevicius123/Trabalhos-SO/`.


Em seguida, instale o gcc utilizando `sudo yum install gcc`, e utilize o comando `cd Trabalhos-SO/Projeto1` para acessar a pasta contendo o código, e `gcc Projeto1.c -lpthread` para compilá-lo, gerando 
um arquivo `a.out` com o programa.


### Execução
Com o arquivo compilado, apenas execute-o com `./a.out`.

### Resultado da execução:

Forneça o valor de cada transação, e o valor inicial do saldo de cada conta. Em seguida, cada transação será exibida, mostrando qual das contas fez o envio, e qual das contas o recebeu, e se o programa
foi finalizado devido ao esvaziamento de uma das contas, ou se foi devido ao fim das 100 transações preparadas.

![alt](/Projeto1/assets/exec.png)

### Integrantes do grupo.
- Igor Benites Moura - 32275528
- João Pedro Maia Matulevicius Garcia - 32241429
