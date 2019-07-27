#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>

using namespace std;;

int main()
{
    int fd = open("/home/narada/Desktop/1",O_RDWR);
    cout << "fd=" << fd << endl;
    if(fd = -1)
    {
        perror("open");
        return 0;
    }
    int fd1 = open("/home/narada/Desktop/2.txt",O_RDWR | O_CREAT,0664);
    cout << "fd1="<< fd1 << endl;

    char buf[4096];
    int len = read(fd,buf,sizeof(buf));
    while(len > 0)
    {
        int ret = write(fd1,buf,len);
        len = read(fd,buf,sizeof(buf));
        cout << "len=" << len << endl;
    }
    close(fd);
    close(fd1);
    return 0;
}
