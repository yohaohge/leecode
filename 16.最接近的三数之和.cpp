/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());
        
        int res = 0;
        // case for base
        if(nums.size() >= 3)
            res = nums[0] + nums[1] + nums[2];

        int i = 0;
        for(int i = 0; i < nums.size() - 2; i++)
        {
            int j = i + 1, k = nums.size() - 1;

            while(j < k)
            {
                // cout <<  i << " " << j << " " << k << endl;
                int sum = nums[i] + nums[j] + nums[k];
                res = abs(target-res) < abs(target-sum) ? res : sum;

                if(sum < target)
                {
                    j++;
                }
                else if(sum > target)
                {
                    k--;
                }
                // 加速：找到直接返回
                else
                {
                    return target;
                }

                // 错误，导致错过num[j] == num[k] 的case
                // while(j < k && nums[j] == nums[j+1])
                //     j++;
                // while(j < k && nums[k] == nums[k-1])
                //     k--;
            }
        }

        return res;
    }
};
// @lc code=end

