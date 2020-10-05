//
//  main.cpp
//  NC88
//
//  Created by admin on 2020/10/1.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int quickSort(vector<int> &a, int left, int right, int K) {
    int flag = a[left];
    int i = left;
    int j = right;
    while (i < j) {
        
        while (i < j && a[j] >= flag) { // 一定要先确定j的位置
            -- j;
        }
        
        while (i < j && a[i] <= flag) {
            ++ i;
        }
        
        if (i < j) {
            swap(a[i], a[j]);
        }
    }
    swap(a[left], a[j]);
    if (a.size() - j == K) {
        return a[j];
    } else if (a.size() - j < K) {
        return quickSort(a, left, j - 1, K);
    } else {
        return quickSort(a, j + 1, right, K);
    }
}

/*
 * 有一个整数数组，请你根据快速排序的思路，找出数组中第K大的数。
 * 给定一个整数数组a,同时给定它的大小n和要找的K(K在1到n之间)，请返回第K大的数，保证答案存在。
 */
int findKth(vector<int> a, int n, int K) {
    // write code here
    if (a.size() == 0 || K > n) {
        return INT_MIN;
    }
    return quickSort(a, 0, (int)a.size()-1, K);
}

/*
 * 我们还可以是使用K个元素最小堆来求解,这样根就是第K大
 * 我们构建一个K个元素的小顶堆
 */

int findKthByHeap(vector<int> &a, int K) {
    // 建立K个元素小顶堆
    priority_queue<int, vector<int>, greater<int> > heap;
    // 大顶堆定义如下
//    priority_queue<int, vector<int>, less<int> > heap;
    for (int i = 0; i < K; ++ i) {
        heap.push(a[i]);
    }
    for (int i = K; i < a.size(); ++ i) {
        if (a[i] > heap.top()) {
            heap.pop();
            heap.push(a[i]);
        }
    }
    return heap.top();
}

int main(int argc, const char * argv[]) {
    int a[] = {5,6,3,4,7};
    vector<int> v(a, a + 5);
//    cout<<findKth(v, 5, 3)<<endl;
    cout<<findKthByHeap(v, 3)<<endl;
    return 0;
}
