//
//  main.cpp
//  NC3
//
//  Created by admin on 2020/10/5.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
#include "LinkListHelper.hpp"

/// 对于一个给定的链表，返回环的入口节点，如果没有环，返回null
ListNode *detectCycle(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            ListNode *slow2 = head;
            while (slow != slow2) {
                slow2 = slow2->next;
                slow = slow->next;
            }
            return slow2;
        }
    }
    return nullptr;
}
int main(int argc, const char * argv[]) {
    return 0;
}
