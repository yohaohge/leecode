/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        if(s.length() == 0)
            return 0;
        int nums[] = {900,  400,  90, 40, 9, 4, 1000, 500, 100, 50,  10, 5, 1};
        string roman[] = {"CM","CD", "XC","XL", "IX", "IV", "M", "D",  "C", "L",  "X", "V", "I"};
        for(int i = 0; i < 13; i++)
        {
            string str = roman[i];
            if(s.length() >= str.length() && str == s.substr(0, str.length()))
                return nums[i] + romanToInt(s.substr(str.length()));
        }

        return 0;
    }
};
// @lc code=end

