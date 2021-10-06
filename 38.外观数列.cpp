/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string nextstr(string s)
    {
        string res;
        if(s == "")
            return s;
        int cnt = 1;
        int ch = s[0];
        for(int i = 1; i < s.length(); ++i)
        {
            if(s[i] == ch)
                cnt++;
            else
            {
                res = res + to_string(cnt);
                res += ch;
                cnt = 1;
                ch = s[i];
            }
        }
        if(cnt > 0)
        {
            res = res + to_string(cnt);
            res += ch;
        }
        return res;
    }

    string countAndSay(int n) {
        string s = "1";
        n--;
        while(n--)
        {
            s = nextstr(s);
        }

        return s;
    }
};
// @lc code=end

