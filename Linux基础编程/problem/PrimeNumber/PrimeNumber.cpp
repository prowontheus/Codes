#include <iostream>

bool IsNumPrime(int num)
{
    if(num == 2)
        return true;
    if(num % 2 == 0)
        return false;
    for(int i = 3;i <= num /2;i++)
    {
        if(num%i==0)
            return false;
    }
    return true;
}



int main()
{
    int n = 0;
    while(std::cin >> n && n > 0)
    {
   	  int i = 0;
  	  int prime_num = 0;
  	  for(i = 2;i <= n;++i)
  	  {
  	      if(IsNumPrime(i))
  	          ++prime_num;
  	  }
  	  std::cout << prime_num << std::endl;
    }
    return 0;
}
