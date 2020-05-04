/*System call: mknod *filename* 
               mkfifo a=rw *filename* */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int ret;
    ret = mkfifo("fifofile",0777);
    printf("mkfifo returns %d\n",ret); 

    ret = mknod("fifomknod",S_IFIFO,0);
    printf("mknod returns %d\n",ret);
}
