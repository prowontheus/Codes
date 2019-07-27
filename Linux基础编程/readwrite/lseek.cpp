#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <cstring>

using namespace std;

int main()
{
    int fd  = open("/home/narada/Desktop/2.txt",O_RDWR);
    if(fd == -1)
    {
        perror("open");
        exit(0);
    }
    int len = lseek(fd,0,SEEK_END);
    cout << "the length of 2.txt is " << len << endl;
    len = lseek(fd,1000,SEEK_END);
    cout << "the length of 2.txt is " << len << endl;
    len  = lseek(fd,-1,SEEK_END);
    write(fd,"a",1);
    close(fd);
    return 0;
}
