#include <iostream>
#include <stdio.h>
#include <unistd.h>

int main()
{
    char buf[10];
    int len = read(STDIN_FILENO,buf,sizeof(buf));
    write(STDOUT_FILENO,buf,len);
    return 0;
}
