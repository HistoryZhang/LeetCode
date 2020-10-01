//
//  main.cpp
//  NC78
//
//  Created by admin on 2020/9/30.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
#include "LinkListHelper.hpp"

using namespace std;

/// 输入一个链表，反转链表后，输出新链表的表头。
ListNode* ReverseList(ListNode* pHead) {
    if (pHead == NULL || pHead->next == NULL) {
        return pHead;
    }
    ListNode *pre = NULL;
    ListNode *next = NULL;
    while (pHead != NULL) {
        next = pHead->next;
        pHead->next = pre;
        pre = pHead;
        pHead = next;
    }
    return pre;
}

/// 翻转链表前m节点
/// @param pHead 头结点
/// @param n 总长度
/// @param m 翻转数
ListNode *RevLinkList(ListNode *pHead, int n, int m) {
    if (m > n) {
        return pHead;
    }
    if (pHead == NULL) {
        return pHead;
    }
    ListNode *p = pHead;
    ListNode *pre = NULL;
    ListNode *next = NULL;
    for (int i = 0; i < m; ++ i) {
        next = pHead->next;
        pHead->next = pre;
        pre = pHead;
        pHead = next;
    }

    if (next) {
        p->next = next;
    }

    return pre;
}

int main(int argc, const char * argv[]) {
    int a[] = {1, 2, 3, 4, 5};
    vector<int> vec(a, a + 5);

    ListNode *pHead = LinkListHelper::CreateLinkList(vec);
    
    LinkListHelper::PrintLinkList(pHead);
    
    ListNode *res = RevLinkList(pHead, 5, 3);
    LinkListHelper::PrintLinkList(res);
    
    
    return 0;
}
