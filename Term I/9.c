

// stat filename *** gives almost all info


#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<time.h>

int main(int argc,char * argv[]){

struct stat buff;
int fd;
fd = open(argv[1],O_RDONLY);
stat(argv[1],&buff);


printf("Inode = %ld \n",buff.st_ino);
printf("no of hard links = %ld\n",buff.st_nlink);
printf("User id = %d\n",buff.st_uid);
printf("Group id = %d\n",buff.st_gid);
printf("Size = %ld\n",buff.st_size);
printf("Block Size = %ld\n",buff.st_blksize);
printf("Number of blocks = %ld\n",buff.st_blocks);
printf("LastTime of acces = %s\n",ctime(&(buff.st_atime)));
printf("Last Modfn time = %s\n",ctime(&(buff.st_mtime)));
printf("Last change time= %s\n",ctime(&(buff.st_ctime)));


}
