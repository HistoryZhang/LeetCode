//
//  main.cpp
//  NC78
//
//  Created by admin on 2020/9/30.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

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

void PrintNode(ListNode *pHead) {
    ListNode *p = pHead;
    while (p != NULL) {
        cout<<p->val<<endl;
        p = p->next;
    }
    cout<<"-------"<<endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *pHead = new ListNode(1);
    ListNode *p = pHead;
    for (int i = 2; i < 5; ++ i) {
        ListNode *node = new ListNode(i);
        p->next = node;
        p = node;
    }
    
    PrintNode(pHead);
    
    ListNode *res = ReverseList(pHead);
    PrintNode(res);
    
    return 0;
}
