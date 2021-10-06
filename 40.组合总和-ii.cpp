/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution {
public:

    // unordered_set< string > set;
    // vector<vector<int>>  res;
    // void dfs(vector<int>& candidates, int target, int sum, vector<int>& current,int index)
    // {
    //     if(sum > target) return;
    //     //base case
    //     if(sum == target)
    //     {
    //         //to string
    //         auto tmp = current;
    //         sort(tmp.begin(), tmp.end());
    //         string str;
    //         for(auto e:tmp)
    //             str += to_string(e) + ",";
    //         if(set.find(str) == set.end())
    //         {
    //             res.push_back(tmp);
    //             set.insert(str);
    //         }
    //     }
    //     if(index >= candidates.size()) return;

    //     dfs(candidates, target, sum,current, index+1);
    //     current.push_back(candidates[index]);
    //     dfs(candidates, target, sum+candidates[index],current,index+1);
    //     current.pop_back();
    // }

    unordered_set<string> set;

    void dfs(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& cur, int index, int sum, string curstr)
    {
        if(sum == target && set.find(curstr) == set.end())
        {
            res.push_back(cur);
            set.insert(curstr);
        }

        if(index >= candidates.size() || sum >= target)
            return;
        cur.push_back(candidates[index]);
        dfs(res, candidates, target, cur, index + 1, sum + candidates[index], curstr +"#"+to_string(candidates[index]));
        cur.pop_back();
        dfs(res, candidates, target, cur, index + 1, sum,  curstr);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // int sum=accumulate(candidates.begin(),candidates.end(),0); 
        // if(sum < target) return res;
        // vector<int> current;
        // dfs(candidates, target, 0,current, 0);
        // return res;

        vector<vector<int>> res;

        int sumtotal = accumulate(candidates.begin(), candidates.end(), 0);
        if(sumtotal < target)
            return res;
        sort(candidates.begin(), candidates.end());
            
        vector<int> cur;

        dfs(res, candidates, target, cur, 0, 0, "");

        return res;
    }
};
// @lc code=end

