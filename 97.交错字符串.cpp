/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, bool> map;
    bool dfs(string s1, string s2, string s3)
    {
        string key = s1 + "#" + s2 + "" + s3;
        if(map.find(key) != map.end())
            return map[key];
        if(s1.length() + s2.length() != s3.length())
            return false;
        if(s1 == "") return s2 == s3;
        if(s2 == "") return s1 == s3;

        if(s1[0] == s3[0] && dfs(s1.substr(1), s2, s3.substr(1)) ) return true;
        if(s2[0] == s3[0] && dfs(s1, s2.substr(1), s3.substr(1)) ) return true;
        map[key] = false;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() + s2.length() != s3.length())
            return false;

        return dfs(s1, s2, s3);
    }
};
// @lc code=end

