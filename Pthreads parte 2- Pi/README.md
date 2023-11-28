# Pthreads parte 2- Pi
Assim como na parte 1 de Pthreads, multiplicação matriz-vetor, a função fornecida funciona corretamente para a divisão do trabalho entre as threads
e para obter o resultado pedido pelo exercício, sem precisar de ajustes. Porém, ao utilizar multiprocessamento, problemas são encontrados, que desta vez precisam ser resolvidos com o uso
do mutex.


Para utilizar esta função e realizar os exercícios propostos, é necessario definir a variável global `sum`, um número de threads e limite de iterações, e uma main que chamará a função, 
utilizando pthreads para operá-la com multiprocessamento, sem se esquecer de multiplicar o resultado do código por 4, já que a fórmula de Lebniz fornece apenas 1/4 de pi.
Ao utilizar o código com mais de uma thread, e sem o uso de um mutex, são notadas inconsistências no resultado fornecido. Quanto mais threads e iterações, mais frequentes e 
danosas estas inconsistências.


***Todos os testes a seguir foram feitos utilizando um limite de iterações (n) de 100000, e um limite de threads (THREAD_LIMIT) de 25.***


### Testes inconsistentes do Pi sem mutex:

![alt](/Pthreads%20parte%202-%20Pi/assets/1.png)


![alt](/Pthreads%20parte%202-%20Pi/assets/2.png)


![alt](/Pthreads%20parte%202-%20Pi/assets/3.png)


Apesar do número te iterações e threads ser idêntico para cada teste, os resultados foram divergentes. Isso ocorre pois há uma condição de corrida ocorrendo na variável global `sum`,
fazendo com que operações executadas nela em cada thread ocorram simultaneamente, constantemente utilizando valores anteriores de `sum` em suas operações, e sobrescrevendo o resultado 
fornecido por outras operações. 


O mutex é capaz de fazer threads aguardarem sua vez para executar uma seção do código, tornando-o extremamente útil para impedir diferentes threads de entrarem em conflito modificando a 
mesma variável. Ele será implementado da seguinte maneira:


![alt](/Pthreads%20parte%202-%20Pi/assets/5.png)


Ao substituir `sum` por uma variável `temp` própria de cada thread durante o loop da fórmula de Leibniz, permitimos que múltiplas threads façam sua parte do cálculo sem constantemente
travar e destravar a global `sum` usando o Mutex. Só o que precisamos fazer é incrementar `sum` pela `temp` quando o loop for finalizado, permitindo assim que todas as threads trabalhem
juntas sem se interromper constantemente.


Após a implementação do mutex, o uso de múltiplas threads na função é viável, e se torna consistente, exibindo sempre o mesmo resultado sem grandes perdas de performance. 


![alt](/Pthreads%20parte%202-%20Pi/assets/4.png)


Ao testar o código, note que o número de iterações deve ser divisível pelo número de threads, ou o número de iterações processadas será menor que o desejado.
