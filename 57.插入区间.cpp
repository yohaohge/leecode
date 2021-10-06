/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;

        bool hasInsert = 0;
        for(int i = 0; i < intervals.size(); ++i)
        {
            if(hasInsert || intervals[i][1] < newInterval[0])
            {
                res.push_back(intervals[i]);
            }
            else if(intervals[i][0] > newInterval[1])
            {
                res.push_back(newInterval);
                res.push_back(intervals[i]);
                hasInsert = 1;
            }
            else
            {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }

        // coner case
        if(hasInsert == 0)
            res.push_back(newInterval);

        return res;
    }
};
// @lc code=end

