#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>


int main(){
    struct sockaddr_in server;
    int sd;
    char buf[80];
    
    sd = socket(AF_UNIX,SOCK_STREAM,0);
    if(sd == 0){
        perror("Socket Failed");
        exit(EXIT_FAILURE);
    }


    server.sin_family = AF_UNIX;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htonl(5555);

    
    if(connect(sd,(struct sockaddr *)(&server),sizeof(server)) == -1){
        perror("connection failed");
        exit(EXIT_FAILURE);
    }
    getchar();
    write(sd,"HI SERVER\n",sizeof("HE SERVER\n"));
    read(sd,buf,sizeof(buf));
    printf("MESSAGE FROM SERVER : %s\n",buf);

    printf("Press [Enter] to exit.....\n");
    getchar();

    close(sd);
}