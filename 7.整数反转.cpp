/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        string str = to_string(x);
        ::reverse(str.begin(), str.end());
        return stoi(str);

    }
};
// @lc code=end

