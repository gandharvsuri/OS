/*System call: ln -s <source> <link>*/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int ret;
    ret = symlink("/home/gandharv/OS/Lab/1a", "/home/gandharv/OS/Lab/lab2/link1a_cprog");
    printf("symlink returns %d\n",ret);
}