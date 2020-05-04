#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct record {
    char* name;
    int num;
} rec;


int main() {

    int fd = open("record.txt", O_RDWR);
    if(fd == -1) {
      printf("Unable to open the file\n");
      exit(1);
    }

    printf("Enter the record you wish to lock: ");
    int rec_no;
    scanf("%d", &rec_no);
    getchar();

    static struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_start = sizeof(rec)*(rec_no-1);
    lock.l_whence = SEEK_SET;
    lock.l_len = sizeof(rec);
    lock.l_pid = getpid();

    printf ("Before critical section\n");
    int ret = fcntl(fd, F_SETLK, &lock);
    if (ret == -1) {
      printf("Attempt to set read lock failed\n");
    }
    else {
      printf("Attempt to set read lock successful\n");
      printf ("After critical section. Enter to unlock\n");
      getchar();
      lock.l_type = F_UNLCK;
      fcntl(fd, F_SETLK, &lock);
    }
    printf("Return value of fcntl:%d\n",ret);

  
}