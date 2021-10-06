/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, right = 0;

        unordered_map<char, int> cntMap;
        // 记录所有字符的个数
        // 找到最多的字符个数
        // 剩下的做替换

        int ans = 0;    
        int maxnum = 0;

        while(right < s.length())
        {
            cntMap[s[right]]++;
            
            maxnum = max(maxnum, cntMap[s[right]]);
            if(right + 1 - left - maxnum <= k)
                ans = max(ans, right - left + 1);
            else
                cntMap[s[left++]]--;
            right++;
        }

        return ans;
    }
};
// @lc code=end

