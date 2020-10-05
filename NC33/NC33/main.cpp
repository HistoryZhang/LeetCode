//
//  main.cpp
//  NC33
//
//  Created by admin on 2020/10/2.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>

struct ListNode {
   int val;
   struct ListNode *next;
    ListNode(int x): val(x), next(nullptr){};
};


/// 将两个有序的链表合并为一个新链表，要求新的链表是通过拼接两个链表的节点来生成的。
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // write code here
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    
    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    cur = head->next;
    delete head; // 删除头结点
    return cur;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    return 0;
}
