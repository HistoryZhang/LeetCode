//
//  main.cpp
//  NC40
//
//  Created by admin on 2020/10/5.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
#include "LinkListHelper.hpp"

ListNode *reverseList(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    ListNode *pre = nullptr;
    ListNode *next = head->next;
    while (head) {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }
    return pre;
}
/// 链表相加
ListNode* addInList(ListNode* head1, ListNode* head2) {
    // write code here
    if (head2 == nullptr || head1 == nullptr) {
        return head1 ? head1 : head2;
    }
    head1 = reverseList(head1);
    head2 = reverseList(head2);
    ListNode *res = head1;
    ListNode *pre = head1;
    bool carry = false;
    while (head1 && head2) {
        head1->val += (head2->val + (carry ? 1 : 0));
        if (head1->val >= 10) {
            head1->val %= 10;
            carry = true;
        } else {
            carry = false;
        }
        pre = head1;
        head2 = head2->next;
        head1 = head1->next;
    }
    ListNode *tmp = head1 ? head1 : head2;
    while (tmp) {
        tmp->val += (carry ? 1 : 0);
        if (tmp->val >= 10) {
            tmp->val %= 10;
            carry = true;
        } else {
            carry = false;
        }
        pre->next = tmp;
        pre = tmp;
        tmp = tmp->next;
    }
    if (carry) {
        ListNode *last = new ListNode(1);
        pre->next = last;
    }
    return reverseList(res);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    int a[] = { 5,9,2,3,7,4,9,9,0,2,6,6,1,3,8,3,2,1,9,8,4,3,1,3,3,7,5,3,9,3,1,3,1};
    int b[] = { 4,2,8,3,5,1,0,5,7,4,5,0,2,5,0,3,9,7,3,6,8,4,4,9,7,1};
    vector<int> v1(a, a + 33);
    vector<int> v2(b, b + 26);
    ListNode *p = LinkListHelper::CreateLinkList(v1);
    ListNode *q = LinkListHelper::CreateLinkList(v2);
    LinkListHelper::PrintLinkList(p);
    LinkListHelper::PrintLinkList(q);
    ListNode *m = addInList(p, q);
    LinkListHelper::PrintLinkList(m);
    return 0;
}
