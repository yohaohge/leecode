/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:

    unordered_set< string > set;
    vector<vector<int>>  res;
    void dfs(vector<int>& candidates, int target, int sum, vector<int>& current,int index)
    {
        if(sum > target) return;
        //base case
        if(sum == target)
        {
            //to string
            auto tmp = current;
            sort(tmp.begin(), tmp.end());
            string str;
            for(auto e:tmp)
                str += to_string(e) + ",";
            if(set.find(str) == set.end())
            {
                res.push_back(tmp);
                set.insert(str);
            }
        }
        if(index >= candidates.size()) return;

        dfs(candidates, target, sum,current, index+1);
        current.push_back(candidates[index]);
        dfs(candidates, target, sum+candidates[index],current,index+1);
        current.pop_back();
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int sum=accumulate(candidates.begin(),candidates.end(),0); 
        if(sum < target) return res;
        vector<int> current;
        dfs(candidates, target, 0,current, 0);
        return res;
    }
};
// @lc code=end

