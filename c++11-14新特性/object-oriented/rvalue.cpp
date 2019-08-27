#include <iostream>

bool is_r_value(int &&) 
{
	std::cout << "true" << std::endl; 
	return true;
}
bool is_r_value(const int &)
{
	std::cout << "false" << std::endl; 
	return false;
}

void test(int && i)
{
    bool isRValue = is_r_value(i); // i 為具名變數，即使被宣告成右值也不會被認定是右值。false
    isRValue = is_r_value(std::move<int&>(i)); // 使用 std::move<T>() 取得右值。 true
}

class Foo
{
public:
    std::string member;

    // Copy member.
    Foo(const std::string& m): member(m) {}

    // Move member.
    Foo(std::string&& m): member(std::move(m)) {}
};
int main()
{
	int a = 10;
	test(10);
	int &&rr1=42;
	//int &&rr2=rr1;//错误，表达式rr1是左值，不能绑定到右值引用上
	int rr3 = std::move(rr1);
	std::cout << "rr1=" << rr1 << ",rr3=" << rr3 << std::endl;
	return 0;
}
