/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:

    struct Node {
        int val;
        int index;
        Node(int x, int idx) : val(x), index(idx) {}
    };

    struct cmp1{
	    bool  operator ()  (Node  a , Node  b  ){
	   	      return a.val < b.val;
	   } 
    }; 
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 最大队列
        // deque<int> q;

        // vector<int> res;
        // for(int i = 0; i < nums.size(); i++)
        // {
        //     // 
        //     while(!q.empty() && nums[q.back()] < nums[i])
        //         q.pop_back();
        //     q.push_back(i);

        //     while(q.front() <= i - k)
        //         q.pop_front();
            
        //     if(i >= k-1)
        //         res.push_back(nums[q.front()]);
        // }

        // return res;

        priority_queue<Node, vector<Node>, cmp1> q;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            q.push(Node(nums[i], i));

            if(i >= k - 1)
            {
                while(q.top().index <= i - k)
                {
                    q.pop();
                }

                res.push_back(q.top().val);
            }
        } 
        
        return res;
    }
};
// @lc code=end

