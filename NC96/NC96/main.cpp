//
//  main.cpp
//  NC96
//
//  Created by admin on 2020/10/5.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
#include "LinkListHelper.hpp"

ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode *pre = nullptr;
    ListNode *next = head->next;
    while (head) {
        head->next = pre;
        pre = head;
        head = next;
        next = head->next;
    }
    return pre;
}

/// 给定一个链表，请判断该链表是否为回文结构。
bool isPail(ListNode* head) {
    // write code here
    if (head == nullptr) {
        return true;
    }
    ListNode *fast = head;
    ListNode *slow = head;
    if (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    // 翻转 slow 后半部分
    ListNode *tail = reverseList(slow);
    while (tail && head) {
        if (tail->val != head->val) {
            return false;
        }
        tail = tail->next;
        head = head->next;
    }
    return true;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
