#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    char buf[10];
    int fd,n;
    fd = open("/dev/tty",O_RDONLY | O_NONBLOCK);
    if(fd < 0)
    {
        perror("open /dev/tty");
        exit(1);
    }

tryagain:
    n = read(fd,buf,10);
    if(n < 0)
    {
        if(errno == EAGAIN)
        {
            sleep(3);
            write(STDOUT_FILENO,"tryagain\n",9);
            goto tryagain;
        }
        perror("read /dev/tty");
        exit(0);
    }
    write(STDOUT_FILENO,buf,n);
    close(fd);
    return 0;
}
