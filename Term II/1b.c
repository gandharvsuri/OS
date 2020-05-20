#include <stdio.h>
#include <sys/time.h>


int main(){
    
    struct itimerval value;
    int which = ITIMER_VIRTUAL;

    getitimer( which, &value );

    // Time until next expiration
    value.it_value.tv_sec = 1;
    value.it_value.tv_usec = 0;

    // Interval for periodic timer
    value.it_interval.tv_sec = 1;
    value.it_interval.tv_usec = 0;

    setitimer(which,&value,NULL);

    while(1);

}