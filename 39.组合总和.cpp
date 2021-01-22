/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    unordered_set< string > set;
    vector<vector<int>>  res;
    void dfs(vector<int>& candidates, int target, int sum, vector<int> current)
    {
        if(sum > target) return;
        //base case
        if(sum == target)
        {
            sort(current.begin(), current.end());
            //to string
            string str;
            for(auto e:current)
                str += to_string(e) + ",";
            if(set.find(str) == set.end())
            {
                res.push_back(current);
                set.insert(str);
            }
        }

        for(auto num:candidates)
        {
            current.push_back(num);
            dfs(candidates, target, sum+num,current);
            current.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        dfs(candidates, target, 0,current);
        return res;
    }
};
// @lc code=end

