// enumType.cpp: 定义控制台应用程序的入口点。
#include <iostream>
 
//定义一个枚举类型，可以通过这个定义相应的枚举成员的标识符
//并用其中的一个为他们赋值
//定义在main函数体外属于全局变量
enum GameResult { WIN, LOSE, TIE, CANCEL };
 
int main() {
 
	//enum GameResult { WIN, LOSE, TIE, CANCEL };
	//int WIN;
	//若将enum定义在主函数内，然后再定义WIN则会出现重定义错误
	//主要是因为两者在同一命名空间中
 
	GameResult result;
	enum GameResult omit = CANCEL;
 
	for (int count = WIN; count <= CANCEL; count++) {
		result = GameResult(count);
		if (result == omit)
			std::cout << "The game was cancelled" << std::endl;
		else {
			std::cout << "The game was played ";
			if (result == WIN)     
				std::cout << "and we won!";
			if (result == LOSE)       
				std::cout << "and we lost.";
			std::cout << std::endl;
		}
	}
	//std::cout << &WIN << std::endl;
	//编译错误，因为WIN是常量，不能对其取地址
	std::cout << &omit << std::endl;
	std::cout << &result << std::endl;
	return 0;
}
 
 
