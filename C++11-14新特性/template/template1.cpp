#include <iostream>

template<typename... args>
void magic(args... arg)
{
	std::cout << sizeof...(arg) << std::endl;
}

int main()
{
	int i = 10;
	int *p = &i;
	int &r = i;
	int arr[] = {1,2,3,4,5};
	magic();
	magic(1);
	magic(1,"");
	magic(1,2,3,'a',"hello",5.6,p,r,arr);
	return 0;
}
