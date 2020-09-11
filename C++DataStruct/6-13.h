//
// Created by 丁月星 on 2020/8/7.
//

#ifndef A_OUT_6_13_H
#define A_OUT_6_13_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::ifstream;
using std::ios;

template<typename T> class SplayTree;

template<typename T>
struct TreeNode{
    T val;
    TreeNode<T> *left,*right,*parent;
    TreeNode(){left = nullptr;right = nullptr;parent = nullptr;}
    TreeNode(const T& el,TreeNode<T> *l=nullptr,TreeNode<T> *r=nullptr,TreeNode<T> *p=nullptr):
            val(el),left(l),right(r),parent(p){}
};

template<typename T>
class SplayTree{
public:
    SplayTree(){root = nullptr;}
    T* search(const T& el);
    void insert(T& el);
    void del(const T& el);
    void deleteByMergeing(TreeNode<T> *l);
    void splay(TreeNode<T> *l);
    void rotateR(TreeNode<T> *l);
    void rotateL(TreeNode<T> *l);
    void inorder(){inorder(root);}
    void inorder(TreeNode<T> *l);
protected:
    TreeNode<T> *root;
    virtual void visit(TreeNode<T> *l){};
};

class Word
{
public:
    Word(){
        str = new char[64];
        freq = 1;
    }
    ~Word(){
        if(str)
        {
            delete[] str;
            str = nullptr;
        }
    }
    Word(const Word &w)
    {
            str = new char[strlen(w.str) + 1];
            strcpy(str,w.str);
            freq = w.freq;
    }
    bool operator<(const Word &w)const{return strcmp(str,w.str) < 0;}
    bool operator>(const Word &w)const{return strcmp(str,w.str) > 0;}
    bool operator==(const Word &w)const{return strcmp(str,w.str) == 0;}
    char *str;
    int freq;
    friend class WordSplay;
};

class WordSplay final: public SplayTree<Word>
{
public:
    WordSplay():different(0),totalwords(0){}
    void run(char *FileName);
    void visit(TreeNode<Word> *l);
private:
    int different;
    int totalwords;
};

#endif //A_OUT_6_13_H