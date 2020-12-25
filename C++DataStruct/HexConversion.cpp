#include <iostream>
#include <stack>

class HexConversion
{
public:
    HexConversion(int s = 0);
    void Init();
    void conversion(int Hex);
    void print();
private:
    int m_Idigital;
    std::stack<int> m_Listdigital;
};

HexConversion::HexConversion(int s):m_Idigital(s)
{
    // Init();
}

void HexConversion::Init()
{
    int tmp = m_Idigital;
    if(!isdigit(tmp))
    {
        std::cout << "该字符串不是十进制数" << std::endl;
    }
    int a = 0;
    while(tmp != 0)
    {
        a = tmp % 10;
        m_Listdigital.push(a);
        tmp /= tmp;
    }
}

void HexConversion::conversion(int Hex)
{
    int tmp = m_Idigital;
    int a = 0;
    while(tmp != 0)
    {
        a = tmp % Hex;
        m_Listdigital.push(a);
        tmp /= Hex;
    }
}

void HexConversion::print()
{
    while(!m_Listdigital.empty())
    {
        std::cout << m_Listdigital.top();
        m_Listdigital.pop();
    }
    std::cout << std::endl;
}

int main()
{
    int number = 0;
    int hex = 0;
    std::cout << "请输入一个十进制数" << std::endl;
    std::cin >> number;
    std::cout << "请输入你想转化的进制数" << std::endl;
    std::cin >> hex;
    if(hex >= 2 && hex <= 9)
    {
        HexConversion digital(number);
        digital.conversion(hex);
        digital.print();
    }
    return 0;
}