//
//  main.cpp
//  NC119
//
//  Created by admin on 2020/10/5.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int quickSort(vector<int> &input, int left, int right) {
    // 一趟快排
    int flag = input[right];
    int i = left;
    for (int j = left; j < right; ++ j) {
        if (input[j] < flag) {
            swap(input[i++], input[j]);
        }
    }
    swap(input[i], input[right]);
    return i;
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    if (k == 0 || k > input.size()) {
        return {};
    }
    if (k == input.size()) {
        return input;
    }
    // 快排处理
    int flag = -1;
    int left = 0, right = (int)input.size() - 1;
    while (flag + 1 != k) {
        flag = quickSort(input, left, right);
        if (flag + 1 < k) {
            left = flag + 1;
        } else if (flag + 1 > k) {
            right = flag - 1;
        }
    }
    vector<int> p(input.begin(), input.begin() + flag + 1);
    return p;
}

vector<int> GetLeastNumbersByHeap(vector<int> input, int k) {
    if (k == 0 || k > input.size()) {
        return {};
    }
    if (k == input.size()) {
        return input;
    }
    // 构建大顶堆
    priority_queue<int, vector<int>, less<int> > heap;
    for (int i = 0; i < k; ++ i) {
        heap.push(input[i]);
    }
    for (int i = k; i < input.size(); ++ i) {
        if (input[i] < heap.top()) {
            heap.pop();
            heap.push(input[i]);
        }
    }
    vector<int> res;
    while (!heap.empty()) {
        res.push_back(heap.top());
        heap.pop();
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> input = { 4,5,1,6,2,7,3,8};
    vector<int> output = GetLeastNumbersByHeap(input, 4);
//    vector<int> output = GetLeastNumbers_Solution(input, 10);
    
    return 0;
}
