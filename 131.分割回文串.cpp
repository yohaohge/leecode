/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    bool check(string s)
    {
        if(s.length() == 0)
            return false;
        int left = 0, right = s.length() - 1;
        while(left < right)
            if(s[left++] != s[right--])
                return false;
        
        return true;
    }

    void dfs(vector<vector<string>>& res, const string s, int index, vector<string>& cur, string curstr)
    {
        if(index >= s.length() )
        {
            if(check(curstr))
            {
                cur.push_back(curstr);
                res.push_back(cur);
                cur.pop_back();
            }
            return;
        }

        dfs(res, s, index + 1, cur, curstr + s[index]);
        if(check(curstr))
        {
            cur.push_back(curstr);
            dfs(res, s, index + 1, cur, string("") + s[index]);
            cur.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        dfs(res, s,  0, cur, "");
        return res;

    }
};
// @lc code=end

