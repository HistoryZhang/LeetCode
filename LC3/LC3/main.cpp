//
//  main.cpp
//  LC3
//
//  Created by admin on 2020/10/5.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
#include <set>
#include <string>

using namespace std;

/// 3. 无重复字符的最长子串
int lengthOfLongestSubstring(string s) {
    set<char> hash;
    int j = -1;
    int ans = 0;
    for (int i = 0; i < s.length(); ++ i) {
        if (i != 0) {
            hash.erase(s[i - 1]);
        }
        while (j + 1 < s.length() && hash.count(s[j + 1]) == 0) {
            hash.insert(s[j + 1]);
            ++ j;
        }
        ans = max(ans, j - i + 1);
    }
    return ans;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "abcabcd";
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}
