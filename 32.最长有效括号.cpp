/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        
        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                if(st.size() > 0)
                {
                    s[st.top()] = '*';
                    s[i] = '*';
                    st.pop();
                }
            }
        }
        int res = 0;
        int cnt = 0;
        for(int i = 0; i < s.length(); ++i)
        {
            if(s[i] == '*')
                res = max(res, ++cnt);
            else
                cnt = 0;
        }
        // coner case
        res = max(res, cnt);

        return res;
    }
};
// @lc code=end

