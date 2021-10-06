/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(n == INT_MIN)
            return 1.0 / myPow(x, INT_MAX) / x;
            
        if(n < 0)
            return 1.0 / myPow(x, 0 - n);

        double res = 1;
        while(n > 0)
        {
            if(n & 1)
                res = res * x;
            n = n >> 1;
            x = x * x;
        }

        return res;
    }
};
// @lc code=end

