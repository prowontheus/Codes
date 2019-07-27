#include <iostream>
#include "FuncPoi.h"

using namespace std;

int (*pFun)(int,int);
typedef char (*pFun1)(char a,char b);

int Fun(int a,int b)
{
    return a>b?a:b;
}

char Fun1(char a,char b)
{
    return a>b?a:b;
}

int main()
{
    int a = 10,b = 19;
    char c = 'j',d = 'i';
    pFun = Fun;
    cout << (*pFun)(a,b)<< endl;
    pFun1 p1 = Fun1;
    cout << (*p1)(c,d) << endl;
    return 0;
}
