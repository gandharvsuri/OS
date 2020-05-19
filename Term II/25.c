
#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 

int main() 
{ 
	key_t key; 
	int msqid; 
	key = ftok(".", 'a'); 

	msqid = msgget(key, 0666 | IPC_CREAT); 
    struct msqid_ds ms_info;
	msgctl(msqid,IPC_STAT,&ms_info);
    struct ipc_perm permissions = ms_info.msg_perm;
    printf("access permissions = %d\n",permissions.mode);
    printf("uid = %d ",permissions.uid);
    printf("gid = %d\n",permissions.gid);
    printf("time of last msg sent = %ld\n",ms_info.msg_stime);
    printf("time of last msg received = %ld\n",ms_info.msg_rtime);
    printf("time of last change = %ld\n",ms_info.msg_ctime);
    printf("size of msg queue = %ld\n",ms_info.__msg_cbytes);
    printf("number of messages = %ld\n",ms_info.msg_qnum);
    printf("max num of bytes = %ld\n",ms_info.msg_qbytes);
    printf("pid of last msg sent = %d\n",ms_info.msg_lspid);
    printf("pid of last msg received = %d\n",ms_info.msg_lrpid);
	return 0; 
} 
