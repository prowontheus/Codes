//
// Created by 丁月星 on 2020/7/31.
//

#ifndef A_OUT_REDBLACKTREE_H
#define A_OUT_REDBLACKTREE_H

#define BLACK 1
#define RED 0
#include <iostream>

using namespace std;

struct Node {
    int value;
    bool color;
    Node *leftTree, *rightTree, *parent;
    Node() : value(0), color(RED), leftTree(NULL), rightTree(NULL), parent(NULL) {}
    Node* grandparent() {
        if(parent == NULL)
            return NULL;
        return parent->parent;
    }
    Node* uncle() {
        if(grandparent() == NULL)
            return NULL;
        if(parent == grandparent()->rightTree)
            return grandparent()->leftTree;
        else
            return grandparent()->rightTree;
    }
    Node* sibling() {
        if(parent->leftTree == this)
            return parent->rightTree;
        else
            return parent->leftTree;
    }
};

class RedBlackTree {
private:
    void rotate_right(Node *p);
    void rotate_left(Node *p);
    void inorder(Node *p);
    string outputColor (bool color);
    Node* getSmallestChild(Node *p);
    bool delete_child(Node *p, int data);
    void delete_one_child(Node *p);
    void delete_case(Node *p);
    void insert(Node *p, int data);
    void insert_case(Node *p);
    void DeleteTree(Node *p);
public:
    RedBlackTree();
    ~RedBlackTree();
    void inorder();
    void insert (int x);
    bool delete_value (int data);
private:
    Node *root, *NIL;
};
#endif //A_OUT_REDBLACKTREE_H
