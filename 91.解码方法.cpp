/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, int> map;
    int dfs(string s)
    {
        if(map.find(s) != map.end())
            return map[s];
        if(s.length() == 0)
            return 1;
        if(s[0] == '0')
            return 0;
        if(s.length() == 1)
            return 1;
    
        int iNum = dfs(s.substr(1));
        string sub = s.substr(0,2);
        if(atoi(sub.c_str()) >= 10 && atoi(sub.c_str()) <=26)
            iNum += dfs(s.substr(2));
        map[s] = iNum;
        return iNum;
    }
    int numDecodings(string s) {
        return dfs(s);
    }
};
// @lc code=end

