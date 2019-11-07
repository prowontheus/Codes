#include <iostream>

int foo(int a,int b,int c)
{
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	return a+b+c;
}

int main()
{
	auto bindfoo = std::bind(foo,1,std::placeholders::_1,std::placeholders::_2);
	int num = bindfoo(3,5);
	std::cout << num << std::endl;
}
