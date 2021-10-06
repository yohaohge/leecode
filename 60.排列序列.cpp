/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 排列序列
 */

// @lc code=start
class Solution {
public:
    string get_next(string str)
    {
        int len = str.length();

        int indexEnd = len - 1;
        int indexStart = len - 1;

        while(indexStart > 0 && str[indexStart - 1] > str[indexStart])
            indexStart--;

        int indexMid = len - 1;
        while(indexMid < len && str[indexMid] < str[indexStart - 1]) 
            indexMid--;

        swap(str[indexStart-1], str[indexMid]);

        
        indexEnd = len -1;
        while(indexStart < indexEnd)
            swap(str[indexStart++], str[indexEnd--]);
        
        return str;
    }

    string getPermutation(int n, int k) {
        string str;
        for(int i = 1; i <= n ; i++)
        {
            str += to_string(i);
        }
        k--;
        while(k--)
            str = get_next(str);

        return str;
    }
};
// @lc code=end

