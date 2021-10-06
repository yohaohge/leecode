/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // if(nums1.size() > num2.size())
        //     return intersection(num2, num1);

        unordered_set<int> set;
        unordered_set<int> res;

        for(auto e: nums1)
            set.insert(e);
        
        for(auto e: nums2)
            if(set.find(e) != set.end())
                res.insert(e);
        vector<int> ans;
        for(auto e:res)
            ans.push_back(e);
        return ans;
    }
};
// @lc code=end

