#include<iostream>
enum class Side{ Right, Left };
enum class Thing{ Wrong, Right };  //不冲突
int main()
{
	Side s = Side::Right;//必须使用Side进行作用域的限制
	Thing w = Thing::Wrong;
	std::cout << (s == w) << std::endl;
	//编译错误，无法直接比较不同枚举类
	return 0;
}
