//
// Created by 丁月星 on 2020/9/11.
//

#ifndef A_OUT_ADDPOLYNOMIALS_H
#define A_OUT_ADDPOLYNOMIALS_H

#include <iostream>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Variable {
public:
    char id;
    int exp;
    Variable() { // required by <vector>;
    }
    Variable(char c, int i) {
        id = c; exp = i;
    }
    bool operator== (const Variable& v) const {
        return id  == v.id  && exp == v.exp;
    }
    bool operator< (const Variable& v) const { // used by sort();
        return id < v.id;
    }
};

class Term {
public:
    Term() {
        coeff = 0;
    }
    int coeff;
    vector<Variable> vars;
    bool operator== (const Term&) const;
    bool operator!= (const Term& term) const { // required by <list>
        return !(*this == term);
    }
    bool operator< (const Term&) const;
    bool operator> (const Term& term) const {  // required by <list>
        return *this != term && (*this < term);
    }
    int min(int n, int m) const {
        return (n < m) ? n : m;
    }
};

class Polynomial {
public:
    Polynomial() {
    }
    Polynomial operator+ (Polynomial&);
    void error(const char *s) {
        cerr << s << endl;
        exit(1);
    }
private:
    list<Term> terms;
    friend istream& operator>> (istream& in, Polynomial& polyn);
    friend ostream& operator<< (ostream& out, const Polynomial& polyn);
};

#endif //A_OUT_ADDPOLYNOMIALS_H
