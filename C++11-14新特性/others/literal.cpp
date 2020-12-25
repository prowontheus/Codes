#include <iostream>
#include <string>

int main() {
    std::string str1 = R"(C:\\What\\The\\Fxxk)";
	std::string str2 = "(C:\\What\\The\\Fxxk)";
	std::string str3 = "C:\\What\\The\\Fxxk";
    std::cout << "str1=" << str1 << std::endl;
    std::cout << "str2=" << str2 << std::endl;
    std::cout << "str3=" << str3 << std::endl;
    return 0;
}
