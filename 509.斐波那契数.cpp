/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;

        int num1 = 0, num2 = 1;
        n = n - 1;
        while(n--)
        {
            num2 = num1 + num2;
            num1 = num2 - num1;
        }

        return num2;
    }
};
// @lc code=end

