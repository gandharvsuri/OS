/*System call: ln <source> <link>*/

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int ret;
    ret = link("/home/gandharv/OS/Lab/1a", "/home/gandharv/OS/Lab/lab2/link2a_cprog");
    printf("link returns %d\n",ret);
}