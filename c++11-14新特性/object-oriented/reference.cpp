#include <iostream>

void process_value(int i) 
{ 
  std::cout << "nomal Value processed: " << i << std::endl; 
} 

void process_value1(int& i) 
{ 
  std::cout << "LValue processed: " << i << std::endl; 
} 

void process_value2(int&& i) 
{ 
  std::cout << "RValue processed: " << i << std::endl; 
} 
template <class _Tp> void f(_Tp &&amp) { /* do something */ }
template <class _Tp> void g(const _Tp &&amp) { /* do something */ }

int fun()
{
	int a = 10;
	int b = 20;
	return a+b;
}

int const func()
{
	return 5;
}

const int funb()
{
	return 6;
}
int main() 
{ 
  int a = 28; 
  process_value(14);
  process_value(a);
  process_value1(a);
  process_value2(35);
  int&& y = 3;
  process_value1(y);
  const int b = 5;

  int&& v1 = 5;
  //int&& v2 = a;   //compile error
  //int&& v3 = b;   //compile error
  int&& v4 = a + b;
  const int &v5 = fun();
  int &&v6 = func();
  const int &&v7 = fun();
  int x = 123;
  f(x);//ok，f()模板函数形参为非const非volatile右值引用类型，实参x为int类型左值，使用int&来做参数推导，因此调用f<int &>(int &amp ;)
  f(456); // ok，实参为右值，调用f<int>(int &&amp ;)
//g(x);
}
