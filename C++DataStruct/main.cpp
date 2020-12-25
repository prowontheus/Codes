#include "intSLList.h"

int main()
{
	IntSLList a;
	a.addToTail(2);
	a.addToTail(3);
	a.addToTail(4);
	a.printAll();
	a.addToHead(5);
	a.addToHead(6);
	a.addToHead(7);
	a.printAll();
	return 0;
}