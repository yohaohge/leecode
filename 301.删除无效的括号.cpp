/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
class Solution {
public:
    unordered_set<string> set;
    void dfs(int i, int left_removed, int right_removed, int leftNum, string& s, string cur)
    {
        if(left_removed < 0 || right_removed < 0 || leftNum < 0)
            return;
        if(s.length() == i)
        {
            if(left_removed == 0 && right_removed == 0 && leftNum == 0)
            {
                set.insert(cur);
            }
            return;
        }

        if(s[i] == '(')
        {
            dfs(i + 1, left_removed, right_removed, leftNum + 1, s, cur + s[i]);
            dfs(i + 1, left_removed - 1, right_removed, leftNum, s, cur);
        }
        else if(s[i] == ')')
        {
            dfs(i + 1, left_removed, right_removed, leftNum - 1, s, cur + s[i]);
            dfs(i + 1, left_removed, right_removed - 1, leftNum, s, cur);
        }
        else
        {
            dfs(i + 1, left_removed, right_removed, leftNum, s, cur + s[i]);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int left_removed = 0;
        int right_removed = 0;        
        for(auto c : s) {
            if(c == '(') {
                ++left_removed;
            }
            if(c == ')') {
                if(left_removed != 0) {
                    --left_removed;
                }
                else {
                    ++right_removed;
                }
            }
        }

        dfs(0, left_removed, right_removed, 0, s,  "");
        vector<string> res(set.begin(), set.end());

        return res;
    }
};
// @lc code=end

