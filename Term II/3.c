#include<stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

void printer(struct rlimit* r){

    printf("Soft Limit : %lu \nHard Limit : %lu\n\n",r->rlim_cur,r->rlim_max);
}

int main(){

    struct rlimit r;

    getrlimit(RLIMIT_FSIZE , &r);
    printer(&r);

    r.rlim_cur = 1;
    r.rlim_max = 3;

    setrlimit(RLIMIT_FSIZE, &r);
    
    getrlimit(RLIMIT_FSIZE , &r);
    printer(&r);
}
