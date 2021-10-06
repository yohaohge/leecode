/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 */

// @lc code=start
class Solution {
public:
    bool isPureNumber(string s)
    {
        if(s.length() == 0)
            return false;

        for(int i = 0; i < s.length(); ++i)
        {
            if(!isdigit(s[i]))
                return false;
        }

        return true;
    }
    bool isInt(string s)
    {
        if(s.length() == 0)
            return false;
        if(s[0] == '+' || s[0] == '-')
            return isPureNumber(s.substr(1));
        return isPureNumber(s);
    }
    bool isNumber(string s) {
        if(s.length() == 0)
            return false;
        bool isPoint = false;
        bool hasE = false;
        bool isNumber = false;
        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == '+' || s[i] == '-')
            {
                if(i != 0 || i == s.length() - 1)
                    return false;
            }
            else if(s[i] == 'e' || s[i] == 'E')
            {
                if(isNumber == false ||  hasE || i == s.length() - 1 || i == 0)
                    return false;
                return isInt(s.substr(i+1));
            }
            else if(s[i] == '.')
            {
                if(isPoint || hasE || s.length() == 1 ||(isNumber == false && i == s.length() - 1))
                    return false;
                isPoint = true;
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                isNumber = true;
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

