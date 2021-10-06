/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;

        for(int i = s.length() - 1; i >= 0; i--)
        {
            if(s[i] == ' ' && ans == 0)
                continue;
            if(s[i] == ' ' && ans > 0)
                return ans;
            ans++;
        }
        return ans;
    }
};
// @lc code=end

