#include <stdio.h>
#include <sys/time.h>


int main(){
    
    struct itimerval value;
    int which = ITIMER_REAL;

    getitimer( which, &value );

    value.it_value.tv_sec = 10;
    value.it_value.tv_usec = 10;

    setitimer(which,&value,NULL);

    printf("Finished \n");

}