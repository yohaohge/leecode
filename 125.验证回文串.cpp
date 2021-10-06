/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
// 2021 06 01 5min

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while(left < right)
        {
            if(!(isdigit(s[left]) || isalpha(s[left])))
                left++;
            else if(!(isdigit(s[right]) || isalpha(s[right])))
                right--;
            else if(toupper(s[left]) != toupper(s[right]))
                return false;
            else
            {
                left++; right--;
            }
        }

        return true;
    }
};
// @lc code=end

