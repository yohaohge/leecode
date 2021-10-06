/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 */

// @lc code=start
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> set;

        vector<double> res;
        for(int i = 0; i < nums.size(); i++)
        {
            set.insert(nums[i]);
            if(i >= k)
            {
                auto it = set.find(nums[i-k]);
                set.erase(it);
           
            }

            if(i >= k - 1)
            {
                int j = 0;
                long num1 = 0;
                long num2 = 0;
                for(auto e: set)
                {
                    if(j == k/2)
                        num1 = e;
                    if(j == (k-1)/2)
                        num2 = e;
                    j++;
                    if(j > (k+1)/2)
                        break;
                }
                res.push_back((num1+num2)/2.0);
            }
        }

        return res;
    }
};
// @lc code=end

