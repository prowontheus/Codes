#include <iostream>
#include <string>
using namespace std;

bool func(const string &str,char *a)
{
	return false;
}

int main()
{
	bool (*pf)(const string &str,char *a);
	pf = func;
	int i = 42,*p = &i,&r = i;
	decltype(r+1.2) b;
	decltype(*p) c = r;
	std::cout << typeid(i).name() << std::endl;
	std::cout << typeid(p).name() << std::endl;
	std::cout << typeid(r).name() << std::endl;
	std::cout << typeid(b).name() << std::endl;
	std::cout << typeid(c).name() << std::endl;
	std::cout << typeid(func).name() << std::endl;
	std::cout << typeid(decltype(pf)).name() << std::endl;
	std::cout << pf << std::endl;
	pf = &func;
	std::cout << pf << std::endl;
	std::cout << func << &func << std::endl;
	return 0;
}
