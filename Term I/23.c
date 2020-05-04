#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
    int pid = fork(); 
  
    if (pid > 0) 
        sleep(5); 
  
    else        
        exit(0); 
  
    return 0; 
} 

// Zombiw state when chil completes it's process but parent is still active.
