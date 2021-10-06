/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        int ans = INT_MAX;

        while(right < nums.size())
        {
            sum += nums[right++];
            if(sum >= target)
            {
                while(sum - nums[left] >= target)
                    sum -= nums[left++];
                if(right - left < ans)
                    ans = right - left;
                
                sum -= nums[left++]; 
            }
        }

        if(ans == INT_MAX) 
            return 0;
        return ans;
    }
};
// @lc code=end

