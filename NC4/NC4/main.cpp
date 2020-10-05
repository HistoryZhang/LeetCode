//
//  main.cpp
//  NC4
//
//  Created by admin on 2020/10/2.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    if (head == NULL) {
        return false;
    }
    ListNode *p = head;
    ListNode *q = head;
    while (q != NULL && q->next != NULL) {
        p = p->next;
        q = q->next->next;
        if (p == q) {
            return true;
        }
    }
    return false;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    return 0;
}
