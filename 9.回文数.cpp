/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindromeStr(string str)
    {
        int len = str.length();
        for(int i = 0; i < len/2; ++i)
        {
            if(str[i] != str[len - 1 - i])
                return false;
        }

        return true;
    }
    bool isPalindrome(int x) {
        if(x < 0)
            return false;

        string str = to_string(x);
        return isPalindromeStr(str);
    }
};
// @lc code=end

