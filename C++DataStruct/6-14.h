//
// Created by 丁月星 on 2020/8/10.
//

#ifndef A_OUT_6_14_H
#define A_OUT_6_14_H

#include <iostream>
#include <queue>
#include <stack>
#include <cmath>

template<typename T>
struct TreeNode{
    T val;
    int BalanceFactor;
    TreeNode<T> *left,right,parent;
    TreeNode(const T& el):val(el){}
    TreeNode(const T& el=0,
             TreeNode<T> *l=nullptr,
             TreeNode<T> *r=nullptr,
             TreeNode<T> *p=nullptr,
             int b=0)
    {
        val = el;
        left = l;
        right = r;
        parent = p;
        BalanceFactor = 0;
    }
};

template<typename T>
class BinaryTree{
public:
    BinaryTree(){root = nullptr;balanceFactor = 0;}
    BinaryTree(TreeNode<T> *p):root(p){}
    TreeNode<T> *Sibling(TreeNode<T> *p);
    void insert(const T& el);
    void del(const T& el);//删除值为el的元素
    T* search(const T& el);
    void inorder(){inorder(root);}
    void inorder(TreeNode<T> *p);
    void visit(TreeNode<T> *p);
    void rotateR(TreeNode<T> *p);
    void rotateL(TreeNode<T> *p);
    int ListCount(TreeNode<T> *p);//计算以P为根的树的节点数目
    int LeafCount(TreeNode<T> *p);//计算以P为根的树的叶子节点数目
    int RightCount(TreeNode<T> *p);//计算右子节点的数目
    int RightLeafCount(TreeNode<T> *p);//计算以P为根节点的树的右子节点的数目
    int Height(TreeNode<T> *p);//计算以P为根节点的树的高度
    void DeleteLeaf(TreeNode<T> *p);//删除以P为根节点的二叉树的所有叶节点
    bool IsBalance(){return IsBalance(root);}//树是否平衡
    bool IsBalance(TreeNode<T> *p);//以p为根节点的树是否平衡
    int Balance(TreeNode<T> *p){//返回以p为根节点的树的平衡因子
        return Height(p->left) - Height(p->right);
    }
    bool IsBinarySearchTree(TreeNode<T> *p);//判断二叉树是否为二叉查找树
    TreeNode<T> *MirrorTree(TreeNode<T> *p);//创建二叉查找树的镜像
private:
    TreeNode<T> *root;
    int balanceFactor;//左子树高度 - 右子树高度
};

#endif //A_OUT_6_14_H