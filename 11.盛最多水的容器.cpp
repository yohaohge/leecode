/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int res = 0;
        while(left < right)
        {   
            // 每次都计算
            // res = max(res, (right - left) * min(height[left], height[right]));

            // if(height[left] < height[right])
            // {
            //     left ++;
            // }
            // else
            // {
            //     right --;
            // }

            // 跳过一些情况
            int h = min(height[left], height[right]);
            res = max(res, (right - left) * h);
            while(h >= height[left] && left < right)
                left++;
            while(h >= height[right] && left < right)
                right--;

            
        }
        return res;
    }
};
// @lc code=end

