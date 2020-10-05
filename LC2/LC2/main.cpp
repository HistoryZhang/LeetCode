//
//  main.cpp
//  LC2
//
//  Created by admin on 2020/10/5.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
#include "LinkListHelper.hpp"

/// 2. 两数相加
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == NULL || l2 == NULL) {
        return l1 ? l1 : l2;
    }
    ListNode *res = l1;
    ListNode *pre = l1;
    bool carry = false;
    while (l1 && l2) {
        l1->val += (l2->val + (carry ? 1 : 0));
        if (l1->val >= 10) {
            l1->val -= 10;
            carry = true;
        } else {
            carry = false;
        }
        pre = l1;
        l1 = l1->next;
        l2 = l2->next;
    }
    if (l1 || l2) {
        ListNode *tmp = l1 ? l1 : l2;
        pre->next = tmp;
        while (tmp) {
            tmp->val += (carry ? 1 : 0);
            if (tmp->val >= 10) {
                tmp->val -= 10;
                carry = true;
            } else {
                carry = false;
            }
            pre = tmp;
            tmp = tmp->next;
        }
    }
    if (carry) {
        ListNode *last = new ListNode(1);
        pre->next = last;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    vector<int> v1 = { 2, 4, 3 };
    vector<int> v2 = { 5, 6, 4 };
    ListNode *l1 = LinkListHelper::CreateLinkList(v1);
    ListNode *l2 = LinkListHelper::CreateLinkList(v2);
    ListNode *res = addTwoNumbers(l1, l2);
    LinkListHelper::PrintLinkList(res);
    return 0;
}
