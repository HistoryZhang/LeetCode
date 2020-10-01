//
//  LinkListHelper.hpp
//  NC78
//
//  Created by admin on 2020/9/30.
//  Copyright © 2020 tsing. All rights reserved.
//

#ifndef LinkListHelper_hpp
#define LinkListHelper_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

class LinkListHelper {
    
    
public:
    static void PrintLinkList(ListNode *node);
    static ListNode * CreateLinkList(vector<int> vec);
    static void DestoryLinkList(ListNode *pHead);
};

#endif /* LinkListHelper_hpp */
