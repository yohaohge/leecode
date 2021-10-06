/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        vector<int> nums;
        unordered_set<int> visited;
        queue<int> q;
        for(int i = 1; i * i <= n; ++i)
        {
            nums.push_back(i*i);
            q.push(i*i);
            visited.insert(i*i);

        }

        int ans = 0;
        while(q.size())
        {
            int len = q.size();
            while(len --)
            {
                int front = q.front();
                q.pop();
                if(front == n)
                {
                    return ans + 1;
                }

                for(auto num:nums)
                {
                    if(visited.find(front + num) == visited.end())
                    {
                        q.push(front +  num);
                        visited.insert(front + num);
                    }
                }
            }
            ans ++;
        }
    
        return 0;
    }
};
// @lc code=end

