#include <iostream>

class Base {
public:
    int value1;
    int value2;
    Base() {
        value1 = 1;
    }
    Base(int value) : Base() {                          // 委托 Base() 构造函数
        value2 = value;
    }
};
class Subclass : public Base {
public:
    using Base::Base;  // 继承构造
};
class Base1
{
public:
	Base1(int va) :m_value(va), m_c('0'){}
	Base1(char c) :m_c(c) , m_value(0){}
private:
	int m_value;
	char m_c;
};

class Derived :public Base1
{
public:
	//初始化基类需要透传基类的各个构造函数，那么这是很麻烦的
	Derived(int va) :Base1(va) {}
	Derived(char c) :Base1(c) {}

	//假设派生类只是添加了一个普通的函数
	void display()
	{
//dosomething		
	}
};

int main() {
    Subclass s(3);
    std::cout << s.value1 << std::endl;
    std::cout << s.value2 << std::endl;
}
