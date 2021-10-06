/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        cout << s << "--" << p << endl;
        if(p == "")
            return s == "";
        else if(s == "")
            return p[0] == '*' ? isMatch(s, p.substr(1)) : false;
        else if(p[0] == '?' || s[0] == p[0])
        {
            return  isMatch(s.substr(1), p.substr(1));
        }
        else if(p[0] == '*')
        {
            bool result = isMatch(s, p.substr(1))||
                        isMatch(s.substr(1), p)||
                        isMatch(s.substr(1), p.substr(1));
            return result;
        }

        return false;
    }
};
// @lc code=end

