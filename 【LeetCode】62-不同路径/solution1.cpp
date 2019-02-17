class Solution {
/*
思路：利用动态规划，用动态规划Dynamic Programming来解，我们可以维护一个二维数组dp，其中dp[i][j]表示到
当前位置不同的走法的个数，然后可以得到递推式为: dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，这里为了节省空间，我们使用一维数组dp，一行一行的刷新也可以，
*/
public:
    int uniquePaths(int m, int n) {
       vector<int> path(n,1);
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                path[j]+=path[j-1];
            }
        }
        return path[n-1];
    }
};
