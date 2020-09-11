//
// Created by 丁月星 on 2020/8/6.
//
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry   = 0;
        int cur_num = 0;
        ListNode *root = new ListNode(cur_num);
        ListNode *node = root;
        while(l1 != nullptr || l2 != nullptr || carry != 0)
        {
            cur_num = ((l1?l1->val:0) + (l2?l2->val:0) + carry) % 10;
            node->val = cur_num;
            carry   = ((l1?l1->val:0) + (l2?l2->val:0) + carry) / 10;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
            if(l1 != nullptr || l2 != nullptr || carry != 0)
            {
                node->next = new ListNode(0);
                node = node->next;
            }
        }
        node->next = nullptr;
        return root;
    }
};