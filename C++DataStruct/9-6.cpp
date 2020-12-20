//
// Created by 丁月星 on 2020/9/11.
//

//32x2y3+5x2w3-88x2w3z4+3;
//-2x2w3+9y-3xw-x2y3+8x2w3z4-4+8xw;
//
//5wx+3w3x2-80w3x2z4+31x2y3+9y-1

#include "9-6.h"

std::ostream& operator<<(std::ostream& os,const group& gro)
{
    if(gro.exp == 0)
        return os;
    if(gro.exp == 1)
        os << gro.ch;
    else os << gro.ch << gro.exp;
    return os;
}

bool term::operator==(const term &term2)const
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

bool term::operator<(const term &term2)const
{
    int size = vec.size()<term2.vec.size()?vec.size():term2.vec.size();
    for(int i = 0;i < size;i++)
    {
        if(vec[i] < term2.vec[i])
            return true;
        else if(vec[i] > term2.vec[i])
            return false;
    }
    return size < term2.vec.size();
}

term term::operator+(const term &term)
{
    if(*this == term)
        this->coef = this->coef + term.coef;
    return *this;
}

term operator*(const term &term1,const term &term2)
{
    term tmp;
    tmp.coef = term1.coef * term2.coef;
    auto iter1 = term1.vec.cbegin();
    auto iter2 = term2.vec.cbegin();
    while(iter1 != term1.vec.cend() && iter2 != term2.vec.cend())
    {
        if(iter1->ch < iter2->ch)
            tmp.vec.push_back(*iter1++);
        else if(iter1->ch > iter2->ch)
            tmp.vec.push_back(*iter2++);
        else if(iter1->ch == iter2->ch)
        {
            tmp.vec.push_back(group(iter1->ch,iter1->exp+iter2->exp));
            iter1++;
            iter2++;
        }
    }
    if(iter1 == term1.vec.cend() && iter2 != term2.vec.cend())
    {
        while(iter2 != term2.vec.cend())
            tmp.vec.push_back(*iter2++);
    }
    else if(iter2 == term2.vec.cend() && iter1 != term1.vec.cend())
    {
        while(iter1 != term1.vec.cend())
            tmp.vec.push_back(*iter1++);
    }
    if(tmp.vec.size() > 1)
        sort(tmp.vec.begin(),tmp.vec.end(),std::less<group>());
    return tmp;
}

term& term::differential(char c)
{
    for(auto iter = vec.begin();iter != vec.end();iter++)
    {
        if(c == iter->ch)
        {
            this->coef = this->coef * iter->exp;
            iter->exp--;
            return *this;
        }
    }
    this->coef = 0;
    this->vec.clear();
    return *this;
}

std::ostream& operator<<(std::ostream& os,const term& term1)
{
    if(term1.coef == -1)
    {
        if(term1.vec.empty())
            os << "-1";
        else os << "-";
    }
    else if(term1.coef == 1)
        os << "+";
    else if(term1.coef > 0)
        os << "+" << term1.coef;
    else os << term1.coef;
    for(auto r:term1.vec)
        os << r;
    return os;
}

std::ostream& operator<<(std::ostream &os,const Polynomial& poly)
{
    auto pri1(poly.pri);
    if(pri1.empty())
        return os;
    term *tmp = pri1.top();
    pri1.pop();
    if(tmp->coef == -1 && !tmp->vec.empty())
        os << "-";
    else if(tmp->coef != 1 || tmp->vec.empty())
        os << tmp->coef;
    for (auto r:tmp->vec)
        os << r;
    while(!pri1.empty())
    {
        tmp = pri1.top();
        pri1.pop();
        os << *tmp;
    }
    return os;
}

std::istream& operator>>(std::istream &is,Polynomial &poly)
{
    char ch = ' ';
    is >> ch;
    while(ch != ';')
    {
        if(isspace(ch))
        {
            is >> ch;
            continue;
        }
        term *term1 = new term();
        if(ch != '-' && ch !=  '+' && !isdigit(ch) && !isalpha(ch))
        {
            if(term1 != nullptr)
            {
                delete term1;
                term1 = nullptr;
            }
            exit(-1);
        }
        std::tie(term1,ch)  = poly.ExtractTerm(is,ch);
        std::sort(term1->vec.begin(),term1->vec.end(),std::less<group>());
        poly.pri.push(term1);
    }
    poly.MergeSimilarItems();
    return is;
}

tuple<term*,char> Polynomial::ExtractTerm(std::istream &is,char ch)
{
    term *term1 = new term();
    int sign = 1;
    if(ch == '+' || ch == '-')
    {
        sign = ch=='-'?-1:1;
        is >> ch;
    }
    while(isspace(ch))
    {
        is >>ch;
    }
    if(ch == ';')
        return std::make_tuple(term1,ch);
    if(ch == '0')
        return std::make_tuple(term1,ch);
    while (isdigit(ch))
    {
        term1->coef = 10 * term1->coef + ch - '0';
        is >> ch;
    }
    if(term1->coef != 0)
        term1->coef *= sign;
    else term1->coef = sign;
    group group1;
    while(ch != ';')
    {
        if(ch == '-' || ch == '+')
        {
            if(group1.exp == 0)
                group1.exp = 1;
            if(group1.ch != ' ')
                term1->vec.push_back(group1);
            return std::make_tuple(term1,ch);
        }
        if(isspace(ch))
        {
            is >> ch;
            continue;
        }
        if(!isdigit(ch) && !isalpha(ch))
            exit(-1);
        while(isdigit(ch))
        {
            group1.exp = 10 * group1.exp + ch - '0';
            is >> ch;
        }
        if(isalpha(ch))
        {
            if(group1.ch != ' ' && group1.ch != ch)
            {
                if(group1.exp == 0)
                    group1.exp = 1;
                term1->vec.push_back(group1);
                group1.exp = 0;
            }
            group1.ch = ch;
            is >> ch;
        }
    }
    if(group1.exp == 0)
        group1.exp = 1;
    if(group1.ch != ' ')
        term1->vec.push_back(group1);
    return std::make_tuple(term1,ch);
}

void Polynomial::MergeSimilarItems()
{
    map<term,int,std::less<term>> map_merge;
    while(!pri.empty())
    {
        term *tmp = pri.top();
        pri.pop();
        auto iter = map_merge.find(*tmp);
        if(iter != map_merge.end())
            iter->second += tmp->coef;
        else map_merge.insert(std::pair<term,int>(*tmp,tmp->coef));
    }
    for(auto r:map_merge)
    {
        term *term1 = new term(r.second,r.first.vec);
        pri.push(term1);
    }
    int i = 0;
}

Polynomial operator+(Polynomial &poly1,Polynomial &poly2)
{
    Polynomial polyno;
    auto p1(poly1.pri);
    auto p2(poly2.pri);
    auto p3(poly1.pri);
    term *term1,*term2;
    if(!p1.empty())
        term1 = p1.top();
    if(!p2.empty())
        term2 = p2.top();
    while(!p1.empty() || !p2.empty())
    {
        if(*term1 == *term2)
        {
            p1.pop();
            p2.pop();
            term *tmp = new term(*term1 + *term2);
            polyno.pri.push(tmp);
            if(!p1.empty())
                term1 = p1.top();
            if(!p2.empty())
                term2 = p2.top();
        }
        else if(*term1 < *term2)
        {
            p2.pop();
            term *tmp = new term(*term2);
            polyno.pri.push(tmp);
            if(!p2.empty())
                term2 = p2.top();
        }
        else
        {
            p1.pop();
            term *tmp = new term(*term1);
            polyno.pri.push(tmp);
            if(!p1.empty())
                term1 = p1.top();
        }
    }
    if(p1.empty())
    {
        while(!p2.empty())
        {
            term *tmp = new term(*(p2.top()));
            polyno.pri.push(tmp);
            p2.pop();
        }
    }
    if(p2.empty())
    {
        while(!p1.empty())
        {
            term *tmp = new term(*(p1.top()));
            polyno.pri.push(tmp);
            p1.pop();
        }
    }
    poly1.pri = p3;
    return polyno;
}

Polynomial operator*(Polynomial &poly1,Polynomial &poly2)
{
    Polynomial poly;
    auto pri_tmp1(poly1.pri);
    while(!pri_tmp1.empty())
    {
        const term *tmp1 = pri_tmp1.top();
        pri_tmp1.pop();
        auto pri_tmp2(poly2.pri);
        while(!pri_tmp2.empty())
        {
            const term *tmp2 = pri_tmp2.top();
            pri_tmp2.pop();
            term *t = new term(*tmp1 * *tmp2);
            poly.pri.push(t);
        }
    }
    poly.MergeSimilarItems();
    return poly;
}

Polynomial& Polynomial::differential(char c)
{
    priority_queue<term*,vector<term*>,cmp<term>> pri_tmp;
    while(!this->pri.empty())
    {
        term *tmp = pri.top();
        pri.pop();
        tmp->differential(c);
        if(tmp->coef != 0)
            pri_tmp.push(tmp);
    }
    while(!pri_tmp.empty())
    {
        this->pri.push(pri_tmp.top());
        pri_tmp.pop();
    }
    return *this;
}

void funcexit()
{
    cout << "funcexit()" << endl;
}

int main()
{
    atexit(funcexit);
//    多项式加法
    cout << "请输入两个多项式，以分号结束：" << endl;
    Polynomial poly1,poly2;
    cin >> poly1 >> poly2;
    cout << "相加之前:poly1 = " << poly1 << endl;
    cout << "相加之前:poly2 = " << poly2 << endl;
    clock_t time1 = clock();
    cout << "poly1 + poly2 = " << poly1 + poly2 << endl;
    cout << "耗时：" << clock() - time1 << "微秒" << endl;
    cout << "相加之后:poly1 = " << poly1 << endl;
    cout << "相加之后:poly2 = " << poly2 << endl;
//多项式乘法
    cout << "请输入两个多项式，以分号结束：" << endl;
    Polynomial poly3,poly4;
    cin >> poly3 >> poly4;
    cout << "相乘之前:poly3 = " << poly3 << endl;
    cout << "相乘之前:poly4 = " << poly4 << endl;
    time1 = clock();
    cout << "poly3 * poly4 = " << poly3 * poly4 << endl;
    cout << "耗时：" << clock() - time1 << "微秒" << endl;
    cout << "相乘之后:poly3 = " << poly3 << endl;
    cout << "相乘之后:poly4 = " << poly4 << endl;
    cout << "正常退出" << endl;
//多项式微分
    cout << "请输入两个多项式，以分号结束：" << endl;
    Polynomial poly5,poly6;
    cin >> poly5 >> poly6;
    cout << "相乘之前:poly5 = " << poly5 << endl;
    cout << "相乘之前:poly6 = " << poly6 << endl;
    time1 = clock();
    cout << "poly5的微分=" << poly5.differential('x') << endl;
    cout << "poly6的微分=" << poly6.differential('y') << endl;
    cout << "耗时：" << clock() - time1 << "微秒" << endl;
    cout << "相乘之后:poly5 = " << poly5 << endl;
    cout << "相乘之后:poly6 = " << poly6 << endl;
    cout << "正常退出" << endl;
    return 0;
}