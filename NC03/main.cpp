//
//  main.cpp
//  Offer03
//
//  Created by admin on 2020/9/29.
//  Copyright © 2020 iflytek. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int findRepeatNumber(vector<int>& nums) {
    vector<bool> flag(nums.size(),false);
    for (int i = 0; i < nums.size(); ++ i) {
        if (flag[nums[i]]) {
            return nums[i];
        }
        flag[nums[i]] = true;
    }
    return -1;
}

int main(int argc, const char * argv[]) {
    int a[] = {1,2,3,4,5,6,2};
    vector<int> vec(a, a + 7);
    cout<<findRepeatNumber(vec)<<endl;
    return 0;
}
