//
// Created by 丁月星 on 2020/9/11.
//

#ifndef A_OUT_9_6_H
#define A_OUT_9_6_H

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <map>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::priority_queue;
using std::tuple;
using std::map;

std::tuple<char,char> tup;
class group{
public:
    group():ch(' '),exp(0){}
    group(char c,int e):ch(c),exp(e){}
    bool operator==(const group& gro)const{
        return ch == gro.ch && exp == gro.exp;
    }
    bool operator!=(const group& gro)const{
        return !(*this == gro);
    }
    bool operator<(const group& gro)const{
        return ch < gro.ch || (ch == gro.ch && exp < gro.exp);
    }
    bool operator>(const group& gro)const{
        return ch > gro.ch || (ch == gro.ch && exp > gro.exp);
    }
    friend std::ostream& operator<<(std::ostream& os,const group& gro);
    char ch;
    int exp;
};

class term{
public:
    term(){
        coef = 0;
        vec.resize(0);
    }
    term(int c,vector<group> v):coef(c),vec(v){}
    term(const term &term1){
            this->coef = term1.coef;
            this->vec = term1.vec;
    }
    void clear(){coef = 1;vec.resize(0);}
    bool operator==(const term &term2)const;
    bool operator!=(const term &term2)const
    {
        return !operator==(term2);
    }
    bool operator<(const term &term2)const;
    bool operator>(const term &term2)const
    {
        return !(*this == term2) && !(*this < term2);
    }
    term operator+(const term &term);
    friend term operator*(const term &term1,const term &term2);
    term operator=(const term &term2)
    {
        if(this != &term2)
        {
            this->coef = term2.coef;
            this->vec = term2.vec;
        }
        return *this;
    }
    term& differential(char c);
    friend std::ostream& operator<<(std::ostream& os,const term& term1);
    int coef;
    vector<group> vec;
};

template<typename T>
struct cmp{
    bool operator()(const T *tmp1,const T *tmp2)
    {
        return *tmp1 < *tmp2;
    }
};

class Polynomial{
public:
    Polynomial(){}
    ~Polynomial(){
        while(!pri.empty())
        {
            term *tmp = pri.top();
            pri.pop();
            delete tmp;
            tmp = nullptr;
        }
    }
    friend std::ostream &operator<<(std::ostream &os,const Polynomial &poly);
    friend std::istream &operator>>(std::istream &is,Polynomial &poly);
    tuple<term*,char> ExtractTerm(std::istream &is,char ch);
    void MergeSimilarItems();
    friend Polynomial operator+(Polynomial &poly1,Polynomial &poly2);//多项式加法
    friend Polynomial operator*(Polynomial &poly1,Polynomial &poly2);//多项式乘法
    Polynomial& differential(char c);//多项式微分
private:
    priority_queue<term*,vector<term*>,cmp<term>> pri;
};

#endif //A_OUT_9_6_H
