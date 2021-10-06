/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, bool> map;

    bool dfs(string s1, string s2)
    {  
        string key = s1 + "#" + s2;
        if(map.find(key) != map.end())
            return map[key];

        if(s1.length() != s2.length())
        {
            map[key] = false;
            return false;
        }

        if(s1.length() == 1 && s1 == s2)
        {
            map[key] = true;
            return true;
        }

        if(s1.length() == 1 && s1 != s2)
        {
            map[key] = false;
            return false;
        }

        for(int i = 1; i <= s1.length() - 1; i++)
        {
            string s11 = s1.substr(0, i);
            string s12 = s1.substr(i);
            string s21 = s2.substr(0, i);
            string s22 = s2.substr(i);
            if(dfs(s11, s21) && dfs(s12, s22)) 
            {
                map[key] = true;
                return true;
            }
            s22 = s2.substr(0, s2.length() - i);
            s21 = s2.substr(s2.length() - i);
            if(dfs(s11, s21) && dfs(s12, s22)) 
            {
                map[key] = true;
                return true;
            }
        }
        map[key] = false;
        return false;
    }

    bool isScramble(string s1, string s2) {
        return dfs(s1, s2);
    }   
};
// @lc code=end

