//
// Created by 丁月星 on 2020/7/19.
//
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <string>
#include <math.h>

template<typename T>
int lenoflist(std::list<T> l)
{
    if(l.empty())
    {
        return 0;
    }
    else
    {
        l.pop_back();
        return 1 + lenoflist<T>(l);
    }
}

void reverse1()
{
    int ch;
    ch = std::cin.get();
    if(ch != '\n')
        reverse1();
    std::cout.put(ch);
}

void reverse2()
{
    static char ch;
    ch = std::cin.get();
    if(ch != '\n')
        reverse2();
    std::cout.put(ch);
}

void printodd1(int n)
{
    if(n <= 0)
        return;
    printodd1(n-1);
    if(n % 2 == 1)
        std::cout << n << " " ;
}

void printodd2(int n)
{
    if(n <= 0)
        return;
    if(n % 2 == 1)
    {
        std::cout << n << " ";
        n -= 2;
    }
    else
        n--;
    printodd2(n);
}

void putCommas(long n,char *tmp)
{
    long rem = n % 1000;
    n /= 1000;
    if(n == 0) {
        sprintf(tmp,"%03ld",rem);
        return;
    }
    char *tmp1;
    putCommas(n,tmp1);
    sprintf(tmp,"%s,%03ld",tmp1,rem);
    return;
}

void show(int n)
{
    if(n / 1000 == 0)
        std::cout<<n%1000;
    else
    {
        show(n/1000);
        std::cout << ',' << (n>0?n%1000:-n%1000);
    }
}

void Syracuse(int a0,int n)
{
    if(n <= 1)
    {
        if(n > 0)
            std::cout << 1 << std::endl;
        return;
    }
    std::cout << a0 << std::endl;
    a0 = a0%2==0?a0/2:3*a0+1;
    Syracuse(a0,n-1);
}

int Multi(int a,int b)
{
    if(a == 0 || b == 0)
        return 0;
    if(a > 0)
        return Multi(a-1,b) + b;
    else if(b > 0)
        return a + Multi(a,b-1);
    else
        return Multi(-a,-b);
}

int BinomialCoefficient(int n,int k)
{
    if(n < 0 || k < 0)
        return 0;
    if(n == 0 || k == n)
        return 1;
    else
    {
        return BinomialCoefficient(n-1,k-1) + BinomialCoefficient(n-1,k);
    }
}

float func10(int n)
{
    if(n <= 1)
        return 1;
    float tmp = n;
    return n%2==0?1/tmp+func10(n-1):-1/tmp+func10(n-1);
}

int main()
{
    //5-12-2
//    std::list<int> l = {2,4,5,6,7,8,9,1,23,453,3,5};
//    std::cout << "链表的长度是" << lenoflist(l) << std::endl;

    //5-12-3
//    reverse1();

    //5-12-4
//    reverse2();

    //5-12-5
//    printodd1(146);
//    std::cout << std::endl;
//    printodd2(146);

    //5-12-6
//    long n = -2146428947;
//    char tmp[10] = {0};
////    putCommas(n,tmp);
////    std::cout << tmp << std::endl;
//    show(n);
//    std::cout << std::endl;
//    n = 2344324;
//    show(n);

    //5-12-7
//    Syracuse(222,14);

    //5-12-8
//    int a = 34,b = -42;
//    std::cout << "a*b=" << Multi(a,b) << std::endl;

    //5-12-9
//    std::cout << BinomialCoefficient(7,8) << std::endl;

    //5-12-10
//    std::cout << func10(7) << std::endl;

    return 0;
}