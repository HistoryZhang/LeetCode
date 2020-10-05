//
//  main.cpp
//  NC66
//
//  Created by admin on 2020/10/5.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
        
    };
};
    
// 输入两个链表，找出它们的第一个公共结点。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）

ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
    if (pHead1 == NULL || pHead2 == NULL) {
        return NULL;
    }
    ListNode *p1 = pHead1;
    ListNode *p2 = pHead2;
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
        if (p1 != p2) {
            p1 = p1 ? p1 : pHead2;
            p2 = p2 ? p2 : pHead1;
        }
    }
    return p1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    return 0;
}
