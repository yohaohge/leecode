/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cntMap;
        for(auto e:nums)
            cntMap[e]++;
        
        priority_queue<pair<int, int>> q;
        for(auto e: cntMap)
            q.push(pair<int, int>(e.second, e.first));

        vector<int> res;
        while(k--)
        {
            res.push_back(q.top().second);
            q.pop();
        }

        return res;

    }
};
// @lc code=end

