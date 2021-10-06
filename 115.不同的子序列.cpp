/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 */

// @lc code=start
class Solution {
public:

    unordered_map<string, int> map;
    int cal(string s, string t)
    {
        string key = s + "#" + t;
        if(map.find(key) != map.end())
            return map[key];
        if(s.length() < t.length())
            return 0;
        if(s.length() == 0)
            return 1;

        int iNum = 0;
        if(s[0] == t[0])
            iNum += cal(s.substr(1), t.substr(1));
        iNum += cal(s.substr(1), t);
        map[key] = iNum;
        return iNum;
    }
    int numDistinct(string s, string t) {
        return cal(s, t);
    }   
};
// @lc code=end

