//
//  main.cpp
//  NC105
//
//  Created by admin on 2020/10/1.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * 二分查找
 * 请实现有重复数字的有序数组的二分查找。
 * 输出在数组中第一个大于等于查找值的位置，如果数组中不存在这样的数，则输出数组长度加一。
 * @param n int整型 数组长度
 * @param v int整型 查找值
 * @param a int整型vector 有序数组
 * @return int整型
 */
int upperBound(int n, int v, vector<int>& a) {
    // write code here
    if (a.size() == 0) {
        return 1;
    }
    
    int left = 0, right = (int)a.size() - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (a[mid] > v) {
            right = mid - 1;
        } else if (a[mid] < v) {
            left = mid + 1;
        } else {
            -- right; // 必须从尾部减
        }
    }
    
    if (a[left] >= v) {
        // 返回的索引从1开始
        return left + 1 >= (int)a.size() ? (int)a.size() + 1 : left + 1;
    } else {
        return (int)a.size() + 1;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = { 1,1,2,3,7,7,7,9,9,10};
    vector<int> p(a, a + 10);
    cout<<upperBound(10, 1, p)<<endl;
    return 0;
}
