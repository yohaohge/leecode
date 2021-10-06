/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
class Solution {
public:
    int superEggDrop(int K, int N) {
        if(N == 0||N==1) return N;
        if(K==1) return N;

        vector<vector<long>> dp(K+1, vector<long>(N+1, INT_MAX));

        for(int i=0;i<=K;i++)
            dp[i][0]=0,dp[i][1]=1;   //Filling from base case as if N==0 ans=0 , N==1 ans=1
        for(int i=0;i<=N;i++)
            dp[0][i]=0,dp[1][i]=i;  

        for(int j = 2; j <= K; j++)
        {
            for(int i = 2; i <= N; i++)
            {

                int left = 1, right = i;
                while(left <= right)
                {
                    int mid = left + (right -left)/2;

                    if(dp[j][i-mid] < dp[j-1][mid-1])
                    {
                        right = mid -1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                    int choice = max(dp[j][i-mid]+1, dp[j-1][mid-1]+1);
                    dp[j][i] = min(choice, dp[j][i]);       
                }
            }
        }
        return dp[K][N];


    //     if(N==0||N==1) return N;     //Think for base case
    //     if(K==1) return N;
        
    //   vector<vector<int>> dp(K+1,vector<int> (N+1,0));
    //   for(int i=0;i<=K;i++)
    //     dp[i][0]=0,dp[i][1]=1;   //Filling from base case as if N==0 ans=0 , N==1 ans=1
    //   for(int i=0;i<=N;i++)
    //     dp[0][i]=0,dp[1][i]=i;   //Filling from base case as if K==0 ans=0 , K==1 ans=N, number of current floor (i)
        
    //     for(int i=2;i<K+1;i++)
    //     {
    //         for(int j=2;j<N+1;j++)
    //         {    int l=1,h=j,temp=0,ans=100000;
    //              while(l<=h)
    //              {
    //                 int mid=(l+h)/2;
    //                 int left= dp[i-1][mid-1]; //egg broken check for down floors of mid
    //                 int right= dp[i][j-mid];  // not broken check for up floors of mid
    //                 temp=1+max(left,right);          //store max of both 
    //                 if(left<right){                  //since right is more than left and we need more in worst case 
    //                   l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
    //                 }
    //                 else                             //left > right so we will go downward 
    //                 {    
    //                     h=mid-1;
    //                 }
    //                 ans=min(ans,temp);               //store minimum attempts
    //              }
    //              dp[i][j]=ans;
    //         }
    //     }
    //     return dp[K][N];
        //return dp[K][N];
    }
};
// @lc code=end

