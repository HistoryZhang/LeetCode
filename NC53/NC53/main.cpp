//
//  main.cpp
//  NC53
//
//  Created by admin on 2020/10/5.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>

#include "LinkListHelper.hpp"

/// 给定一个链表，删除链表的倒数第n个节点并返回链表的头指针
ListNode* removeNthFromEnd(ListNode* head, int n) {
    // write code here
    if (head == NULL) {
        return NULL;
    }
    ListNode *fast = head;
    ListNode *mid = head;
    ListNode *slow = head;

    while (n > 0) {
        fast = fast->next;
        -- n;
    }

    if (fast) {
        fast = fast->next;
        mid = mid->next;
    } else {
        // delete head
        mid = mid->next;
        delete head;
        return mid;
    }

    while (fast) {
        fast = fast->next;
        mid = mid->next;
        slow = slow->next;
    }
    // delete m
    slow->next = mid->next;
    delete mid;
    return head;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = { 1, 2, 3, 4, 5};
    vector<int> v(a, a + 5);
    ListNode *l = LinkListHelper::CreateLinkList(v);
    ListNode *ll = removeNthFromEnd(l, 5);
    LinkListHelper::PrintLinkList(ll);
    return 0;
}
