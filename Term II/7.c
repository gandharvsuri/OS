#include<stdio.h>
#include<pthread.h>

void* thread_func(){
    printf("%lu\n",pthread_self());
}

int main(){
    pthread_t tid;

    for(int i = 0; i < 3; i++){
        pthread_create(&tid,NULL,thread_func,NULL);
    }

    pthread_exit(NULL);
}