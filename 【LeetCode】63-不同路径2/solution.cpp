class Solution {
/*
初始化dp数组的大小为 (m+1) x (n+1)，是为了handle边缘情况，当i或j为0时，减1可能会出错。当某个位置是障碍物时，其dp值不为0，我们直接跳过该位置即可。我们还需
要初始化dp数组的某个值，使得其能正常累加。当起点不是障碍物时，其dp值应该为值，即dp[1][1] = 1，由于其是由 dp[0][1] + dp[1][0] 更新而来，所以二者中任意
一个初始化为1即可(dp[0][1])
*/
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.empty()||obstacleGrid[0].empty()||obstacleGrid[0][0]==1)return 0;
        int m=obstacleGrid.size();int n=obstacleGrid[0].size();
        vector<vector<long>> dp(m+1,vector<long>(n+1,0));
        dp[0][1]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(obstacleGrid[i-1][j-1]!=0)continue;
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};
