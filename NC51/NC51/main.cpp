//
//  main.cpp
//  NC51
//
//  Created by admin on 2020/10/5.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
#include <vector>
#include "LinkListHelper.hpp"

using namespace std;

//struct ListNode {
//    int val;
//    struct ListNode *next;
//    ListNode(int x) : val(x), next(NULL) {
//    }
//};

ListNode *merge2List(ListNode *l1, ListNode *l2) {
    if (!l1 || !l2) {
        return l1 ? l1 : l2;
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
    delete head;
    return cur;
}

ListNode *mergeKListByBanary(vector<ListNode *> &list, int left, int right) {
    int step = right - left;
    if (step == 0) {
        return list[left];
    }
    if (step == 1) {
        return merge2List(list[left], list[right]);
    }
    if (step > 0) {
        int mid = (left + right) / 2;
        ListNode *l1 = mergeKListByBanary(list, left, mid);
        ListNode *l2 = mergeKListByBanary(list, mid + 1, right);
        return merge2List(l1, l2);
    }
    return NULL;
}
/// 合并\ k k 个已排序的链表并将其作为一个已排序的链表返回。分析并描述其复杂度。
ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) {
        return NULL;
    }
    ListNode *p = mergeKListByBanary(lists, 0, (int)lists.size() - 1);
    return p;
}


int main(int argc, const char * argv[]) {
    int a1[] = { 2, 8, 10, 15};
    int a2[] = { 3, 4,  19, 35};
    int a3[] = { 6, 13, 17, 23};
    int a4[] = { 11, 21, 31, 41};
    vector<int> v1(a1, a1 + 4);
    vector<int> v2(a2, a2 + 4);
    vector<int> v3(a3, a3 + 4);
    vector<int> v4(a4, a4 + 4);
    ListNode *l1 = LinkListHelper::CreateLinkList(v1);
    ListNode *l2 = LinkListHelper::CreateLinkList(v2);
    ListNode *l3 = LinkListHelper::CreateLinkList(v3);
    ListNode *l4 = LinkListHelper::CreateLinkList(v4);
    vector<ListNode *> list;
    list.push_back(l1);
    list.push_back(l2);
    list.push_back(l3);
    list.push_back(l4);
    ListNode *res = mergeKLists(list);
    LinkListHelper::PrintLinkList(res);
    return 0;
}
