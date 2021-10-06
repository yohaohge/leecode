/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.length() == 0)
            return 0;
        if(haystack.length() == 0)
            return -1;
        if(haystack.length() < needle.size())
            return -1;

        int m = haystack.size(), n = needle.size();
        
        vector<int> lps(n, 0);
      
        // KMP算法

        for(int i = 1, len = 0; i < n;)
        {
            // 这个条件表示，长度后面的一个值和对齐index比较
            if(needle[i] == needle[len])
            {
                lps[i++] = ++len;
            }
            else if(len) {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }

        for(int i = 0, j = 0; i < m;)
        {
            if(haystack[i] == needle[j])
            {
                i++; j++;
            }
            else
                j ? j = lps[j - 1] : i++;

            if(j == n)
            {
                return i - n;
            } 
        }

        return -1;
    }
};
// @lc code=end

