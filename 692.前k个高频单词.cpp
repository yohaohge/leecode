/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start


class Solution {
public:
    class cmp
    {
    public:
        bool operator()(const pair<int, string>& a, const pair<int, string>& b)
        {
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> q;
        
        unordered_map<string, int> map;
        for(auto str:words)
            map[str]++;
        for(auto date:map)
        {
            if(q.size() < k)
            {
                q.push(pair<int, string>(date.second, date.first));
            }
            else if(date.second > q.top().first || (date.second == q.top().first && date.first < q.top().second))
            {
                q.pop();
                q.push(pair<int, string>(date.second, date.first));
            }
        }  

        vector<string> res;
        while(q.size())
        {
            res.push_back(q.top().second);
            q.pop();
        } 
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

