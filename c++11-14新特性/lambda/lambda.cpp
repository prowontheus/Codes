#include <iostream>

int main()
{
	auto lam = [](auto x,auto y)
	{
		return x+y;
	};
	auto a = lam(3,4);
	auto b = lam(3.3,4.4);
	auto c = lam(3,4.4);
	return 0;
}
