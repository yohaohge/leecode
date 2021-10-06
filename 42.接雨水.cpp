/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {

        // 当前垂直位置能接雨水的量由左边最高挡板，右边最高挡板和当前位置高度决定
        // vector<int> backHeight(height.size(), 0);
        // vector<int> frontHeight(height.size(), 0);

        // stack<int> mystatk;
        // int maxHeight = 0;
        // for(int i = height.size() - 1; i >= 0; i--)
        // {
        //     backHeight[i] = maxHeight;
        //     maxHeight = max(maxHeight, height[i]);
        // }

        // maxHeight = 0;
        // for(int i = 0; i < height.size(); i++)
        // {
        //     frontHeight[i] = maxHeight;
        //     maxHeight = max(maxHeight, height[i]);
        // }
        // int ans = 0;
        // for(int i = 0; i < height.size(); i++)
        // {
        //     int minHight = min(frontHeight[i], backHeight[i]);
        //     if(minHight > height[i])
        //     {
        //         ans += minHight - height[i];
        //     }
        // }
        // return ans;

        int ans = 0;
        int left = 0; 
        int right = height.size() -1;

        int level = 0, lower = 0;

        while(left < right)
        {
            if(height[left] < height[right])
            {
                lower = height[left++];
            }
            else
            {
                lower = height[right--];
            }

            level = max(level, lower);
            if(level > lower)
                ans += level - lower;
        }
        
        return ans;
    }
};
// @lc code=end

