//
// Created by 丁月星 on 2020/7/28.
//

#ifndef A_OUT_DSW_H
#define A_OUT_DSW_H


#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<list>
#include<stack>
#include<queue>
using namespace std;

//栈实现
template<typename T>
class Stack : public stack<T> {
public:
    T pop() {
        T tmp = stack<T>::top();
        stack<T>::pop();
        return tmp;
    }
};

//队列实现
template<typename T>
class Queue : public queue<T> {
public:
    T dequeue() {
        T tmp = queue<T>::front();
        queue<T>::pop();
        return tmp;
    }
    void enqueue(const T& el) {
        queue<T>::push(el);
    }
};

//树节点类
template<typename T>
class Node {
public:
    Node():left(NULL),right(NULL){}
    Node(const T& e,Node<T>* l=NULL,Node<T>*r=NULL):data(e),left(l),right(r){}
    ~Node(){}
    T data;
    Node* left;
    Node* right;
};

//二叉查找树的实现类
template<typename T>
class BST {
public:
    BST():root(NULL),count(0){}
    BST(T* a, int len);	//根据数组中的数据构造树，调试测试用
    ~BST() {
        clear();
    }
    bool isEmpty() const {
        return NULL == root;
    }
    void clear() {
        clear(root);
        root = NULL;
    }
    uint count;
    void insert(const T&);		//插入
    void inorder() {//深度遍历之中序树遍历
        inorder(root);
    }
    void breadthFirst();		//广度优先遍历
    virtual void visit(Node<T>* p) {
        cout << p->data << ' ';
    }
protected:
    Node<T>* root; //根节点
    void clear(Node<T>*);
    void inorder(Node<T>*);
};

//根据数组中的内容构造树
template<typename T>
BST<T>::BST(T* a, int len) {
    root = NULL;
    count = 0;
    for (int i = 0; i < len; i++) {
        insert(a[i]);
    }
}

//清除节点p及其子节点
template<typename T>
void BST<T>::clear(Node<T> *p) {
    if (p != NULL) {
        clear(p->left);
        clear(p->right);
        delete p;
    }

    count = 0;
}

//插入，非递归形式
template<typename T>
void BST<T>::insert(const T& el) {
    Node<T> *p = root, *prev = NULL;
    while (p != NULL) {  // find a place for inserting new node;
        prev = p;
        if (el < p->data)
            p = p->left;
        else p = p->right;
    }
    if (root == NULL)    // tree is empty;
        root = new Node<T>(el);
    else if (el < prev->data)
        prev->left = new Node<T>(el);
    else prev->right = new Node<T>(el);

    ++count;
}

//广度优先遍历（从上到下，从左到右，一层一层的向下访问）
template<typename T>
void BST<T>::breadthFirst() {
    Queue<Node<T>*> m_queue;	//要理解这里为什么要用队列，这个队列的作用是把下一层的数据放到本层数据的后面
    Node<T>* p = root;
    if (p != NULL) {
        m_queue.enqueue(p);
        while (!m_queue.empty()) {
            p = m_queue.dequeue();
            visit(p);
            if (p->left != NULL)
                m_queue.enqueue(p->left);
            if (p->right != NULL)
                m_queue.enqueue(p->right);
        }
    }
}

//中序遍历，递归实现
template<typename T>
void BST<T>::inorder(Node<T> *p) {
    if (p != NULL) {
        inorder(p->left);
        visit(p);
        inorder(p->right);
    }
}

template<typename T>
class DswBST: public BST<T> {
public:
    DswBST(T* a, int len);    //根据数组中的数据构造树，调试测试用
    void dswBalance();
protected:
    void createBackbone();
    void creatPerfectTree();
    void rotateRight(Node<T>* Gr, Node<T>* Par, Node<T>* Ch);
    void rotateLeft(Node<T>* Gr, Node<T>* Par, Node<T>* Ch);
};

template<typename T>
DswBST<T>::DswBST(T* a, int len) {
    for (int i = 0; i < len; i++) {
        this->insert(a[i]);
    }
}

template<typename T>
void DswBST<T>::dswBalance() {
    createBackbone();
    creatPerfectTree();
}

// 二叉查找树转化成主链的过程分析
/**********************************************************************************************
*  5 <-tmp         5               5               5              5
*   \               \               \               \               \
*    10             10              10              10              10
*      \              \               \               \               \
*       20            15              15              15              15
*      /  \             \               \               \               \
*     15  30            20              20              20              20
*         / \             \              \                \               \
*        25 40            30 <-tmp       25 <-tmp         23               23
*       /  \             /  \           /  \               \                \
*     23    28          25   40        23   30              25              25
*                      /  \                /  \              \                \
*                     23   28             28   40            30 <-tmp         28
*                                                           /  \               \
*                                                          28  40               30
*                                                                                \
*                                                                                 40 <-tmp
***********************************************************************************************/
template<typename T>
void DswBST<T>::createBackbone() {
    Node<T> *Gr = 0, *Par = this->root, *Ch = 0;
    while(Par != 0) {
        Ch = Par->left;
        if(Ch != 0) {
            rotateRight(Gr, Par, Ch);
            Par = Ch;
        } else {
            Gr = Par;
            Par = Par->right;
        }
        // 旋转过程中，如果是绕根节点的右节点旋转时要将根节点置为原根节点的右节点
        if(Gr == 0)
            this->root = Ch;
    }
}

/************************************************************************
 *  子节点Ch围绕父节点Par的右旋转
 *   Before      After
 *    Gr          Gr
 *     \           \
 *     Par         Ch
 *    /  \        /  \
 *   Ch   Z      X   Par
 *  /  \            /  \
 * X    Y          Y    Z
 ***********************************************************************/
template<typename T>
void DswBST<T>::rotateRight(Node<T>* Gr, Node<T>* Par, Node<T>* Ch) {
    if(Gr != 0)
        Gr->right = Ch;
    Par->left = Ch->right;
    Ch->right = Par;
}

template<typename T>
void DswBST<T>::rotateLeft(Node<T>* Gr, Node<T>* Par, Node<T>* Ch) {
    if(Gr != 0)
        Gr->right = Ch;
    Par->right = Ch->left;
    Ch->left = Par;
}

template<typename T>
void DswBST<T>::creatPerfectTree() {
    int n = this->count;
    if (n < 3) {
        return; //节点数目小于3不用平衡
    }
    int m = (1 << ((int)(log10(n+1)/log10(2)))) - 1;
    Node<T> *Gr = 0;
    Node<T> *Par = this->root;
    Node<T> *Ch = this->root->right;

    this->root = this->root->right; //修改root指针
    // 第一阶段： 左旋n-m次
    for(int i = 0; i < n - m; i++) {
        rotateLeft(Gr, Par, Ch);
        Gr = Ch;
        Par = Gr->right;
        if (0 != Par) {
            Ch = Par->right;
        } else {
            break;
        }
    }

    // 第二阶段，进入while循环
    while( m > 1) {
        m = m >> 1;
        Node<T> *Gr = 0;
        Node<T> *Par = this->root;
        Node<T> *Ch = this->root->right;

        this->root = this->root->right;
        for(int i = 0; i < m; i++) {
            rotateLeft(Gr, Par, Ch);
            Gr = Ch;
            Par = Gr->right;
            if (0 != Par) {
                Ch = Par->right;
            } else {
                break;
            }
        }
    }
}


#endif //A_OUT_DSW_H
