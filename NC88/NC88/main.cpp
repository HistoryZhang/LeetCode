//
//  main.cpp
//  NC88
//
//  Created by admin on 2020/10/1.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
#include <vector>

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

int main(int argc, const char * argv[]) {
    int a[] = {5,6,3,4,7};
    vector<int> v(a, a + 5);
    cout<<findKth(v, 5, 3)<<endl;
    return 0;
}
