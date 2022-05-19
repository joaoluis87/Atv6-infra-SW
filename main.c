#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <stdlib.h>



sem_t sem_prod;
sem_t sem_cons;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int tamanho , limite, x = 0;
int *buffer;


void *produtor(void *args);
void *consumidor(void *args);
void saveLocal (int n, int i);

int main (void) {

    sem_init (&sem_prod, 0, 1);//iniciando em verde
    sem_init (&sem_cons, 0, 1);//iniciando em verde

    int n_prod, n_cons;

    
    scanf("%d", &n_prod);
    
    scanf("%d", &n_cons);
    
    scanf("%d", &limite);
    
    scanf("%d", &tamanho);
    

    buffer = malloc(sizeof(int) * tamanho);

    int i_prod[5];
    

    pthread_t threads_prod[n_prod];
    //criando os produtores
    for (int i = 0; i < n_prod; i++) {
        i_prod[i] = i;
        pthread_create(&threads_prod[i], NULL, produtor, &i_prod[i]);
    }    

    int i_cons[n_cons];
    pthread_t threads_cons[n_cons];
    //criando os consumidores
    for (int i = 0; i < n_cons; i++) {
        i_cons[i] = i;
        pthread_create(&threads_cons[i], NULL, consumidor, &i_cons[i]);
    }


    for (int i = 0; i < n_prod; i++){
	    pthread_join(threads_prod[i], NULL);
    }

    for (int i = 0; i < n_cons; i++)
	    pthread_join(threads_cons[i], NULL);

    sem_destroy(&sem_prod);

    return 0;
}

void *produtor (void *args) {

    
    while (1) {

        int id = *(int*)args;
        sem_wait(&sem_prod);
        
        int i = 0;
        int produto;
        pthread_mutex_lock(&mutex);
        for (i = 0; i < tamanho; i++){
            if (buffer[i] == 0){
                
                produto = (x * 2) + 1;
                printf("\nprodutor %d produzindo %d na posição %d", id, produto, i);
                saveLocal(produto, i);
                break;
            }
        }

        x += 1;
        if (x > limite) {
            x = 0;
        }
        pthread_mutex_unlock(&mutex);

       
        if (i != tamanho)
            sem_post(&sem_prod);

        
        sem_post(&sem_cons);
        
    }
}

void *consumidor (void *args) {
    int *i = (int*)args;
    
    while (1) {

        int id = *(int*)args;
        
        sem_wait(&sem_cons);
        
        
        
        pthread_mutex_lock(&mutex);
        for (int i = 0; i < tamanho; i++){
            if (buffer[i] != 0){
                printf("\nconsumidor %d consumindo %d na posição %d", id, buffer[i], i);
                saveLocal(0, i);
                
                break;
            }
        }
        pthread_mutex_unlock(&mutex);
       

        sem_post(&sem_cons);
        sem_post(&sem_prod);
                
        
        
    }
}

void saveLocal (int n, int i) {
    
    buffer[i] = n;
   
}
