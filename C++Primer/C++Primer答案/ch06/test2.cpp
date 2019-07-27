#include <iostream>
#include <vector>
using namespace std;

int add(int a,int b)
{
	return a+b;
}
int sub(int a,int b)
{
	return a-b;
}
int mul(int a,int b)
{
	return a*b;
}
int divd(int a,int b)
{
	return a%b;
}
int Bigger(int,int)
{return 1;}
typedef int (*pFunc)(int,int);
typedef bool Func(string &,string &);
typedef decltype(Func) Func2;
int main()
{
	pFunc p1 = Bigger;
	cout << p1(1,1) << endl;
	cout << typeid(pFunc).name() << endl;
	vector<pFunc> vec;
	pFunc p2 = add;
	pFunc p3 = sub;
	pFunc p4 = mul;
	pFunc p5 = divd;
	vec.push_back(p2);
	vec.push_back(p3);
	vec.push_back(p4);
	vec.push_back(p5);
	cout << vec.at(2)(8,3) << endl;
	return 0;
}
