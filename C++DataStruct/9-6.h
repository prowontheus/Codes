//
// Created by 丁月星 on 2020/9/11.
//

#ifndef A_OUT_9_6_H
#define A_OUT_9_6_H

#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::vector;
using std::priority_queue;


class group{
public:
    group():ch(' '),exp(0){}
    group(char c,int e):ch(c),exp(e){}
    bool operator==(const group& gro){
        return ch == gro.ch && exp == gro.exp;
    }
    bool operator!=(const group& gro){
        return !(*this == gro);
    }
    bool operator<(const group& gro){
        return ch < gro.ch || (ch == gro.ch && exp < gro.exp);
    }
    friend std::ostream& operator<<(std::ostream& os,const group& gro);
private:
    char ch;
    int exp;
};

class term{
public:
    term(){
        coef = 0;
        vec.resize(0);
    }
    int min(int a,int b){return a<b?a:b;}
    bool operator==(const term& term2);
    bool operator<(const term & term2);
    friend std::ostream& operator<<(std::ostream& os,const term& term1);
private:
    int coef;
    vector<group> vec;
};

class Polynomial{
public:
    Polynomial(){}
    friend std::ostream &operator<<(std::ostream &os,const Polynomial &poly);
    friend std::istream &operator>>(std::istream &is,Polynomial &poly);
    bool operator+(const Polynomial &poly);
private:
    priority_queue<term,vector<term>,std::less<term>> pri;
};

#endif //A_OUT_9_6_H
