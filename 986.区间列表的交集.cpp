/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int iIndexA = 0; int iIndexB = 0;
        vector<vector<int>> res;

        //左边最大的和右边最小的是交集
        //右边小的要移动        
        while(iIndexA < A.size() && iIndexB < B.size())
        {
            int left = max(A[iIndexA][0],  B[iIndexB][0]);
            int right = min(A[iIndexA][1],  B[iIndexB][1]);
            if(left <= right) res.push_back({left, right});
            if(right == A[iIndexA][1]) iIndexA++;
            else iIndexB++;
            
        }
        
        return res;

    }
};
// @lc code=end

