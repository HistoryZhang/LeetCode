//
//  LinkListHelper.cpp
//  NC78
//
//  Created by admin on 2020/9/30.
//  Copyright © 2020 tsing. All rights reserved.
//

#include "LinkListHelper.hpp"



void LinkListHelper::PrintLinkList(ListNode *pHead) {
    ListNode *p = pHead;
    while (p != NULL) {
        cout<<p->val<<endl;
        p = p->next;
    }
    cout<<"-------"<<endl;
}


ListNode * LinkListHelper::CreateLinkList(vector<int> vec) {
    if (vec.size() == 0) {
        return NULL;
    }
    ListNode *pHead = new ListNode(vec[0]);
    ListNode *p = pHead;
    for (int i = 1; i < vec.size(); ++ i) {
        ListNode *node = new ListNode(vec[i]);
        p->next = node;
        p = node;
    }
    return pHead;
}

void LinkListHelper::DestoryLinkList(ListNode *pHead) {
    while (pHead != NULL) {
        ListNode *tmp = pHead;
        pHead = pHead->next;
        delete tmp;
    }
}
