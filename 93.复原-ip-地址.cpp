/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    void dfs(vector<string>& res, string& s, int index, string cur, string curspilt, int num)
    {
        if(curspilt.length() >= 2 && curspilt[0] == '0')
            return;
        
        if(atoi(curspilt.c_str()) > 255)
            return;

        if(index >= s.length())
        {
            if(num == 3)
            {
                res.push_back(cur);
            }
            return;
        }



        if(num > 3)
            return;
        dfs(res, s, index + 1, cur + s[index], curspilt + s[index], num);
        if(curspilt != "")
            dfs(res, s, index + 1, cur + "." + s[index], string("") + s[index], num + 1);
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.length() > 12)
            return res;
        dfs(res, s, 0, "", "", 0);
        return res;
    }
};
// @lc code=end

