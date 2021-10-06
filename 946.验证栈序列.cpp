/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;

        int j = 0;
        for(int i = 0; i < pushed.size(); ++i)
        {
            while(st.size() != 0 && st.top() == popped[j])
            {
                j++;
                st.pop();
            }

            st.push(pushed[i]);
        }  

        while(st.size() != 0 && st.top() == popped[j])
        {
            j++;
            st.pop();
        }

        return st.empty();
    }
};
// @lc code=end

