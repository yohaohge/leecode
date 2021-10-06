/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> out(numCourses);

        for(auto item:prerequisites)
        {
            out[item[1]].push_back(item[0]);
            indegree[item[0]] ++ ;
        }


        vector<int> ans;
        queue<int> q;
        for(int i = 0; i < indegree.size(); ++i)
        {
             if(indegree[i] == 0)
             {
                q.push(i);
                indegree[i] = -1;
             }
        }
        // dfs
        while(q.size())
        {   
            int i = q.front();
            ans.push_back(i);
            indegree[i] = -1;
            for(auto item:out[i])
            {
                indegree[item] --;
                if(indegree[item] == 0)
                {
                     q.push(item);
                     indegree[item] = -1;
                }
            }
            q.pop();
        }

        if(ans.size() == numCourses) return ans;

        return {};
    }   
};
// @lc code=end

