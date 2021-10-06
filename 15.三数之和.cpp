/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
// hash table
// time: O(N)
// space: O(N*N + N)


// double point
// time: O(1)
// space: O(N*N)
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        // for(int i = 0; i < nums.size(); i++)
        // {
        //     numMap[nums[i]]++;
        // }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
                break;
            
            // for(int j = nums.size() - 1; j > i+1; j--)
            // {
            //     int target = 0 -(nums[i] + nums[j]);
            //     if(target < nums[i] || target > nums[j])
            //     {
            //         continue;
            //     }

            //     if(target == nums[i] && numMap[target] > 1)
            //     {
            //         res.push_back({nums[i], target, nums[j]});
            //     }
            //     else if(target == nums[j] && numMap[target] > 1)
            //     {
            //         res.push_back({nums[i], target, nums[j]});
            //     }
            //     else if(target > nums[i] && target < nums[j] && numMap[target] > 0)
            //     {
            //         res.push_back({nums[i], target, nums[j]});
            //     }

            //     while(j > 0 && nums[j] == nums[j-1])
            //     {
            //         j--;
            //     }
            // }

            int j = i + 1, k = nums.size() - 1;

            while(j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum < 0)
                    j++;
                else if(sum > 0)
                    k--;
                else if(sum == 0)
                {
                    res.push_back({nums[i], nums[j], nums[k]});

                    // 避免重复，不会出现错漏的case
                    // 因为num[i] num[j]中的两个确定后，第三个值是确认的
                    while(j < k&& nums[j] == nums[j+1])
                        j++;
                    while(k > j && nums[k] == nums[k-1])
                        k--;
                    j++; 
                    k--;
                }
              
            }
            while(i < nums.size() -1 &&  nums[i] == nums[i+1])
            {
                i++;
            }
        }

        return res;
    }
};
// @lc code=end

