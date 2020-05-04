#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct ticketinfo {
    char* train_name;
    int ticket_num;
} ticket;

int main() {

  int fd = open("ticket_record.txt", O_RDWR);

  if(fd == -1) {
    printf("Unable to open the file\n");
    exit(1);
  }
  static struct flock lock;
  ticket* ticket1 = (ticket *)malloc(sizeof(ticket));
  read(fd, ticket1, sizeof(ticket));

    lock.l_type = F_WRLCK;
    lock.l_start = 0;
    lock.l_whence = SEEK_SET;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf ("Current ticket number: %d\n", ticket1->ticket_num);
    int ret = fcntl(fd, F_SETLKW, &lock);
    if (ret == -1) {
      printf("Attempt to set write lock failed\n");
    }
    else {
      lock.l_type = F_UNLCK;
      fcntl(fd, F_SETLKW, &lock);
      ticket1->ticket_num += 1;
      lseek(fd,0,SEEK_SET);
      write(fd, ticket1, sizeof(ticket));
      printf ("Incremented ticket number: %d\n", ticket1->ticket_num);
    }
    close(fd);
  
}