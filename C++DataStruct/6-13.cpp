//
// Created by 丁月星 on 2020/8/7.
//
#include "6-13.h"

template<typename T>
T* SplayTree<T>::search(const T &el)
{
    TreeNode<T> *node = root;
    while(node)
    {
        if(el < node->val)
            node = node->left;
        else if(el > node->val)
            node = node->right;
        else
        {
            splay(node);
            return &node->val;
        }
    }
    return 0;
}

template<typename T>
void SplayTree<T>::insert(T &el)
{
    if(root == nullptr)
        root = new TreeNode<T>(el);
    else
    {
        TreeNode<T> *node = root;
        TreeNode<T> *prev = nullptr;
        TreeNode<T> *l = new TreeNode<T>(el);
        while(node)
        {
            prev = node;
            if(el < node->val)
                node = node->left;
            else if(el > node->val)
                node = node->right;
            else break;
        }
        if(prev->val > el)
        {
            prev->left = l;
            l->parent = prev;
        }
        else if(prev->val < el)
        {
            prev->right = l;
            l->parent = prev;
        }
    }
}

template<typename T>
void SplayTree<T>::del(const T& el)
{
    TreeNode<T> *node = root;
    while(node)
    {
        if(el < node->val)
            node = node->left;
        else if(el > node->val)
            node = node->right;
        else
        {
            deleteByMergeing(node);
            break;
        }
    }
}

template<typename T>
void SplayTree<T>::deleteByMergeing(TreeNode<T> *l)
{
    TreeNode<T> *node = l;
    if(node->left)
    {
        node = node->left;
        while(node)
        {
            if(node->right)
                node = node->right;
            else break;
        }
        l->val = node->val;
        deleteByMergeing(node);
    }
    else if(node->right)
    {
        node = node->right;
        while(node)
        {
            if(node->left)
                node = node->left;
            else break;
        }
        l->val = node->val;
        deleteByMergeing(node);
    }
    else
    {
        if(l == root)
        {
            delete l;
            root = nullptr;
        }
        else
        {
            TreeNode<T> *p = l->parent;
            if (p->left == l)
                p->left = nullptr;
            else p->right = nullptr;
            delete l;
            splay(p);
        }
    }
}

template<typename T>
void SplayTree<T>::splay(TreeNode<T> *l)
{
    TreeNode<T> *R = l;
    TreeNode<T> *Q = R->parent;
    while(R != root)
    {
        Q = R->parent;//很重要
        if(Q == root)
        {
            if (Q->left == R)
                rotateR(R);
            else rotateL(R);
        }
        else if((Q->parent->left == Q && Q->left == R) || (Q->parent->right == Q && Q->right == R))//同构情况
        {
            if(Q->parent->left == Q)
            {
                rotateR(Q);
                R = R->parent;//半张开策略
//                rotateR(R);//张开策略
            }
            else//Q->parent->right == Q
            {
                rotateL(Q);
                R = R->parent;//半张开策略
//                rotateL(R);//张开策略
            }
        }
        else//异构情况
        {
            if(Q->parent->left == Q)
            {
                rotateL(R);
                rotateR(R);
            }
            else//Q->parent->right == Q
            {
                rotateR(R);
                rotateL(R);
            }
        }
    }
}

template<typename T>
void SplayTree<T>::rotateR(TreeNode<T> *l)
{
    TreeNode<T> *P = l->parent;
    TreeNode<T> *G = P->parent;
    P->left = l->right;
    if(G)
    {
        if(G->left == P)
            G->left = l;
        else G->right = l;
    }
    else root = l;
    l->parent = G;
    P->parent = l;
    l->right = P;
    if(P->left)//很重要
        P->left->parent = P;
}

template<typename T>
void SplayTree<T>::rotateL(TreeNode<T> *l)
{
    TreeNode<T> *P = l->parent;
    TreeNode<T> *G = P->parent;
    P->right = l->left;
    if(G)
    {
        if(G->left == P)
            G->left = l;
        else G->right = l;
    }
    else root = l;
    l->parent = G;
    P->parent = l;
    l->left = P;
    if(P->right)
        P->right->parent = P;
}

template<typename T>
void SplayTree<T>::inorder(TreeNode<T> *l)
{
    if(l)
    {
        inorder(l->left);
        visit(l);
        inorder(l->right);
    }
}

void WordSplay::run(char *FileName)
{
    std::fstream ifs;
    ifs.open(FileName,ios::in);
    if(!ifs)
    {
        cerr << "打开" << FileName << "出错!" << endl;
        return;
    }
    char ch;
    char tmp[64];
    Word w;
    while(!ifs.eof())
    {
        int i = 0;
        ch=ifs.get();
        if(isalpha(ch))
        {
            for(i = 0;!ifs.eof() && isalpha(ch) && i < 64;i++)
            {
                ch = tolower(ch);
                tmp[i] = ch;
                ch = ifs.get();
            }
        }
        else continue;
        tmp[i] = '\0';
        strcpy(w.str,tmp);
        Word* p = search(w);//一定要对word定义拷贝构造函数，并且要是深拷贝
        if(p)
            p->freq++;
        else
            insert(w);
    }
    inorder();
    cout << "File " << FileName << " contains " << totalwords << " words among which " << different << " are different" << endl;
    if(ifs.is_open())
        ifs.close();
}

void WordSplay::visit(TreeNode<Word> *l)
{
    different++;
    cout << l->val.str << "出现了" << l->val.freq << "次" << endl;
    totalwords += l->val.freq;
}

int main(int argc,char **argv)
{
    char FileName[1024] = {0};
    if(argc != 2)
    {
        cout << "请输入文件名：";
        cin >> FileName;
    }
    else
        strcpy(FileName,argv[1]);
    WordSplay *ws = new WordSplay();
    auto time1 = clock();
    ws->run(FileName);
    auto time2 = clock();
    std::cout << "全程耗时：" << (float)(time2-time1)/1000 << "毫秒" << std::endl;
    delete ws;
    return 0;
}