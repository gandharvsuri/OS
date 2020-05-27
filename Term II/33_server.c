#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(){

    struct timeval tmo;
    fd_set readfds;

    struct sockaddr_in server, client;
    unsigned int sd,sz,nsd; //server file descriptor, size, nsd
    int opt = 1;
    char buf[80]; //buffer 

    sd = socket(AF_UNIX,SOCK_STREAM,0);  //  or AF_INET for internet, TCP 
    if(sd == 0){
        perror("Socket Failed");
        exit(EXIT_FAILURE);
    }

    if(setsockopt(sd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))){
        perror("setsocketopt");
        exit(EXIT_FAILURE);
    }

    server.sin_family = AF_UNIX;
    server.sin_addr.s_addr = INADDR_ANY; 
    server.sin_port = htonl(5555); //big endian (host to socket)
    if(bind(sd,(struct sockaddr *)&server,sizeof(server)) <0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    //number of clients at a time;
    if(listen(sd,5) < 0){
        perror("listen");
        exit(EXIT_FAILURE);
    }   
    
    sz = sizeof(client);
    if((nsd = accept(sd,(struct sockaddr *)(&client),&sz)) <0){
        perror("accept");
        exit(EXIT_FAILURE);
    }

    FD_ZERO(&readfds);
    FD_SET(nsd, &readfds);
    tmo.tv_sec = 3;
    tmo.tv_usec = 0;
    if(!select(nsd+1, &readfds, NULL, NULL, &tmo)){
        printf("No Response from Client\n");
        exit(0);
    }
    read(nsd,buf,sizeof(buf));
    printf("MESSAGE FROM CLIENT : %s\n",buf);

    write(nsd,"ACK FROM SERVER\n",sizeof("ACK FROM SERVER\n"));

    close(sd);
}