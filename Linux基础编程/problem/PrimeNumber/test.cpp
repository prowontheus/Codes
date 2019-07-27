//#include<string.h>
#include<iostream>
#include<algorithm>
 
using namespace std;

int main()
{
    bool check[1000000] = {false};
    int prim[1000000] = {0};
;    int tot = 0;
    for(int i = 2;i <= 1000000;i ++)
    {
        if(!check[i]) prim[tot ++] = i;
        for(int j = 0;j < tot;j ++)
        {
            if(i * prim[j] > 1000000) break;
            check[i * prim[j]] = true;
            if(i % prim[j] == 0) break;   
        }
    }
     
    int n;
    while(cin >> n && n > 0)
    {
	int *a = find(prim,prim+1000000,n);
	cout << a-prim << endl;
    }
     
    return 0;
}
