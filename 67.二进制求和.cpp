/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(begin(a), end(a));
        reverse(begin(b), end(b));

        string ans;
        int sum = 0;
        int i = 0;
        while(i < a.length() || i < b.length())
        {
            if(i < a.length())
                sum += a[i] - '0';
            if(i < b.length())
                sum += b[i] - '0';
            ans = ans + to_string(sum%2);
            sum /=2;
            i++;
        }
        
        if(sum > 0)
            ans = ans + to_string(sum%2);
        
        reverse(begin(ans), end(ans));

        return ans;
    }
};
// @lc code=end

