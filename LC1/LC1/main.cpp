//
//  main.cpp
//  LC1
//
//  Created by admin on 2020/10/5.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> hash;
    for (int i = 0; i < nums.size(); ++ i) {
        if (hash.find(target - nums[i]) != hash.end()) {
            return {hash[target-nums[i]], i};
        }
        hash[nums[i]] = i;
    }
    return {};
}

int main(int argc, const char * argv[]) {
    return 0;
}
