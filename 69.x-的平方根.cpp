/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x > 1 ? x/2 : 1;

        while(left <= right)
        {
            long mid = left + (right - left)/2;
            
            if(mid * mid < x)
                left = mid + 1;
            else if(mid * mid > x)
                right = mid - 1;
            else
                return mid;
        }

        return right;
    }
};
// @lc code=end

