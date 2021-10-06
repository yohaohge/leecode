/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> map;
        map[')'] = '(';
        map['}'] = '{';
        map[']'] = '[';
        for(auto ch:s)
        {
            if(map.find(ch) == map.end())
                st.push(ch);
            else 
            {
                if(st.size() > 0 && st.top() == map[ch])
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        return st.size() == 0;
    }
};
// @lc code=end

