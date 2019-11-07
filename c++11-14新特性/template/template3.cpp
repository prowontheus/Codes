#include <iostream>
template<typename T, typename... Args>
auto print(T value, Args... args) {
    std::cout << value << std::endl;
    return std::initializer_list<T>{([&]{std::cout << args << std::endl;}(), value)...};
}
int main() {
	int i = 10;
	int *p = &i;
	int &r = i;
	r++;
    print(1, 2.1,'a',"123",r,p,i);
    return 0;
}
