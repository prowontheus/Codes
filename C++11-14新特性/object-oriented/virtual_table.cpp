#include<iostream>
//将上面“虚函数示例代码”添加在这里
class A{//虚函数示例代码
    public:
        virtual void fun(){std::cout<<1<<std::endl;}
        virtual void fun2(){std::cout<<2<<std::endl;}
};
class B : public A{
    public:
        void fun(){std::cout<<3<<std::endl;}
        void fun2(){std::cout<<4<<std::endl;}
};
int main()
{
    void(*fun)(A*);
    A *p=new B;
    long lVptrAddr;
    memcpy(&lVptrAddr,p,4);
    memcpy(&fun,reinterpret_cast<long*>(lVptrAddr),4);
    fun(p);
    delete p;
    system("pause");
    return 0;
}
