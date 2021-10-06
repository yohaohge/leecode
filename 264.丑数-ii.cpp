/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>> q;
        q.push(1);

        for(int i = 0; i < n - 1; i++) 
        {
            long top = q.top();
            q.pop();
            q.push(top * 2);
            q.push(top * 3);
            q.push(top * 5);
            while(top == q.top())
                q.pop();
        }

        return q.top();
    }
};
// @lc code=end

