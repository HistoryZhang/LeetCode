//
//  main.cpp
//  LC5
//
//  Created by admin on 2020/10/6.
//  Copyright © 2020 tsing. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

/// 5. 最长回文子串
string longestPalindrome(string s) {
    if (s.length() == 0) {
        return "";
    }
    string res;
    for (int i = 0; i < s.length(); ++ i) {
        int left = i - 1;
        int right = i + 1;
        while (left >= 0 && s[left] == s[i]) {
            -- left;
        }
        while (right < s.length() && s[right] == s[i]) {
            ++ right;
        }
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            -- left;
            ++ right;
        }
        int length = right - left - 1;
        if (res.length() < length) {
            res = s.substr(left + 1, length);
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout<<longestPalindrome("abccb")<<endl;
    return 0;
}
