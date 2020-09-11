//
// Created by 丁月星 on 2020/7/28.
//

#include "DSW.h"
int main()
{
    int a[] = { 5,10,20,15,30,25,40,23,28};
    DswBST<int> tree(a, sizeof(a) / sizeof(a[0]));
    tree.breadthFirst();
    cout << endl;
    tree.inorder();
    cout << endl;

    tree.dswBalance();
    tree.breadthFirst();
    cout << endl;
    tree.inorder();
    return 0;
}