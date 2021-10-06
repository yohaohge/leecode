/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> vec;
        string cur;
        for(int i = 0; i < path.length(); ++i)
        {
            if(path[i] == '/')
            {
                if(cur == "..")
                {
                    if(vec.size() > 0) vec.pop_back();
                }
                else if(cur.length() > 0 && cur != ".")
                {
                    vec.push_back(cur);
                }

                cur = "";
            }
            else {
                cur += path[i];
            }
        }

        if(cur == "..")
        {
            if(vec.size() > 0) vec.pop_back();
        }
        else if(cur.length() > 0 && cur != ".")
        {
            vec.push_back(cur);
        }

        string res;
        for(int i = 0; i < vec.size(); ++i)
        {
            res += "/";
            res += vec[i];
        }
        if(res == "") res = "/";
        return res;
    }
};
// @lc code=end

