#include <stdio.h>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

using namespace std;

int main()
{
    struct stat st;
    int ret = lstat("m.s",&st);
    if(ret == -1)
    {
        perror("stat");
        exit(0);
    }
    cout << "file size=" << st.st_size << endl;
    //S_ISREG(st.st_mode);
    mode_t mode = st.st_mode & S_IFMT;
    switch(st.st_mode & S_IFMT)
    {
        case S_IFREG:
            cout << "regular file" << endl;
            break;
        case S_IFDIR:
            cout << "directory" << endl;
            break;
        case S_IFCHR:
            cout << "character file" << endl;
            break;
        case S_IFBLK:
            cout << "block file" << endl;
            break;
        case S_IFIFO:
            cout << "pipe or FIFO" << endl;
            break;
        case S_IFSOCK:
            cout << "socket" << endl;
            break;
        case S_IFLNK:
            cout << "symbol link" << endl;
            break;
    }
    return 0;
}
