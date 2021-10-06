/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        if(strs.size() == 1)
            return strs[0];

        string res;

        for(int i = 0; i < strs[0].length(); i++)
        {
            char ch = strs[0][i];
            for(int j = 1; j < strs.size(); j++)
            {
                if(strs[j].size() <= i || strs[j][i] != ch)
                    return res;
            }

            res = res + ch;
        }

        return res;
    }
};
// @lc code=end

