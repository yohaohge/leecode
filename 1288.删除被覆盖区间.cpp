/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 */

// @lc code=start

class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int num = 0;
        // 排序后的隐藏条件是当前处理的左边值一定被覆盖到了
        int right = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++)
        {
            if(right < intervals[i][1])
            {
                right = intervals[i][1];
                continue;
            }
            if(right >= intervals[i][1])
            {
                num++;
                continue;
            }
          
        }
        return intervals.size() - num;
    }
};
// @lc code=end

