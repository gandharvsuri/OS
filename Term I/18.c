#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct record {
    char* name;
    int num;
} rec;

int main() {
    
    int fd = open("record.txt", O_WRONLY);
    rec* rec1 = (rec *)malloc(sizeof(rec));
    
    rec1->name = "ABC";
    rec1->num = 54;
    lseek(fd,0,SEEK_END);
    write(fd, rec1, sizeof(rec));
    
    printf("Train name: %s\n", rec1->name);
    printf("Ticket number: %d\n", rec1->num);


    rec* rec2 = (rec *)malloc(sizeof(rec));
    
    rec2->name = "PQR";
    rec2->num = 33;
    lseek(fd,0,SEEK_END);
    write(fd, rec2, sizeof(rec));
    
    printf("Train name: %s\n", rec2->name);
    printf("Ticket number: %d\n", rec2->num);

    rec* rec3 = (rec *)malloc(sizeof(rec));
    
    rec3->name = "XYZ";
    rec3->num = 20;
    lseek(fd,0,SEEK_END);
    write(fd, rec3, sizeof(rec));
    
    printf("Train name: %s\n", rec3->name);
    printf("Ticket number: %d\n", rec3->num);

    return 0;
}