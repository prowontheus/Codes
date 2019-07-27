#nclude <stdio.h> 
#include <string.h> 
#include <malloc.h> 
#include <iostream>
using namespace std;
 
int main(void) 
{ 
	char *p = (char *) malloc(100); 
	strcpy(p, "hello");
 
	delete p;	// p 所指的内存被释放，但是p所指的地址仍然不变，原来的内存变为“垃圾”内存（不可用内存 
 
	if ( p != NULL )	// 没有起到防错作用 
	{
		strcpy(p, "world");
	}
	for(int i = 0; i < 5; i++) //i=5后为乱码 
		cout<<*(p+i)<<" ";
 
	cout<<endl;
}
