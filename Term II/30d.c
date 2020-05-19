#include <sys/ipc.h> 
#include <sys/shm.h> 
#include <stdio.h> 

int main() 
{ 
	key_t key = ftok(".",'c'); 
	int shmid = shmget(key,1024,0); 
	char *str = (char*) shmat(shmid,(void*)0,0); 
	printf("Data read from memory: %s\n",str); 
	shmdt(str); 
	shmctl(shmid,IPC_RMID,NULL); 
    printf("Destroyed shared memory\n");
	
	return 0; 
} 
