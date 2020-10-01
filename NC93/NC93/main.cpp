//
//  main.cpp
//  NC93
//
//  Created by admin on 2020/10/1.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

/*
 * 设计LRU缓存结构，该结构在构造时确定大小，假设大小为K，并有如下两个功能
 * set(key, value)：将记录(key, value)插入该结构
 * get(key)：返回key对应的value值
 * [要求]
 * set和get方法的时间复杂度为O(1)
 * 某个key的set或get操作一旦发生，认为这个key的记录成了最常使用的。
 * 当缓存的大小超过K时，移除最不经常使用的记录，即set或get最久远的。
 * 若opt=1，接下来两个整数x, y，表示set(x, y)
 * 若opt=2，接下来一个整数x，表示get(x)，若x未出现过或已被移除，则返回-1
 * 对于每个操作2，输出一个答案
 */

using namespace std;

/*
 * 采用双向链表存储
 * 使用map来查找
 * 对于插入,先查找是否存在,不存在插入在头结点后,并判断空间是否超出;存在则将节点移至头结点后
 * 对于获取,先查找是否存在,不存在则返回-1;否则将节点移至头结点后,然后返回值
 */

struct DLinkNode {
    struct DLinkNode *prev;
    struct DLinkNode *next;
    int key, val;
    DLinkNode(int k, int v):key(k),val(v),prev(nullptr),next(nullptr){};
};


class Solution {
private:
    int size = 0;
    DLinkNode *tail;
    DLinkNode *head;
    map<int, DLinkNode*> mp;
    
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        if (k < 1) {
            return {};
        }
        
        this->size = k;
        this->head = new DLinkNode(0, 0);
        this->tail = new DLinkNode(0, 0);
        this->head->next = this->tail;
        this->tail->prev = this->head;
        
        if (operators.size() == 0) {
            return {};
        }
        vector<int> res;
        for (vector<int> op : operators) {
            if (op.size() == 0) {
                continue;
            }
            if (op[0] == 1 && op.size() >= 3) {
                set(op[1], op[2]);
            } else if (op[0] == 2 && op.size() >= 2) {
                int value = get(op[1]);
                res.push_back(value);
            }
        }
        return res;
    }
    
    void set(int key, int val) {
        if (mp.find(key) == mp.end()) {
            // 不存在
            DLinkNode *node = new DLinkNode(key, val);
            mp[key] = node;
            if (mp.size() > this->size) {
                removeLast();
            }
            insertToFirst(node);
        } else {
            mp[key]->val = val;
            moveToHead(mp[key]);
        }
    }
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            // 不存在
            return -1;
        }
        DLinkNode *node = mp[key];
        moveToHead(node);
        return node->val;
    }
    
    void moveToHead(DLinkNode *node) {
        if (node->prev == head) {
            // 头结点不需要移动
            return;
        }
        node->prev->next = node->next;
        node->next->prev = node->prev;
        insertToFirst(node);
    }
    
    void removeLast() {
        mp.erase(this->tail->prev->key);
        DLinkNode *node = this->tail->prev;
        node->prev->next = this->tail;
        this->tail->prev = node->prev;
        delete node;
    }
    
    void insertToFirst(DLinkNode *node) {
        node->prev = this->head;
        node->next = this->head->next;
        this->head->next->prev = node;
        this->head->next = node;
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> p;
    {
        int a[] = {1,1,1};
        vector<int> v(a, a + 3);
        p.push_back(v);
    }
    {
        int a[] = {1,2,2};
        vector<int> v(a, a + 3);
        p.push_back(v);
    }
    {
        int a[] = {1,3,2};
        vector<int> v(a, a + 3);
        p.push_back(v);
    }
    {
        int a[] = {2,1};
        vector<int> v(a, a + 2);
        p.push_back(v);
    }
    {
        int a[] = {1,4,4};
        vector<int> v(a, a + 3);
        p.push_back(v);
    }
    {
        int a[] = {2,2};
        vector<int> v(a, a + 2);
        p.push_back(v);
    }
    Solution *solution = new Solution();
    vector<int> res = solution->LRU(p, 3);
    for (int i : res) {
        cout<<i<<endl;
    }
    delete solution;
    return 0;
}
