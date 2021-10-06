/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while(x)
        {
            result *= 10;
            result += x%10;

            x = x/10;
        }

        if(result > INT_MAX ||result < INT_MIN) 
            return 0;
        return result;

    }
};
// @lc code=end

