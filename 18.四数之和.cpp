/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                int k = j + 1, m = nums.size() - 1;
                while(k < m)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[m];
                    if(sum < target)
                        k++;
                    else if(sum > target)
                        m--;
                    else
                    {
                        res.push_back({nums[i],nums[j], nums[k], nums[m]});

                        while(k < m && nums[k] == nums[k+1])
                            k++;
                        while(k < m && nums[m] == nums[m-1])
                            m--;
                        k++;
                        m--;
                    }
                }

                while(j < nums.size() - 2 && nums[j] == nums[j+1])
                    j++;
            }
            while(i < nums.size() - 1 && nums[i] == nums[i+1])
                i++;
        }

        return res;
    }
};
// @lc code=end
