//
// Created by 丁月星 on 2020/8/9.
//

#include "6-14.h"
#include <queue>
#include <tuple>

template<typename T>
TreeNode<T> *BinaryTree<T>::Sibling(TreeNode<T> *p)
{
    if(!p || p->parent == nullptr)
        return nullptr;
    if(p->parent->left == p)
        return p->parent->right;
    else return p->parent->left;
}

//********************************习题6.14.2********************************************************
//a.计算二叉树中的节点数目
template<typename T>
int BinaryTree<T>::ListCount(TreeNode<T> *p)
{
    int count = 0;
    std::queue<TreeNode<T> *> que = {0};
    if(p)
        que.push(p);
    while(!que.empty())
    {
        TreeNode<T> *tmp = que.pop();
        count++;
        if(tmp->left)
            que.push(tmp->left);
        if(tmp->right)
            que.push(tmp->right);
    }
    return count;
}
//b.计算叶子节点数目
template<typename T>
int BinaryTree<T>::LeafCount(TreeNode<T> *p)
{
    if(!p)
        return 0;
    if(p->left == nullptr && p->right == nullptr)
        return 1;
    int count;
    count += LeafCount(p->left);
    count += LeafCount(p->right);
    return count;
}
//c.计算右子节点的数目
template<typename T>
int BinaryTree<T>::RightCount(TreeNode<T> *p)
{
    if(!p)
        return 0;
    else if(p->parent == nullptr)
        return RightCount(p->left) + RightCount(p->right);
    else
        return (p->parent->right == p)?1:0 + RightCount(p->left) + RightCount(p->right);
}
//计算右叶子节点数目
template<typename T>
int BinaryTree<T>::RightLeafCount(TreeNode<T> *p)
{
    if(!p)
        return 0;
    if(p->left == nullptr && p->right == nullptr)
    {
        if (p->parent->right == p)
            return 1;
        else return 0;
    }
    int count;
    count += RightLeafCount(p->left);
    count += RightLeafCount(p->right);
    return count;
}
//d计算树的高度
template<typename T>
int BinaryTree<T>::Height(TreeNode<T> *p)
{
    if(!p)
        return 0;
    if(p->left == nullptr && p->right == nullptr)
        return 1;
    int left = Height(p->left);
    int right = Height(p->right);
    return 1 + left>right?left:right;
}
//e.删除二叉树中的所有叶子节点
template<typename T>
void BinaryTree<T>::DeleteLeaf(TreeNode<T> *p)
{
    if(!p)
        return;
    else if(p == root)
    {
        delete p;
        root = nullptr;
    }
    if(p->left == nullptr && p->right == nullptr)
    {
        if(p->parent->left == p)
        {
            p->parent->left = nullptr;
            delete p;
        }
        else
        {
            p->parent->right = nullptr;
            delete p;
        }
    }
    else
    {
        DeleteLeaf(p->left);
        DeleteLeaf(p->right);
    }
}
//*********************************习题6.14.3*****************************************************
//检查二叉树是否完全平衡
template<typename T>
bool BinaryTree<T>::IsBalance(TreeNode<T> *p)
{
    return (fabs(Height(p->left),Height(p->right)) <= 1) ? true : false;
}
//*********************************习题6.14.4*****************************************************
//测试二叉树是否二叉查找树
template<typename T>
bool BinaryTree<T>::IsBinarySearchTree(TreeNode<T> *p)
{
    if(!p)
        return true;
    if(p->left == nullptr && p->right == nullptr)
        return true;
    if(p->left == nullptr)
        return (p->right->val >= p->val) ? IsBinarySearchTree(p->right) : false;
    else if(p->right == nullptr)
        return (p->left->val <= p->val) ? IsBinarySearchTree(p->left) : false;
    else if((p->left->val <= p->val) && (p->right->val >= p->val))
        return IsBinarySearchTree(p->left) && IsBinarySearchTree(p->right);
    else return false;
}
//**********************************习题6.14.10***************************************************
//创建二叉查找树的镜像（代码可能不正确，有待验证）
template<typename T>
TreeNode<T> *BinaryTree<T>::MirrorTree(TreeNode<T> *p)
{
    if(!p)
        return nullptr;
    TreeNode<T> *Mirror = nullptr;
    TreeNode<T> *tmp1 = p;
    TreeNode<T> *tmp2 = nullptr;
    std::queue<std::tuple<int,TreeNode<T> *>> que = {0};
    que.push(std::make_tuple(0,tmp1));
    while(!que.empty())
    {
        std::tuple<int,TreeNode<T> *> tup = que.pop();
        auto ret1 = std::get<0>(tup);
        auto ret2 = std::get<1>(tup);
        if(ret1 == 0)//原来的树的根
        {
            Mirror = new TreeNode<T>(ret2->val);
            tmp2 = Mirror;
        }
        else if(ret1 == -1)//原来的树的左子节点
        {
            if(!tmp2->right)
                tmp2->right = new TreeNode<T>(ret2->val,0,0,tmp2->right);
            else
            {
                tmp2 = Sibling(tmp2);
                tmp2->right = new TreeNode<T>(ret2->val);
            }
        }
        else if(ret1 == 1)//原来的树的右子节点
        {
            if(!tmp2->left)
                tmp2->left = new TreeNode<T>(ret2->val,0,0,tmp2->left);
            if(tmp2->parent)
            {
                while (tmp2->parent && tmp2->parent->left == tmp2)
                    tmp2 = tmp2->parent;
                if(tmp2 != root)
                {
                    tmp2 = Sibling(tmp2);
                    do
                    {
                        if(tmp2->right == nullptr)
                            tmp2 = tmp2->left;
                        else tmp2 = tmp2->right;
                    }while(tmp2->right && tmp2->left);
                }
                else
                {
                    while(tmp2->right)
                        tmp2 = tmp2->right;
                }
            }
            else tmp2 = tmp2->right;
        }
        if(ret2->left)
            que.push(std::make_tuple(-1, ret2->left));
        if(ret2->right)
            que.push(std::make_tuple(1, ret2->right));
    }
}

int main()
{
    return 0;
}