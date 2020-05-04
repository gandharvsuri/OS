#include <stdio.h>
#include <stdlib.h>


extern char **environ;
int main(){


    int i = 0 ;
    while(environ[i]){

        printf("%s\n",environ[i]);
        i++;
    }
}


/*  user
    loguser
    home: user's login directory
    lang
    path
    pwd
    shell : pathname to user's login shell
    term : terminal type.
    pager
    editor
*/