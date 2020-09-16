//
// Created by 丁月星 on 2020/9/11.
//

#include "9-6.h"


std::ostream& operator<<(std::ostream& os,const group& gro)
{
    if(gro.exp == 1)
        os << gro.ch;
    else os << gro.ch << gro.exp;
    return os;
}

bool term::operator==(const term &term2)
{
    if(vec.size() != term2.vec.size())
        return false;
    for(int i = 0;i < vec.size();i++)
    {
        if(vec[i] != term2.vec[i])
            return false;
    }
    return true;
}

bool term::operator<(const term &term2)
{
    int size = min(vec.size(),term2.vec.size());
    for(int i = 0;i < size;i++)
    {
        if(vec[i] < term2.vec[i])
            return true;
    }
    return size < term2.vec.size();
}

std::ostream& operator<<(std::ostream& os,const term& term1)
{
    if(term1.coef == -1)
        os << "-";
    for(auto r:term1.vec)
        os << r;
    return os;
}

std::ostream& operator<<(std::ostream &os,const Polynomial& poly)
{
    priority_queue<term,vector<term>,std::less<term>> *pri1 = const_cast<priority_queue<term,vector<term>,std::less<term>> *>(&(poly.pri));
    while(pri1->empty())
    {
        term tmp =  pri1->top();
        os << tmp;
    }
    return os;
}

std::istream& operator>>(std::istream &is,Polynomial &poly)
{
    char ch;
    is >> ch;
    int sign = 1;
    if(ch == '-')
        sign = -1;
    else if(!isdigit(ch))
        return is;
    is >> ch;
    term term1;
    group group1;
    while(ch != ';')
    {
        if(isdigit(ch))
        {

        }
        else if(isalpha(ch))
        {

        }
        else if(ch == '+' || ch == '-' || isspace(ch))
        {

        }
        else exit(-1);
        is >> ch;
    }
    return is;
}

bool Polynomial::operator+(const Polynomial &poly)
{
    return true;
}

void funcexit()
{
    cout << "输入的多项式非法" << endl;
}

int main()
{
    atexit(funcexit);
    cout << "请输入一个多项式，以分号结束：" << endl;
    Polynomial poly;
    cin >> poly;
    cout << poly;
    return 0;
}