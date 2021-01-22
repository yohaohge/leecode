/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        // int res = 0;
        // for(int i = 0; i < n; i++)
        // {
        //     int left = i; int right =i;
        //     while(left-1 >= 0 && heights[left-1] >= heights[i])
        //     {
        //         left--;
        //     }

        //     while(right+1 <= n-1 && heights[right+1] >= heights[i])
        //     {
        //         right++;
        //     }

        //     res = max(res, (right-left+1)*heights[i]);
        // }


        int n = heights.size();
        vector<int> leftIndex(n, -1);
        vector<int> rightIndex(n,n);

        stack<int> s;
        for(int i = 0; i < n; ++i)
        {
            while(!s.empty() && heights[s.top()] >= heights[i])
            {
                rightIndex[s.top()] = i;
                s.pop();
            }

            // if(s.empty()) 
            // {
            //     leftIndex[i] = -1;
            // }
            // else leftIndex[i] = s.top();
            leftIndex[i]  = s.empty() ?-1 :  s.top();
            s.push(i);

        }
        
        // s.clear();
        // for(int i = n -1; i >=0 ; i--)
        // {
        //     while(!s.empty() && heights[s.top()] >= heights[i])
        //     {
        //         s.pop();
        //     }

        //     if(s.empty()) 
        //     {
        //         rightIndex[i] = n;
        //     }
        //     else rightIndex[i] = s.top();
            
        //     s.push(i);

        // }

        int ans = 0;
        for(int i = 0; i <  n; ++i)
        {
            ans = max(ans, heights[i] * (rightIndex[i] - leftIndex[i] -1));
        }

        return ans;
    }
};
// @lc code=end

