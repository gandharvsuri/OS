#include<stdio.h>
#include<pthread.h>

int g = 0;

void *thread_func(void *vargp)
{
    int id = (int*) vargp;
    printf("Thread id %d g = %d\n",id,g++);

    for(int i = 0; i < 10; i++){
        continue;
    }

    printf("Thread 1 after looping  ");
    printf("Thread id %d g = %d\n",id,g++);


}

void* thread_func2(void* vargp){
    int id = (int*) vargp;
    printf("Thread id %d g = %d\n",id,g++);
}


int main(){
    
    pthread_t tid,tid2;

    pthread_create(&tid, NULL,thread_func,(void*)&tid);
    pthread_create(&tid2,NULL,thread_func2,&tid2);


    printf("%d\n",g);
    pthread_join(tid,NULL);
    pthread_create(&tid2,NULL,thread_func2,&tid2);

    pthread_exit(NULL);
}