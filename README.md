# Acesso compratilhado
Repositorio com programa em C com finalidade de simulação onde threads criam um produto e outras threads consomem
Aluno: João Luís Queiroz Castro de Almeida  
Turma: B  
Período: 3  
Cadeira: Infraestrutura de software  

## Objetivo
Crie uma implementação do problema do produtor consumidor utilizando threads. Esse
problema consiste em termos threads que produzem dados e também termos threads que
consomem esses dados. Uma forma comum de implementar isso é utilizando um buffer circular
(quando chegar no fim do buffer ele volta ao começo) compartilhado em que os produtores
precisam inserir os dados nesse buffer e os consumidores precisam consumir os dados do
buffer. Para que a solução funcione corretamente é necessário garantir que ao inserir os dados
no buffer os produtores não possam inserir os dados na mesma posição e eles também precisam
produzir apenas em posições vazias, caso o buffer volte ao início e acesse uma posição que
ainda não foi consumida, ele precisa esperar alguém consumir o dado antes de produzir nessa
posição novamente. Já os consumidores só podem consumir se a posição do buffer não estiver
vazia, ao consumir essa posição se torna vazia. Do mesmo modo, se o consumidor voltar ao
começo do buffer, ele precisa aguardar que alguém produza.

## Para começar   

É necessario clonar o repositorio e fazer a abertura do local dos arquivos com:   

```bash
$ git clone https://github.com/joaoluis87/Atv6-infra-SW.git
$ cd Atv6InfraSW
```

## Compilar o programa   

Com o repositorio aberto, é compilado o programa com o comando "make bin", onde o Makefile realizará o compilamento com "gcc main.c -o main".   

```bash
$ make bin
```

## Rodar o programa   

Já  com o programa compilado, para rodar é necessário o comando "make run", onde o Makefile utilizará do "./main".  

```bash
$ make run
```
Semaforos foram usados para controlar o acesso das threads.
Foram usadas as funções "pthread_mutex_lock(&mutex);" e "pthread_mutex_unlock(&mutex);" para garantir o acesso aos dados e fazer alterações apenas uma thread por vez.

## Finalização   

Com a conclusão do programa, o Makefile se propõe apagar o programa compilado com "rm main", para isso é preciso utilizar o comando "make clean".  

```bash
$ make clean
```