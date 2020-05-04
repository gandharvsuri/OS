#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct ticketinfo {
    char* train_name;
    int ticket_num;
} ticket;

int main() {
    
    int fd = open("ticket_record.txt", O_WRONLY);
    ticket* ticket1 = (ticket *)malloc(sizeof(ticket));
    
    ticket1->train_name = "Shtabdi";
    ticket1->ticket_num = 54;
    write(fd, ticket1, sizeof(ticket));
    
    printf("Train name: %s\n", ticket1->train_name);
    printf("Ticket number: %d\n", ticket1->ticket_num);
    
    return 0;
}