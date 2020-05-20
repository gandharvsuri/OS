#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<pthread.h>


void* socket_connection(void* vargp){
    char buf[80];
    int nsd = *(int*)vargp;
    read(nsd,buf,sizeof(buf));
    printf("MESSAGE FROM CLIENT : %s\n",buf);
    write(nsd,"ACK FROM SERVER\n",sizeof("ACK FROM SERVER\n"));
    return 0;

}

int main(){

    struct sockaddr_in server, client;
    unsigned int sd,sz,nsd; //server file descriptor, size, nsd
    char buf[80]; //buffer 

    sd = socket(AF_UNIX,SOCK_STREAM,0);  //  or AF_INET for internet, TCP 

    server.sin_family = AF_UNIX;
    server.sin_addr.s_addr = INADDR_ANY; 
    server.sin_port = htonl(5555); //big endian (host to socket)
    bind(sd,(struct sockaddr *)&server,sizeof(server));

    listen(sd,2); //number of clients at a time;
    
    while(1){
        sz = sizeof(client);
        if((nsd = accept(sd,(struct sockaddr *)(&client),&sz)) <0){
        perror("accept");
        exit(EXIT_FAILURE);
        }
        pthread_t tid;
        if(pthread_create(&tid,NULL,socket_connection,(void*)&nsd) < 0){
            perror("Thread Failed");
            exit(EXIT_FAILURE);
        } 
    }

    return 0;
}