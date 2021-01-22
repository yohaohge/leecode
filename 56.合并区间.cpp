/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            int left = max(res.back()[0], intervals[i][0]);
            int right = min(res.back()[1],  intervals[i][1]);
            if(left <= right) res.back()[1]=max(res.back()[1],  intervals[i][1]);
            else res.push_back(intervals[i]);
        }
        return res;
    }
};
// @lc code=end

