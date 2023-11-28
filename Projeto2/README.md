## Introdução:

Projeto desenvolvido para a realização do Projeto 2 - Escada Rolante, o Problema E da Maratona de Programação da SBC - ICPC 2021.

### Integrantes:

- Igor Benites Moura - 32275528
- João Pedro Maia Matulevicius Garcia - 32241429

## Solução:

Começamos implementando uma estrutura `passageiro`, que irá comportar tanto o tempo de chegada de um passageiro, quanto a direção que ele deseja tomar na escada. O programa lê o arquivo 
de entrada `entrada.txt`, e com base na sua primeira linha, dinamicamente aloca uma array de passageiros. Ele então fornece tanto o array quanto o número de passageiros à função principal,
`escadaRolanteDupla`.


Na função `escadaRolanteDupla`, um loop é iniciado que persiste enquanto o número de passageiros processados não se iguale ao total. O primeiro passo é verificar se há algum passageiro na
fila, e se ele está livre para passar. Caso este seja o caso, incrementa-se o tempo, tempo de chegada e passageiros processados. Caso isto falhe, o passageiro atual é escolhido.
Se a escada estiver na direção -1 (parada), a direção e tempo de chegada são definidas para a do passageiro atual, e o passageiro selecionado e os processados são incrementados. 
Caso a direção do passageiro atual seja igual à da escada, o tempo, tempo de chegada, o passageiro selecionado e os processados são incrementados. 


Caso a direção tomada pelo próximo passageiro seja contrária à direção atual da escada, e ele só chegará após o passageiro atual chegue ao seu destino, o tempo levado à chegadado novo, 
e a escada é simplesmente parada, fazendo com que o passageiro esteja pronto para ser processado pelo caso da próxima parada na próxima iteração do loop. Se o passageiro que vai na direção
contrária chegar antes da conclusão da viagem do atual, ele é colocado no array de passageiros pendentes, o passageiro atual é incrementado, e o bool de fila é transformado em true, fazendo 
com que um passageiro que alcance esse caso seja processado pelo primeiro caso na próxima iteração do loop.


Iterações são feitas até que a condição se quebre, retornando o momento de chegada final, que é então exibido ao usuário.

## Compilação:


![alt](/Projeto1/assets/compilacao.png)


Basta compilar o arquivo-fonte utilizando o GCC. É simplesmente utilizar o comando `gcc projeto2.c` ou opcionalmente `gcc projeto2.c -o "projeto2.bin"` para dar ao arquivo um nome 
específico.

### Execução:

Após compilar como no passo anterior, basta utilizar o comando `./` seguido pelo nome especificado no passo anterior, ou `a.out` caso não seja fornecido um nome. Não esqueça de fornececer
um arquivo entrada.txt, com o formato detalhado no enunciado do projeto. (Exemplo no diretório.)



## Resultados


![alt](/Projeto1/assets/result.png)


