#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main ()
{
    int fd;
    struct flock lock;
    
    fd = open ("file1.txt", O_WRONLY);
    printf ("locking\n");
    memset (&lock, 0, sizeof(lock));
    lock.l_type = F_WRLCK;
    fcntl (fd, F_SETLKW, &lock);
    
    write(fd,"LOCKED",20);
    
    printf ("unlocking\n");
    lock.l_type = F_UNLCK;
    fcntl (fd, F_SETLKW, &lock);
    
    close (fd);
    return 0;

}