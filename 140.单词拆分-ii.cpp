/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<string>& res, string& s, unordered_set<string>& wordSet, int index, string cur, string curspilt)
    {
        if(index >= s.length())
        {
            if(wordSet.find(curspilt) != wordSet.end())
            {
                if(cur.length() == 0)
                    cur = curspilt;
                else
                    cur = cur + " " + curspilt;
                res.push_back(cur);
            }
            return;
        }

        dfs(res, s, wordSet, index + 1, cur, curspilt + s[index]);
        if(wordSet.find(curspilt) != wordSet.end())
        {
            if(cur.length() == 0)
                cur = curspilt;
            else
                cur = cur + " " + curspilt;
            curspilt = ""; curspilt = curspilt + s[index];

            dfs(res, s, wordSet, index + 1, cur, curspilt);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;

        unordered_set<string> set;
        for(auto word:wordDict)
            set.insert(word);
        
        dfs(res, s, set, 0, "", "");
        return res;
    }
};
// @lc code=end

